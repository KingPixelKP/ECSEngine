#include <cassert>

#include "system_manager.h"

void SystemManager::entity_bitset_change(Entity entity, EntityBitset entity_bitset) {
    for (auto i: name_to_system) {
        auto sys_bit_set = *name_to_system_bitset.at(i.first);
        if ((sys_bit_set & entity_bitset) == sys_bit_set) {
            i.second->entities.insert(entity);
        } else {
            i.second->entities.erase(entity);
        }
    }
}

void SystemManager::remove_entity(Entity entity) {
    for (auto pair: name_to_system) {
        pair.second->entities.erase(entity);
    }
}
