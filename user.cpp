#include <raylib.h>
#include <raymath.h>
#include <random>

typedef struct CubeComponent {
} CubeComponent;

#include "core.h"
#include "physics_system.cpp"
#include "render_system.cpp"
#include "cube_system.cpp"
#include "camera_system.cpp"
#include "components/keyboard_movement_component.h"

Core core;

Mesh mesh;
Material material;
BoundingBox mesh_bbox;

Entity make_cube() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis(0.0, 8);
    static std::uniform_real_distribution<float> disd(0.0f, 80.0f);
    Entity cube = core.create_entity();

    auto &m = core.add_component<Mesh>(cube);
    m = mesh;
    auto &ma = core.add_component<Material>(cube);
    ma = material;
    auto &bbox = core.add_component<BoundingBox>(cube);
    bbox = mesh_bbox;
    core.add_component<CubeComponent>(cube);

    auto &c = core.add_component<Color>(cube);
    switch (dis(gen)) {
        case 0:
            c = RED;
            break;
        case 1:
            c = GREEN;
            break;
        case 2:
            c = BLUE;
            break;
        case 3:
            c = YELLOW;
            break;
        case 4:
            c = GRAY;
            break;
        case 5:
            c = PURPLE;
            break;
        case 6:
            c = BLACK;
            break;
        case 7:
            c = PINK;
            break;
        case 8:
            c = MAROON;
            break;
    }
    auto &t = core.add_component<Transform>(cube);
    t.translation = Vector3(0.0f, 0.0f, 0.0f);
    auto &r = core.add_component<RigidBody>(cube);
    r.velocity.y = (float) disd(gen);
    return cube;
}

int main() {
    Camera3D camera = {0};
    camera.position = (Vector3){0.0f, 10.0f, 0.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 0.0f, 1.0f};
    camera.fovy = 45.0f;
    camera.position = Vector3Add(Vector3Scale(Vector3Subtract(camera.position, camera.target), 12), camera.position);
    camera.projection = CAMERA_PERSPECTIVE;

    core.register_component<KeyboardMovementComponent>();
    core.register_component<int>();
    core.register_component<Transform>();
    core.register_component<Camera3D>();
    core.register_component<CubeComponent>();
    core.register_component<Color>();
    core.register_component<RigidBody>();
    core.register_component<Mesh>();
    core.register_component<Material>();
    core.register_component<BoundingBox>();

    auto cam_sys = core.register_system<CameraSystem>();
    core.add_component<CameraSystem, Camera3D>();
    core.add_component<CameraSystem, KeyboardMovementComponent>();

    Entity camera_entity = core.create_entity();
    auto &c = core.add_component<Camera3D>(camera_entity);
    c = camera;
    core.add_component<KeyboardMovementComponent>(camera_entity);


    auto physics_system = core.register_system<PhysicsSystem>();
    core.add_component<PhysicsSystem, Transform>();
    core.add_component<PhysicsSystem, RigidBody>();
    core.add_component<PhysicsSystem, BoundingBox>();

    auto render_system = core.register_system<RenderSystem>();
    core.add_component<RenderSystem, Transform>();
    core.add_component<RenderSystem, Mesh>();
    core.add_component<RenderSystem, Material>();
    core.add_component<RenderSystem, Color>();

    auto cube_system = core.register_system<CubeSystem>();
    core.add_component<CubeSystem, Transform>();
    core.add_component<CubeSystem, RigidBody>();
    core.add_component<CubeSystem, CubeComponent>();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(-60.0f, 60.0f);;

    InitWindow(800, 800, "Hi");
    ToggleFullscreen();

    mesh = GenMeshSphere(1.0f,8,8);

    material = LoadMaterialDefault();
    mesh_bbox = GetMeshBoundingBox(mesh);

    int frame = 0;

    for (int i = 0; i < 16000; i++) {
        Entity cube = make_cube();
        core.get_component<Transform>(cube).translation = (Vector3){
            dis(gen), dis(gen), dis(gen)
        };
    }


    while (!WindowShouldClose()) {
        frame++;
        if (frame == 20) {
            core.unregister_component<KeyboardMovementComponent>();
            core.unregister_component<int>();
        };
        physics_system->update(GetFrameTime());
        cube_system->update();

        BeginDrawing();
        ClearBackground(WHITE);
        DrawFPS(10, 10);
        BeginMode3D(core.get_component<Camera3D>(camera_entity));


        render_system->render_all();

        EndMode3D();

        EndDrawing();
    }


    return 0;
}
