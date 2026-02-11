#include <raylib.h>
#include <raymath.h>

#include "../ecs/system.h"
#include "../core.h"
#include "../default_components/mesh_component.h"
#include "../default_components/transform_component.h"

class MeshRenderSystem : public System {
public:
    using System::System;
    ~MeshRenderSystem() override = default;

    void init();

    void render_all();
};


void MeshRenderSystem::init() {
    core->register_component<TransformComponent>();
    core->register_component<MeshComponent>();
    core->add_component<MeshRenderSystem, TransformComponent>();
    core->add_component<MeshRenderSystem, MeshComponent>();
}

void MeshRenderSystem::render_all() {
    for (auto e: entities) {
        auto transform_component = core->get_component<TransformComponent>(e);
        const auto mesh_component = core->get_component<MeshComponent>(e);

        DrawMesh(mesh_component.mesh, mesh_component.material,  transform_component.get_matrix());
    }
}
