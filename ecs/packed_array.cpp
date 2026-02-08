#include "packed_array.h"

template<typename T>
void PackedArray<T>::push(T element, Entity entity) {
    index_to_entity.insert({vector.size(), entity});
    entity_to_index.insert({entity, vector.size()});
    vector.push_back(element);
}

template<typename T>
void PackedArray<T>::remove(Entity entity) {
    int remove_index = entity_to_index.at(entity);
    int last_index = vector.size() - 1;
    Entity last_entity = index_to_entity.at(last_index);
    vector[remove_index] = vector[last_index];
    vector.pop_back();
    entity_to_index.insert({last_entity, remove_index});
    index_to_entity.erase(last_index);
    index_to_entity.insert({remove_index, last_entity});
    entity_to_index.erase(entity);
}

template<typename T>
T PackedArray<T>::get_entity(Entity entity) {
    return vector.at(entity_to_index.at(entity));
}
