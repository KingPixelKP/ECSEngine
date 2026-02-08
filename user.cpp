#include <raylib.h>
#include <raymath.h>
#include <random>

#include "core.h"
#include "physics_system.cpp"
#include "render_system.cpp"
#include "cube_system.cpp"
#include "components/cube_component.h"

Core core;

Entity make_cube() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis(0.0, 4);
    static std::uniform_real_distribution<float> disd(0.0f, 80.0f);
    Entity cube = core.create_entity();
    auto cu = core.add_component<Cube>(cube);
    cu.value()->height = 1.0f;
    cu.value()->width = 1.0f;
    cu.value()->length = 1.0f;
    auto c = core.add_component<Color>(cube).value();
    switch (dis(gen)) {
        case 0:
            *c = RED;
            break;
        case 1:
            *c = GREEN;
            break;
        case 2:
            *c = BLUE;
            break;
        case 3:
            *c = YELLOW;
            break;
        case 4:
            *c = GRAY;
            break;
    }
    auto t = core.add_component<Transform>(cube).value();
    t->translation = Vector3(0.0f, 0.0f, 0.0f);
    auto r = core.add_component<RigidBody>(cube);
    r.value()->velocity.y = (float) disd(gen);
    return cube;
}

int main() {
    Camera3D camera = {0};
    camera.position = (Vector3){10.0f, 10.0f, 10.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.position = Vector3Add(Vector3Scale(Vector3Subtract(camera.position, camera.target), 8), camera.position);
    camera.projection = CAMERA_PERSPECTIVE;

    core.register_component<Cube>();
    core.register_component<Color>();
    core.register_component<Transform>();
    core.register_component<RigidBody>();

    auto physics_system = core.register_system<PhysicsSystem>();
    auto render_system = core.register_system<RenderSystem>();
    auto cube_system = core.register_system<CubeSystem>();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(-60.0f, 60.0f);

    for (int i = 0; i < 2000; i++) {
        Entity cube = make_cube();
        core.get_component<Transform>(cube)->translation = (Vector3){
            dis(gen), dis(gen), dis(gen)
        };
        render_system->add_cube(cube);
        physics_system->add_entity(cube);
        cube_system->add_entity(cube);
    }

    InitWindow(800, 800, "Hi");
    ToggleFullscreen();

    while (!WindowShouldClose()) {

        physics_system->update(GetFrameTime());
        cube_system->update();

        BeginDrawing();
        ClearBackground(WHITE);
        DrawFPS(10, 10);
        BeginMode3D(camera);


        render_system->render_all();

        EndMode3D();

        EndDrawing();
    }


    return 0;
}
