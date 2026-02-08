#include <cassert>
#include <memory>

#include "system_manager.h"

template<typename S>
std::shared_ptr<S> SystemManager::register_system() {
    const char *system_name = typeid(S).name();
    assert(!name_to_system.contains(system_name));
    std::shared_ptr<S> system = std::make_shared<S>();
    name_to_system.insert({system_name, system});
    return system;
}

template<typename S>
void SystemManager::unregister_system() {
    const char *system_name = typeid(S).name();
    assert(name_to_system.contains(system_name));
    name_to_system.erase(system_name);
}
