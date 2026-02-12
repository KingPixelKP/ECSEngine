#include "component_manager.h"
#include <cassert>

ComponentManager::ComponentManager() {
  for (int i = 0; i < MAX_COMPONENTS; i++) {
    available_components.push(i);
  }
}

void ComponentManager::remove_entity(Entity entity) {
  for (auto packed_array : component_array) {
    packed_array->remove(entity);
  }
}
