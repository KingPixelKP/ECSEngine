#pragma once
#include <cassert>

#include "system_manager.h"

template <typename S>
std::shared_ptr<S> SystemManager::register_system(Core *core) {
    const char *system_name = typeid(S).name();
    assert(name_to_system.find(system_name) == name_to_system.end());
    std::shared_ptr<S> system = std::make_shared<S>(core);
    name_to_system.insert({system_name, system});
    name_to_system_bitset.insert({system_name, std::make_shared<SystemBitSet>()});
    return system;
}

template<typename S>
void SystemManager::unregister_system() {
    const char *system_name = typeid(S).name();
    assert(name_to_system.find(system_name) != name_to_system.end());
    name_to_system.erase(system_name);
    name_to_system_bitset.erase(system_name);
}

template<typename S>
void SystemManager::system_bitset_set(ComponentType component_type) {
    const char *system_name = typeid(S).name();
    // assert(name_to_system.contains(system_name));
    name_to_system_bitset.at(system_name)->set(component_type, true);
}

template<typename S>
void SystemManager::system_bitset_clear(ComponentType component_type) {
    const char *system_name = typeid(S).name();
    assert(name_to_system.find(system_name) != name_to_system.end());
    name_to_system_bitset.at(system_name)->set(component_type, false);
}