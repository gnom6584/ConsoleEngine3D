//
//  main.cpp
//  ConsoleEngine3D
//
//  Created by Апсех on 03/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#include <iostream>
#include "SceneManager.hpp"
#include "Drawable.hpp"
#include <unistd.h>
#include <vector>
#include <chrono>
#include <stdio.h>
#include <unistd.h>
#include "Display.hpp"
#include "Camera.hpp"
#include "Enigne.hpp"
#include "Mesh.hpp"
#include "ModelImporter.hpp"
#include "TextureImporter.hpp"

#include <ncurses.h>
#include <fstream>
#define getch() wgetch(stdscr)


struct Behaviour : public Component{
    void onUpdate() override{
        //     getGameObject().getTransform().rotateLocal(0, 0.1f, 0);
        //   Camera::getCurrentCamera().fieldOfView += 0.1f;
        //     Camera::getCurrentCamera().getTransform().rotateLocal(Vector(0, 0, 0.01));
        //     getGameObject().getTransform().rotateLocal(Vector(0, 0.03f, 0));
        char a; // getch();
        switch (a) {
            case 'w':
                getGameObject().getTransform().moveLocal(0,0,1);
                break;
            case 's':
                getGameObject().getTransform().moveLocal(0,0,-1);
                break;
            case 'd':
                getGameObject().getTransform().moveLocal(0,1,0);
                break;
            case 'a':
                getGameObject().getTransform().moveLocal(0,-1,0);
                break;
            case 'q':
                getGameObject().getTransform().rotateLocal(0,1, 0);
                break;
            case 'e':
                getGameObject().getTransform().rotateLocal(0,-1, 0);
                break;
            default:
                break;
        }
    }
};

Color** texture;
struct S : public Shader {
    Vertex vertex(Vertex &vertex) override{
        float d = Vector::dot(vertex.normal.getNormalized(), Vector(0, -1, 0));
        if(d < 0) d = 0;
        if(d > 0.7f) d = 0.7f;
        vertex.color *= d * d + 0.3f;
        vertex.position = Camera::transformWorldToCameraSpace(vertex.position);
        return vertex;
    }
    
    Color fragment(Vertex &vertex) override{
        Color out = vertex.color;
        Color tex = texture[(int)(vertex.uv.x * 127)][(int)((vertex.uv.y) * 127)];
        out = Color::lerp(0.0f, tex, (float)out.red / COLOR_VALUE_MAX);
        return out.clamp();
    }
};

S s;


struct Scene1 : public Scene{
    
