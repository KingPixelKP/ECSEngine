#ifndef ECS_ENTITY_MANAGER_H
#define ECS_ENTITY_MANAGER_H
#include <memory>
#include <queue>
#include <unordered_map>

#include "entity.h"

class EntityManager {
    public:
    EntityManager();
    Entity create_entity();
    void destroy_entity(Entity entity);
    EntityBitset get_entity_bitset(Entity entity);
    private:
    int alive_entity_count;
    std::queue<Entity> entity_queue;
    std::array<EntityBitset, MAX_ENTITIES> entity_bitset;
};

#include "entity_manager.cpp"

#endif //ECS_ENTITY_MANAGER_H
