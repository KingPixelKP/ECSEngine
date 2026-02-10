#ifndef ECS_COMPONENT_MANAGER_H
#define ECS_COMPONENT_MANAGER_H
#include <memory>
#include <queue>
#include <unordered_map>

#include "packed_array.h"

class ComponentManager {
public:
    ComponentManager();

    /**
     * Registers a new component
     * @tparam C Component
     */
    template<typename C>
    void register_component();

    /**
     * Unregisters a component
     * @tparam C Component
     */
    template<typename C>
    void unregister_component();

    /**
     *
     * @tparam C Component
     * @param entity An entity to add C too
     * @return The newly added component
     */
    template<typename C>
    C & add_component_entity(Entity entity);

    /**
     *
     * @tparam C Component
     * @param entity An entity to strip the component from
     */
    template<typename C>
    void remove_component_entity(Entity entity);

    /**
     * Removes the entity from all the underlying arrays
     * @param entity Entity to be removed
     */
    void remove_entity(Entity entity);

    /**
     *
     * @tparam C Component
     * @param entity Entity
     * @return Returns the component C associated with entity
     */
    template<typename C>
    C & get_component(Entity entity);

    /**
     *
     * @tparam C A component
     * @param entity An entity
     * @param component_type A component type (not the type var)
     * @return The component associted with the entity
     */
    template<typename C>
    C & get_component_bytype(Entity entity, ComponentType component_type);

    /**
     *
     * @tparam C A component
     * @return The component type associated with that component
     */
    template<typename C>
    ComponentType get_component_type();

    /**
     *
     * @tparam C Component
     * @return True if the component is registered
     */
    template<typename C>
    bool is_component_registered();

private:
    std::array<IPackedArray*, MAX_COMPONENTS> component_array;
    std::unordered_map<const char *, IPackedArray* > compname_to_array;
    std::unordered_map<const char *, ComponentType> compname_to_comptype;
    std::queue<ComponentType> available_components;
};

#include "component_manager.cpp"

#endif //ECS_COMPONENT_MANAGER_H
