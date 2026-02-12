#pragma once
#include <cassert>
#include <typeinfo>

#include "component_manager.h"
#include "packed_array.h"

template <typename C> void ComponentManager::register_component() {
  const char *component_name = typeid(C).name();
  assert(compname_to_array.find(component_name) == compname_to_array.end());
  auto pack_arr = new PackedArray<C>();
  auto cmp_type = available_components.front();
  compname_to_array.insert({component_name, pack_arr});
  component_array.at(cmp_type) = pack_arr;
  compname_to_comptype.insert({component_name, cmp_type});
  available_components.pop();
}

template <typename C> void ComponentManager::unregister_component() {
  const char *component_name = typeid(C).name();
  assert(compname_to_array.find(component_name) != compname_to_array.end());
  delete compname_to_array.at(component_name);
  compname_to_array.erase(component_name);
  ComponentType comp_type = compname_to_comptype.at(component_name);
  component_array.at(comp_type) = nullptr;
  compname_to_comptype.erase(component_name);
  available_components.push(comp_type);
}

template <typename C> C &ComponentManager::add_component_entity(Entity entity) {
  const char *component_name = typeid(C).name();
  assert(compname_to_array.find(component_name) != compname_to_array.end());
  return get_component_array<C>()->push(entity);
}

template <typename C>
void ComponentManager::remove_component_entity(Entity entity) {
  const char *component_name = typeid(C).name();
  assert(compname_to_array.find(component_name) != compname_to_array.end());
  get_component_array<C>()->remove(entity);
}

template <typename C> C &ComponentManager::get_component(Entity entity) {
  return get_component_array<C>()->get_entity(entity);
}

template <typename C> void ComponentManager::map_component(C (*func)(C val)) {
  get_component_array<C>()->map(func);
}

template <typename C>
C &ComponentManager::get_component_bytype(Entity entity,
                                          ComponentType component_type) {
  return static_cast<PackedArray<C> *>(component_array.at(component_type))
      ->get_entity(entity);
}

template <typename C> ComponentType ComponentManager::get_component_type() {
  const char *component_name = typeid(C).name();
  assert(compname_to_array.find(component_name) != compname_to_array.end());
  return compname_to_comptype.at(component_name);
}

template <typename C> bool ComponentManager::is_component_registered() {
  return compname_to_array.find(typeid(C).name()) != compname_to_array.end();
}

template <typename C> PackedArray<C> *ComponentManager::get_component_array() {
  static ComponentType component_type = component_type =
      get_component_type<C>();
  return static_cast<PackedArray<C> *>(component_array.at(component_type));
}