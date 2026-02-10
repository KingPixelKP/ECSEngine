#ifndef ECS_PACKED_ARRAY_H
#define ECS_PACKED_ARRAY_H

#include <unordered_map>

#include "entity.h"


class IPackedArray {
public:
    virtual ~IPackedArray() = default;

    virtual void remove(Entity entity) = 0;
};

template<typename T>
class PackedArray : public IPackedArray {
public:
    T & push(Entity entity);

    void remove(Entity entity) override;

    T & get_entity(Entity entity);
private:
    int size = 0;
    std::array<T, MAX_ENTITIES> array;
    std::array<int, MAX_ENTITIES> entity_to_index_array = {0};
    std::unordered_map<Entity, int> entity_to_index;
    std::unordered_map<int, Entity> index_to_entity;
};

#include "packed_array.cpp"

#endif //ECS_PACKED_ARRAY_H
