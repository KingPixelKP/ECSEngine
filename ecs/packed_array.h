#pragma once
#ifndef ECS_PACKED_ARRAY_H
#define ECS_PACKED_ARRAY_H

#include <array>
#include <unordered_map>

#include "entity.h"

#define NOTHING -1


class IPackedArray {
public:
    virtual ~IPackedArray() = default;

    virtual void remove(Entity entity) = 0;
};

template<typename T>
class PackedArray : public IPackedArray {
public:
    PackedArray();

    T & push(Entity entity);

    void remove(Entity entity) override;

    T & get_entity(Entity entity);

    void map(T (*func)(T val));
private:
    int size = 0;
    std::array<T, MAX_ENTITIES> array;
    std::array<int, MAX_ENTITIES> entity_to_index_array = {0};
    std::unordered_map<int, Entity> index_to_entity;
};

//#include "packed_array.cpp"
#include "packed_array.tpp"

#endif //ECS_PACKED_ARRAY_H
