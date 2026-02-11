#include "../core.h"

Entity Core::create_entity() {
    return entity_manager.create_entity();
}

void Core::destroy_entity(const Entity entity) {
    entity_manager.destroy_entity(entity);
    component_manager.remove_entity(entity);
    system_manager.remove_entity(entity);
}

template<typename S>
std::shared_ptr<S> Core::register_system() {
    return system_manager.register_system<S>(this);
}

template<typename S>
void Core::unregister_system() {
    system_manager.unregister_system<S>();
}

template<typename S, typename C>
void Core::add_component() {
    assert(component_manager.is_component_registered<C>());
    system_manager.system_bitset_set<S>(component_manager.get_component_type<C>());
}

template<typename S, typename C>
void Core::remove_component() {
    assert(component_manager.is_component_registered<C>());
    system_manager.system_bitset_clear<S>(component_manager.get_component_type<C>());
}

template<typename C>
void Core::register_component() {
    if (component_manager.is_component_registered<C>()) return;
    component_manager.register_component<C>();
}

template<typename C>
void Core::unregister_component() {
    component_manager.unregister_component<C>();
}

template<typename C>
C & Core::add_component(const Entity entity) {
    C &comp_ptr = component_manager.add_component_entity<C>(entity);
    entity_manager.get_entity_bitset(entity).set(component_manager.get_component_type<C>(), true);
    system_manager.entity_bitset_change(entity, entity_manager.get_entity_bitset(entity));
    return comp_ptr;
}

template<typename C>
void Core::remove_component(const Entity entity) {
    component_manager.remove_component_entity<C>(entity);
    entity_manager.get_entity_bitset(entity).set(component_manager.get_component_type<C>(), false);
}

template<typename C>
C & Core::get_component(const Entity entity) {
    static ComponentType component_type = component_type = component_manager.get_component_type<C>();
    return component_manager.get_component_bytype<C>(entity, component_type);
}

template<typename C>
ComponentType Core::get_component_type() {
    return component_manager.get_component_type<C>();
}

template<typename C>
C & Core::get_component_by_type(Entity entity, ComponentType component_type) {
    return component_manager.get_component_bytype<C>(entity, component_type);
}

template<typename C>
bool Core::has_component(Entity entity) {
    static ComponentType component_type = component_type = component_manager.get_component_type<C>();
    auto bitset = entity_manager.get_entity_bitset(entity);
    return bitset.test(component_type);
}
