#include "../core.h"

Entity Core::create_entity() {
    return entity_manager.create_entity();
}

void Core::destroy_entity(const Entity entity) {
    entity_manager.destroy_entity(entity);
}

template<typename S>
std::shared_ptr<S> Core::register_system() {
    return system_manager.register_system<S>();
}

template<typename S>
void Core::unregister_system() {
    system_manager.unregister_system<S>();
}

template<typename C>
void Core::register_component() {
    component_manager.register_component<C>();
}

template<typename C>
void Core::unregister_component() {
    component_manager.unregister_component<C>();
}

template<typename C>
std::expected<std::shared_ptr<C>,std::string> Core::add_component(const Entity entity) {
    if (entity_manager.get_entity_bitset(entity)->test(component_manager.get_component_type<C>())) {
        return std::unexpected<std::string>("The entity already has that component");
    }
    auto comp_ptr = component_manager.add_component_entity<C>(entity);
    entity_manager.get_entity_bitset(entity)->set(component_manager.get_component_type<C>(), true);
    return comp_ptr;
}

template<typename C>
void Core::remove_component(const Entity entity) {
    component_manager.remove_component_entity<C>(entity);
    entity_manager.get_entity_bitset(entity)->set(component_manager.get_component_type<C>(), false);
}

template<typename C>
std::shared_ptr<C> Core::get_component(const Entity entity) {
    return component_manager.get_component<C>(entity);
}

template<typename C>
ComponentType Core::get_component_type(Entity entity) {
    return component_manager.get_component_type<C>(entity);
}

template<typename C>
bool Core::has_component(Entity entity) {
    auto bitset = entity_manager.get_entity_bitset(entity);
    auto comp_type = component_manager.get_component_type<C>();
    return bitset->test(comp_type);
}
