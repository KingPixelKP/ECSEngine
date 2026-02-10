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
    //std::cout << component_name << std::endl;
    assert(!compname_to_array.contains(component_name));
    auto pack_arr = new PackedArray<C>();
    auto cmp_type = available_components.front();

    compname_to_array.insert({component_name, pack_arr});
    component_array.at(cmp_type) = pack_arr;
    compname_to_comptype.insert({component_name, cmp_type});
    available_components.pop();
}


template<typename C>
void ComponentManager::unregister_component() {
    const char *component_name = typeid(C).name();
    assert(compname_to_array.contains(component_name));
    delete compname_to_array.at(component_name);
    compname_to_array.erase(component_name);
    ComponentType comp_type = compname_to_comptype.at(component_name);
    component_array.at(comp_type) = nullptr;
    compname_to_comptype.erase(component_name);
    available_components.push(comp_type);
}


template<typename C>
C & ComponentManager::add_component_entity(Entity entity) {
    const char *component_name = typeid(C).name();
    assert(compname_to_array.contains(component_name));
    auto packed_array = static_cast<PackedArray<C>*>(compname_to_array.at(component_name));
    return packed_array->push(entity);;
}


template<typename C>
void ComponentManager::remove_component_entity(Entity entity) {
    const char *component_name = typeid(C).name();
    assert(compname_to_array.contains(component_name));
    auto packed_array = (compname_to_array.at(component_name));
    packed_array->remove(entity);
}

void ComponentManager::remove_entity(Entity entity) {
    for (auto packed_array : component_array) {
        packed_array->remove(entity);
    }
}

template<typename C>
C & ComponentManager::get_component(Entity entity) {
    const char *component_name = typeid(C).name();
    //assert(compname_to_array.contains(component_name));
    return static_cast<PackedArray<C>* >(compname_to_array.at(component_name))->
            get_entity(entity);
}


template<typename C>
C & ComponentManager::get_component_bytype(Entity entity, ComponentType component_type) {
    return static_cast<PackedArray<C>*>(component_array.at(component_type))->get_entity(entity);
}


template<typename C>
ComponentType ComponentManager::get_component_type() {
    const char *component_name = typeid(C).name();
    assert("Component is not registerer" && compname_to_comptype.contains(component_name));
    return compname_to_comptype.at(component_name);
}

template<typename C>
bool ComponentManager::is_component_registered() {
    return compname_to_comptype.contains(typeid(C).name());
}
