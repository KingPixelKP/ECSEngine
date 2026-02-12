#include <raylib.h>
#include <raymath.h>
#include <random>

typedef struct CubeComponent {
} CubeComponent;

#include "core.h"
#include "default_systems/physics_system.h"
#include "default_systems/mesh_render_system.h"
#include "default_systems/sprite_render_system.h"

//#include "default_components/sprite_component.h"
//#include "default_components/collision_box_component.h"
#include "default_components/mesh_component.h"
#include "default_components/rigid_body_component.h"
#include "default_components/transform_component.h"


Core core;

int main() {
    Camera3D camera = {0};
    camera.position = (Vector3){10.0f, 10.0f, 10.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, -1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.position = Vector3Add(Vector3Scale(Vector3Subtract(camera.position, camera.target), 8), camera.position);
    camera.projection = CAMERA_PERSPECTIVE;

    Camera2D camera2 = {0};
    camera2.offset = (Vector2){0.0f, 0.0f};
    camera2.target = (Vector2){0.0f, 0.0f};
    camera2.zoom = 1.0f;
    camera2.rotation = 0.0f;

    InitWindow(800, 800, "test");

    Texture2D tex = LoadTexture(
        "/home/kpgm/code/ecsDodLearning++/Tiny Swords (Free Pack)/Units/Black Units/Archer/Archer_Idle.png");

    auto sprite_system = core.register_system<SpriteRenderSystem>();
    sprite_system->init();
    auto physics_system = core.register_system<PhysicsSystem>();
    physics_system->init();
    auto mesh_system = core.register_system<MeshRenderSystem>();
    mesh_system->init();

    Mesh mesh = GenMeshCube(1.0f, 1.0f, 1.0f);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(-10.0f, 10.0f);
    std::uniform_int_distribution<int> diss(0, 5);

    for (int i = 0; i < 10000; i++) {
        auto e = core.create_entity();
        auto &sc = core.add_component<MeshComponent>(e);
        sc.material = LoadMaterialDefault();;
        switch (diss(gen)) {
            case 0:
                sc.material.maps[MATERIAL_MAP_ALBEDO].color = RED;
                break;
            case 1:
                sc.material.maps[MATERIAL_MAP_ALBEDO].color = BLUE;
                break;
            case 2:
                sc.material.maps[MATERIAL_MAP_ALBEDO].color = GREEN;
                break;
            case 3:
                sc.material.maps[MATERIAL_MAP_ALBEDO].color = GRAY;
                break;
            case 4:
                sc.material.maps[MATERIAL_MAP_ALBEDO].color = YELLOW;
                break;
            case 5:
                sc.material.maps[MATERIAL_MAP_ALBEDO].color = PURPLE;
                break;
        }
        sc.mesh = mesh;
        auto &tc = core.add_component<TransformComponent>(e);
        tc.translate = (Vector3){dis(gen), dis(gen), dis(gen)};
        core.add_component<RigidBodyComponent>(e);
    }


    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        physics_system->update(GetFrameTime());
        BeginDrawing();
        DrawFPS(20, 10);
        ClearBackground(WHITE);
        //BeginMode2D(camera2);
        //sprite_system->render_all();
        //EndMode2D();
        BeginMode3D(camera);
        mesh_system->render_all();
        EndMode3D();
        EndDrawing();
    }


    return 0;
}
