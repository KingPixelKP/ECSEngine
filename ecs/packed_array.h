#ifndef ECS_PACKED_ARRAY_H
#define ECS_PACKED_ARRAY_H

#include <unordered_map>
#include <vector>

#include "entity.h"

class IPackedArray {
    public:
    virtual ~IPackedArray() = default;
    virtual void remove(Entity entity) = 0;
};

template<typename T>
class PackedArray : public IPackedArray {
public:
    void push(T element, Entity entity);

    void remove(Entity entity) override;

    T get_entity(Entity entity);

    //void get_index(int index);

private:
    std::vector<T> vector;
    std::unordered_map<Entity, int> entity_to_index;
    std::unordered_map<int, Entity> index_to_entity;
};

#include "packed_array.cpp"

#endif //ECS_PACKED_ARRAY_H
