#include <raylib.h>
#include <raymath.h>

#include "ecs/system.h"
#include "core.h"

class RenderSystem : public System {
public:

    void render_all();

private:
};


void RenderSystem::render_all() {
    for (auto e: entities) {
        auto t = core->get_component<Transform>(e);
        auto me = core->get_component<Mesh>(e);
        auto ma = core->get_component<Material>(e);
        auto c = core->get_component<Color>(e);
        auto bbox = core->get_component<BoundingBox>(e);

        ma.maps[MATERIAL_MAP_ALBEDO].color = c;
        DrawMesh(me, ma,  MatrixTranslate(t.translation.x, t.translation.y, t.translation.z));
    }
}
