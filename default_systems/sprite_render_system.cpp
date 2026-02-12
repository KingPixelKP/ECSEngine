#include <raylib.h>

#include "sprite_render_system.h"

#include "../core.h"
#include "../default_components/sprite_component.h"
#include "../default_components/transform_component.h"
#include "../ecs/system.h"


void SpriteRenderSystem::init() {
    core->register_component<TransformComponent>();
    core->register_component<SpriteComponent>();
    core->add_component<SpriteRenderSystem, TransformComponent>();
    core->add_component<SpriteRenderSystem, SpriteComponent>();
}

void SpriteRenderSystem::render_all() {
    for (auto e: entities) {
        auto sprite_component = core->get_component<SpriteComponent>(e);
        if (!sprite_component.is_init()) continue; //TODO Check this for performance later
        const auto transform_component = core->get_component<TransformComponent>(e);

        sprite_component.dest_rect.x = transform_component.translate.x;
        sprite_component.dest_rect.y = transform_component.translate.y;

        sprite_component.dest_rect.width *= transform_component.scale.x;
        sprite_component.dest_rect.height *= transform_component.scale.y;

        sprite_component.origin.x *= sprite_component.dest_rect.width;
        sprite_component.origin.y *= sprite_component.dest_rect.height;

        DrawTexturePro(*sprite_component.texture, sprite_component.source_rect, sprite_component.dest_rect,
                       sprite_component.origin, sprite_component.rotation, sprite_component.color);
    }
}
