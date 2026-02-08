#ifndef ECS_SYSTEM_MANAGER_H
#define ECS_SYSTEM_MANAGER_H

#include <memory>
#include <unordered_map>

#include "../system.h"

class SystemManager {
public:
    template<typename S>
    std::shared_ptr<S> register_system();

    template<typename S>
    void unregister_system();

    template<typename S>
    void add_entity(Entity entity);

    template<typename S>
    void remove_entity(Entity entity);

private:
    std::unordered_map<const char *, std::shared_ptr<System> > name_to_system;
};

#include "system_manager.cpp"

#endif //ECS_SYSTEM_MANAGER_H
