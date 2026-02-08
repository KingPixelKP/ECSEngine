#include <raylib.h>

#include "system.h"
#include "core.h"
#include "components/cube_component.h"

class CubeRenderer : public System {
public:
    CubeRenderer();

    void render_all();

private:
};

CubeRenderer::CubeRenderer() {

}

void CubeRenderer::render_all() {
    for (Entity e : entities) {
        auto transform = core.get_component<Transform>(e);
        auto cube = core.get_component<Cube>(e);
        auto color = core.get_component<Color>(e);
        DrawCube(transform->translation, cube->width,cube->height, cube->length, *color.get());
    }
}

class RenderSystem : public System {
public:
    RenderSystem();

    void add_cube(Entity e);
    void remove_cube(Entity e);

    void render_all();
private:
    using System::add_entity;
    using System::remove_entity;

private:
    CubeRenderer cube_renderer;
};

RenderSystem::RenderSystem() {
}

void RenderSystem::add_cube(Entity e) {
    cube_renderer.add_entity(e);
}

void RenderSystem::remove_cube(Entity e) {
    cube_renderer.remove_entity(e);
}

void RenderSystem::render_all() {
    cube_renderer.render_all();
}
