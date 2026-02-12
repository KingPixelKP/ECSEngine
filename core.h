#pragma once
#ifndef ECS_CORE_H
#define ECS_CORE_H

#include <memory>

#include "ecs/entity_manager.h"
#include "ecs/component_manager.h"
#include "ecs/system_manager.h"

class Core {
public:
    /**
     * Creates a new entity
     * @return An Entity
     */
    Entity create_entity();

    /**
     * Destroys all the references of an entity from a system
     * @param entity An entity
     */
    void destroy_entity(Entity entity);

    /**
     * @tparam S A system
     */
    template<typename S>
    std::shared_ptr<S> register_system();

    /**
     * Unregisters a system
     * @tparam S A system
     */
    template<typename S>
    void unregister_system();

    /**
     * Adds a component from a  system's desired
     * @tparam S System to add component too
     * @tparam C Componetn to be added
     */
    template<typename S, typename C>
    void add_component();

    /**
     * Removes a component from a system's desired
     * @tparam S System to remove component from
     * @tparam C Component to be removed
     */
    template<typename S, typename C>
    void remove_component();

    /**
     * Given a component it will register that component
     * @tparam C A Component
     */
    template<typename C>
    void register_component();

    /**
     * Given a component it will unregister that component
     * @tparam C A component
     */
    template<typename C>
    void unregister_component();

    /**
     * Adds a component to an entity
     * @tparam C Component to add
     * @param entity Entity to add component too
     */
    template<typename C>
    C & add_component(Entity entity);

    /**
     * Removes a component from an entity
     * @tparam C Component to remove
     * @param entity Entity to remove the component from
     */
    template<typename C>
    void remove_component(Entity entity);

    /**
     * Gets the component of type C from an Entity
     * @tparam C Component type to retrieve
     * @param entity Entity to retrieve from
     * @return The component from the desired entity
     */
    template<typename C>
    C & get_component(Entity entity);

    template<typename C>
    C & get_component_by_type(Entity entity, ComponentType component_type);

    template<typename  C>
    void map_component(C (*func)(C val));

    template<typename C>
    ComponentType get_component_type();

    template<typename C>
    bool has_component(Entity entity);


private:
    SystemManager system_manager;
    EntityManager entity_manager;
    ComponentManager component_manager;
};

#include "ecs/core.tpp"

#endif //ECS_CORE_H
