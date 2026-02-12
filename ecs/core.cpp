#include "../core.h"

Entity Core::create_entity() {
    return entity_manager.create_entity();
}

void Core::destroy_entity(const Entity entity) {
    entity_manager.destroy_entity(entity);
    component_manager.remove_entity(entity);
    system_manager.remove_entity(entity);
}
