#pragma once
#include "packed_array.h"

template<typename T>
PackedArray<T>::PackedArray() {
    for (int i = 0; i < MAX_ENTITIES; i++) {
        entity_to_index_array[i] = -NOTHING;
    }
}

template<typename T>
T & PackedArray<T>::push(Entity entity) {
    entity_to_index_array[entity] = size;
    size++;
    return array.at(size - 1);
}

template<typename T>
void PackedArray<T>::remove(Entity entity) {
    int remove_index = entity_to_index_array[entity];
    if (remove_index == NOTHING) return; //Packed array does not have this entity
    int last_index = size - 1;
    Entity last_entity = index_to_entity.at(last_index);
    array[remove_index] = array[last_index];
    entity_to_index_array[last_entity] = remove_index;
    index_to_entity.erase(last_index);
    index_to_entity.insert({remove_index, last_entity});
    entity_to_index_array[entity] = NOTHING;
    size--;
}

template<typename T>
T & PackedArray<T>::get_entity(Entity entity) {
    //int entity_index = entity_to_index.at(entity);

    return array.at(entity_to_index_array[entity]);
}