    Scene1(){
        auto& g = createGameObject("rightKrilo");
        auto& g1 = createGameObject("leftKrilo");
        auto& ship = createGameObject("ship");
        
        g.getTransform().rotateLocal(-3.1415/2, 0, 0);
        g1.getTransform().rotateLocal(-3.1415/2, 0, 0);
   
        g.getTransform().parent = &ship.getTransform();
        g1.getTransform().parent = &ship.getTransform();
        
        g.getTransform().moveLocal(0, -0.7, 0);
           g1.getTransform().moveLocal(0, -0.7, 0);
           
        
        auto& m = g.addComponent<Mesh>();
        //        mesh.normals = {
        //            Vector(-1.0, -1.0,  1.0),
        //          Vector( 1.0, -1.0,  1.0),
        //          Vector( 1.0,  1.0,  1.0),
        //          Vector(-1.0,  1.0,  1.0),
        //          Vector(-1.0, -1.0, -1.0),
        //          Vector( 1.0, -1.0, -1.0),
        //          Vector( 1.0,  1.0, -1.0),
        //          Vector(-1.0,  1.0, -1.0)
        //        };
        //        mesh.vertices = {
        //               Vector(-1.0, -1.0,  1.0),
        //               Vector( 1.0, -1.0,  1.0),
        //               Vector( 1.0,  1.0,  1.0),
        //               Vector(-1.0,  1.0,  1.0),
        //               Vector(-1.0, -1.0, -1.0),
        //               Vector( 1.0, -1.0, -1.0),
        //               Vector( 1.0,  1.0, -1.0),
        //               Vector(-1.0,  1.0, -1.0)
        //           };
        //           mesh.indices = {
        //               // front
        //               0, 1, 2,
        //               2, 3, 0,
        //               // right
        //               1, 5, 6,
        //               6, 2, 1,
        //               // back
        //               7, 6, 5,
        //               5, 4, 7,
        //               // left
        //               4, 0, 3,
        //               3, 7, 4,
        //               // bottom
        //               4, 5, 1,
        //               1, 0, 4,
        //               // top
        //               3, 2, 6,
        //               6, 7, 3
        //           };
        //                mesh.setShader(&s);
        // g.addComponent<Behaviour>();
        auto& m1 = g1.addComponent<Mesh>();
        ship.addComponent<Behaviour>();
        std::vector<Color> c = {Color()};
        int width = 0;
        int height = 0;
        ModelImporter().open("/Users/apc/Desktop/Clone/ConsoleEngine3D/ConsoleEngine3D/Resources/ShipModel", m.vertices,m.indices, m.uv, m.normals, c);
        texture = TextureImporter().open("/Users/apc/Desktop/Clone/ConsoleEngine3D/ConsoleEngine3D/Resources/ShipTexture", width, height);
        m.setShader(&s);
        m1.setShader(&s);
        m1.vertices = m.vertices;
        m1.indices = m.indices;
        m1.normals = m.normals;
        m1.uv = m.uv;
        g1.getTransform().setLocalScale(Vector(-1, 1, 1));
       // g.getTransform().setLocalScale(Vector(0, 1, 1));
        //  g1.getTransform().moveLocal(2, 0, 0);
    }
};

struct CommonConsoleOutput: public Display{
    
    using Display::Display;
    
    std::string charList = " .-`',:_;~\"/!|\\i^trc*v?s()+lj1=e{[]z}<xo7f>aJy3Iun542b6Lw9k#dghq80VpT$YACSFPUZ%a&DKBR@HQWM";
    
    void onPixelDraw(const Color& color, int x, int y, float depth) const override{
        if(x == 0 && y == 0){
            system("clear");
        }
        
        if(x == 0 && y != 0){
            if(y != 1)std::cout << '|';
            std::cout << std::endl;
            std::cout << '|';
        }
        int index = (color.getLuminosity() * (charList.length() - 1)) / (float)(COLOR_VALUE_MAX);
        std::cout << charList[index] << charList[index];
    }
};

struct Xterm256Console: public Display{
    
    Xterm256Console(int width, int height) : Display(width, height){
        initscr();
        start_color();
        for(unsigned int i = 0; i < 256; i++){
            init_pair(i + 1, i, i);
        }
    }
    
    std::string charList = " .-`',:_;~\"/!|\\i^trc*v?s()+lj1=e{[]z}<xo7f>aJy3Iun542b6Lw9k#dghq80VpT$YACSFPUZ%a&DKBR@HQWM";
    
    void onPixelDraw(const Color& color, int x, int y, float depth) const override{
        if(x == 0 && y == 0){
            //  clear();
        }
        attron(COLOR_PAIR((color.red/43)* 36 + (color.green/43)*6 +(color.blue/43) + 16 + 1));
        move(getHeight() -1 - y, x * 2);
        printw("  ");
        if(x == getWidth() - 1 && y == getHeight() - 1){
            refresh();
        }
    }
};

int main(int argc, const char* argv[]) {
    float szie = 1;
    CommonConsoleOutput d(60 * szie, 20 * szie);
    Camera cam(1);
    cam.getTransform().moveLocal(0, -1, -5);
    Engine e(d, 10.f);
    e.start<Scene1>();
    return 0;
}
