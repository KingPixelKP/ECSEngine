#include "packed_array.h"
#include <iostream>
#include <cassert>

template<typename T>
T & PackedArray<T>::push(Entity entity) {
    index_to_entity.insert({size, entity});
    entity_to_index.insert({entity, size});
    entity_to_index_cache.at(entity) = size;
    dirty_bit.set(entity, false);
    std::cout << size << std::endl;
    size++;
    return array.at(size - 1);
}

template<typename T>
void PackedArray<T>::remove(Entity entity) {
    int remove_index = entity_to_index.at(entity);
    int last_index = size - 1;
    Entity last_entity = index_to_entity.at(last_index);
    array[remove_index] = array[last_index];
    entity_to_index.insert({last_entity, remove_index});
    index_to_entity.erase(last_index);
    index_to_entity.insert({remove_index, last_entity});
    entity_to_index.erase(entity);
    size--;
    dirty_bit.set(last_entity, true);
    dirty_bit.set(entity, true);
}

template<typename T>
T & PackedArray<T>::get_entity(Entity entity) {
    if (!dirty_bit.test(entity))
        return array.at(entity_to_index_cache.at(entity));
    int entity_index = entity_to_index.at(entity);
    entity_to_index_cache.at(entity) = entity_index;
    dirty_bit.set(entity, false);
    return array.at(entity_index);
}
