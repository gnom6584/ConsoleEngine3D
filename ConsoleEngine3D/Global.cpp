#include "pch.h"
#include "Global.h"
Camera camera = Camera(Projections::Perspective, 75, 10.0f, 60.0f);
Canvas canvas = Canvas(camera, 50, 27, ' ');