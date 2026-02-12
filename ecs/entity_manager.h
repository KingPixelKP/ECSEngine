#ifndef ECS_ENTITY_MANAGER_H
#define ECS_ENTITY_MANAGER_H
#include <memory>
#include <queue>
#include <array>
#include <unordered_map>

#include "entity.h"

class EntityManager {
    public:
    EntityManager();

    /**
     * Creates a new entity
     * @return An entity
     */
    Entity create_entity();

    /**
     * Destroys an entity
     * @param entity Entity to be destroyed
     */
    void destroy_entity(Entity entity);

    /**
     *
     * @param entity An entity
     * @return The entity bitset attached to the entity
     */
    EntityBitset& get_entity_bitset(Entity entity);
    private:
    int alive_entity_count;
    std::queue<Entity> entity_queue;
    std::array<EntityBitset, MAX_ENTITIES> entity_bitset;
};

#include "entity_manager.cpp"

#endif //ECS_ENTITY_MANAGER_H
