#include "entity_manager.h"

#include <cassert>

EntityManager::EntityManager() {
    alive_entity_count = 0;
    for (int i = 0; i < MAX_ENTITIES; i++) {
        entity_queue.push(i);
    }
}

Entity EntityManager::create_entity() {
    assert("Maximum ammount of entities reached" && !entity_queue.empty());
    alive_entity_count++;
    Entity ret = entity_queue.front();
    entity_bitset.at(ret).reset();
    entity_queue.pop();
    return ret;
}

void EntityManager::destroy_entity(Entity entity) {
    alive_entity_count--;
    entity_queue.push(entity); // Erase the entity
    entity_bitset.at(entity).reset();
}

EntityBitset EntityManager::get_entity_bitset(Entity entity) {
    return entity_bitset.at(entity);
}
