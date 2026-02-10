#ifndef ECS_COMPONENT_MANAGER_H
#define ECS_COMPONENT_MANAGER_H
#include <memory>
#include <queue>
#include <unordered_map>

#include "packed_array.h"

class ComponentManager {
public:
    ComponentManager();

    template<typename C>
    void register_component();

    template<typename C>
    void unregister_component();

    template<typename C>
    C & add_component_entity(Entity entity);

    template<typename C>
    void remove_component_entity(Entity entity);

    template<typename C>
    C & get_component(Entity entity);

    template<typename C>
    C & get_component_bytype(Entity entity, ComponentType component_type);

    template<typename C>
    ComponentType get_component_type();

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
