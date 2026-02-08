#include "component_manager.h"
#include <cassert>


ComponentManager::ComponentManager() {
    for (int i = 0; i < MAX_COMPONENTS; i++) {
        available_components.push(i);
    }
}

template<typename C>
void ComponentManager::register_component() {
    const char *component_name = typeid(C).name();
    assert(!compname_to_array.contains(component_name));
    compname_to_array.insert({component_name, std::make_shared<PackedArray<std::shared_ptr<C> > >()});
    compname_to_comptype.insert({component_name, available_components.front()});
    available_components.pop();
}

template<typename C>
void ComponentManager::unregister_component() {
    const char *component_name = typeid(C).name();
    assert(compname_to_array.contains(component_name));
    compname_to_array.erase(component_name);
    ComponentType comp_type = compname_to_comptype.at(component_name);
    compname_to_comptype.erase(component_name);
    available_components.push(comp_type);
}

template<typename C>
std::shared_ptr<C> ComponentManager::add_component_entity(Entity entity) {
    const char *component_name = typeid(C).name();
    assert(compname_to_array.contains(component_name));
    auto comp_ptr =std::make_shared<C>();
    auto packed_array = static_pointer_cast<PackedArray<std::shared_ptr<C>>>(compname_to_array.at(component_name));
    packed_array->push(comp_ptr, entity);
    return comp_ptr;
}

template<typename C>
void ComponentManager::remove_component_entity(Entity entity) {
    const char *component_name = typeid(C).name();
    assert(compname_to_array.contains(component_name));
    auto packed_array = static_pointer_cast<PackedArray<std::shared_ptr<C>>>(compname_to_array.at(component_name));
    packed_array->remove(entity);
}

template<typename C>
std::shared_ptr<C> ComponentManager::get_component(Entity entity) {
    const char *component_name = typeid(C).name();
    assert(compname_to_array.contains(component_name));
    auto pack_array = static_pointer_cast<PackedArray<std::shared_ptr<C>>>(compname_to_array.at(component_name));
    return pack_array->get_entity(entity);
}

template<typename C>
ComponentType ComponentManager::get_component_type() {
    const char *component_name = typeid(C).name();
    assert(compname_to_array.contains(component_name));
    return compname_to_comptype.at(component_name);
}
