#include <raylib.h>
#include <raymath.h>
#include <random>

typedef struct CubeComponent {
} CubeComponent;

#include "core.h"
#include "default_systems/physics_system.cpp"
#include "default_systems/render_system.cpp"

Core core;

int main() {
    Camera3D camera = {0};
    camera.position = (Vector3){10.0f, 10.0f, 10.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 0.0f, 1.0f};
    camera.fovy = 45.0f;
    camera.position = Vector3Add(Vector3Scale(Vector3Subtract(camera.position, camera.target), 12), camera.position);
    camera.projection = CAMERA_PERSPECTIVE;



    while (!WindowShouldClose()) {

    }


    return 0;
}
