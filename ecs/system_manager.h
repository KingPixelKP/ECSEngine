#ifndef ECS_SYSTEM_MANAGER_H
#define ECS_SYSTEM_MANAGER_H

#include <memory>
#include <unordered_map>

#include "../system.h"

class SystemManager {
public:
    /**
     * Register a new system
     * @tparam S System to register
     * @return A pointer to the register
     */
    template<typename S>
    std::shared_ptr<S> register_system();

    /**
     * Unregisters a system
     * @tparam S System to unregister
     */
    template<typename S>
    void unregister_system();

private:
    std::unordered_map<const char *, std::shared_ptr<System> > name_to_system;
};

#include "system_manager.cpp"

#endif //ECS_SYSTEM_MANAGER_H
