#ifndef ECS_SYSTEM_H
#define ECS_SYSTEM_H

#include <set>

#include "entity.h"

class Core;

class System {
public:
    System(Core *_core) : core(_core) {};
    std::set<Entity> entities;
    Core *core;
};
#endif //ECS_SYSTEM_H
