//
//  3DPainter.cpp
//  ConsoleEngine3D
//
//  Created by Апсех on 06/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#include "Painter3D.hpp"
#include "Camera.hpp"
 

Painter3D::Painter3D(Display &display) : display(display) {
    width = display.getWidth();
    height = display.getHeight();
    contourX = new int*[height];
    for(unsigned int i = 0; i < height; i++){
        contourX[i] = new int[2];
    }
    for (unsigned int y = 0; y < height; y++){
        contourX[y][0] =  width;
        contourX[y][1] = 0;
    }
}

Painter3D::~Painter3D() {
    for(unsigned int i = 0; i < height; ++i){
        delete[] contourX[i];
    }
    delete[] contourX;
}


void Painter3D::drawPoint(const Color &color, unsigned int x, unsigned int y, float depth, bool transparent, bool ignoreDepth) {
    if(depth < 0){
        return;
    }
    auto currentDepth = display.depthBuffer[x][y];
    if(transparent){
        if(ignoreDepth || depth < currentDepth || currentDepth < 0){
            display.transparentBuffer[x][y] = color;
        }
    }
    else{
        if(ignoreDepth || depth < currentDepth || currentDepth < 0){
            if(!ignoreDepth){
                display.depthBuffer[x][y] = depth;
            }
            display.opaqueBuffer[x][y] = color;
        }
    }
}


void Painter3D::scanLine(int x1, int y1, int x2, int y2) { 
    int sx, sy, dx1, dy1, dx2, dy2, x, y, m, n, k, cnt;
    
    sx = x2 - x1;
    sy = y2 - y1;
    
    if (sx > 0) {
        dx1 = 1;
    }
    else if(sx < 0) {
        dx1 = -1;
    }
    else {
        dx1 = 0;
    }
    
    if (sy > 0) {
        dy1 = 1;
    }
    else if (sy < 0) {
        dy1 = -1;
    }
    else {
        dy1 = 0;
    }
    
    m = ABS(sx);
    n = ABS(sy);
    dx2 = dx1;
    dy2 = 0;
    
    if (m < n) {
        m = ABS(sy);
        n = ABS(sx);
        dx2 = 0;
        dy2 = dy1;
    }
    
    x = x1; y = y1;
    cnt = m + 1;
    k = n / 2;
    
    while (cnt--) {
        if ((y >= 0) && (y < height)) {
            if (x < contourX[y][0]) contourX[y][0] = CLIP(x, 0, width - 1);
            if (x > contourX[y][1]) contourX[y][1] = CLIP(x, 0, width - 1);
        }
        k += n;
        if (k < m) {
            x += dx2;
            y += dy2;
        }
        else {
            k -= m;
            x += dx1;
            y += dy1;
        }
    }
}

void Painter3D::drawTriangle(Shader& shader, Vertex v0, Vertex v1, Vertex v2){
    int y;
    
    v0 = shader.vertex(v0);
    v1 = shader.vertex(v1);
    v2 = shader.vertex(v2);
    
    if(Vector::dot(Camera::transformWorldToCameraSpace(v0.normal), Vector(0, 0, 1)) < 0){
        if(Vector::dot(Camera::transformWorldToCameraSpace(v1.normal), Vector(0, 0, 1)) < 0){
            if(Vector::dot(Camera::transformWorldToCameraSpace(v2.normal), Vector(0, 0, 1)) < 0){
                return;
            }
        }
    }
    
    Vertex blended;
    blended.normal = (v0.normal + v0.normal + v2.normal) / 3.0f;
    
    float heigthM = height - 1;
    float widthM = width - 1;
    Vector p0 = Vector((v0.position.x /2.0f) * heigthM + 0.5f * widthM, (v0.position.y /2.0f + 0.5f) * heigthM, v0.position.z);
    Vector p1 = Vector((v1.position.x /2.0f) * heigthM + 0.5f * widthM, (v1.position.y /2.0f + 0.5f) * heigthM, v1.position.z);
    Vector p2 = Vector((v2.position.x /2.0f) * heigthM + 0.5f * widthM, (v2.position.y /2.0f + 0.5f) * heigthM, v2.position.z);
    scanLine(p0.x, p0.y, p1.x, p1.y);
    scanLine(p1.x, p1.y, p2.x, p2.y);
    scanLine(p2.x, p2.y, p0.x, p0.y);
    
    for (y = 0; y < height; y++){
        if (contourX[y][1] >= contourX[y][0]){
            int x = contourX[y][0];
            int length = 1 + contourX[y][1] - contourX[y][0];
            contourX[y][0] = width - 1;
            contourX[y][1] = 0;
            while (length--){
                Vector p = Vector(x++, y);
                float divider = ((p1.y - p2.y) * (p0.x - p2.x) + (p2.x  - p1.x)*(p0.y - p2.y));
                float w0 = 0.0f;
                float w1 = 0.0f;
                w0 = ((p1.y - p2.y)*(p.x - p2.x) + (p2.x - p1.x) * (p.y - p2.y)) / divider;
                w1 = ((p2.y - p0.y)*(p.x - p2.x) + (p0.x - p2.x) * (p.y - p2.y)) / divider;
                float w2 = 1.0f - w1 - w0;
                w0 = CLIP(w0, 0.0f, 1.0f);
                w1 = CLIP(w1, 0.0f, 1.0f);
                w2 = CLIP(w2, 0.0f, 1.0f);
                blended.position = p;
                blended.uv = v0.uv * w0 + v1.uv * w1 + v2.uv * w2;
                blended.uv.x = CLIP(blended.uv.x, 0.0f, 1.0f);
                blended.uv.y = CLIP(blended.uv.y, 0.0f, 1.0f);
                blended.color = Color(
                  v0.color.red * w0 + v1.color.red * w1 + v2.color.red * w2,
                  v0.color.green * w0 + v1.color.green * w1 + v2.color.green * w2,
                  v0.color.blue * w0 + v1.color.blue * w1 + v2.color.blue * w2,
                  v0.color.alpha * w0 + v1.color.alpha * w1 + v2.color.alpha * w2
                  );
                  drawPoint(shader.fragment(blended), p.x, p.y, p0.z * w0 + p1.z * w1 + p2.z * w2, shader.isTransparent());
            }
        }
    }
}
