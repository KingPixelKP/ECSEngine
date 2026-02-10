#ifndef ECS_SYSTEM_MANAGER_H
#define ECS_SYSTEM_MANAGER_H

#include <memory>
#include <unordered_map>

#include "system.h"

typedef std::bitset<MAX_COMPONENTS> SystemBitSet;

class SystemManager
{
public:
    /**
     * Register a new system
     * @tparam S System to register
     * @return A pointer to the register
     */
    template <typename S>
    std::shared_ptr<S> register_system(Core *core);

    /**
     * Unregisters a system
     * @tparam S System to unregister
     */
    template <typename S>
    void unregister_system();

    /**
     * Sets the bit in ComponentType to true
     * @tparam S System to set the bit
     * @param component_type Component (aka the bit)
     */
    template <typename S>
    void system_bitset_set(ComponentType component_type);

    /**
     * Sets the bit in ComponentType to false
     * @tparam S System to clear the bit
     * @param component_type Component (aka the bit)
     */
    template <typename S>
    void system_bitset_clear(ComponentType component_type);

    /**
     * Should be called every time an entity's bit set is changed (the components the entity is associated with)
     * @param entity Entity which bitset changed
     * @param entity_bitset The entity's bitset
     */
    void entity_bitset_change(Entity entity, EntityBitset entity_bitset);

    /**
     * Removes an entity from all the managed systems
     * @param entity Entity to be removed
     */
    void remove_entity(Entity entity);

private:
    std::unordered_map<const char *, std::shared_ptr<System>> name_to_system;
    std::unordered_map<const char *, std::shared_ptr<SystemBitSet>> name_to_system_bitset;
};

#include "system_manager.cpp"

#endif // ECS_SYSTEM_MANAGER_H
