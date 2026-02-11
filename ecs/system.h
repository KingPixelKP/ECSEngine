#ifndef ECS_SYSTEM_H
#define ECS_SYSTEM_H

#include <set>

#include "entity.h"

class Core;

class System {
public:
    //System();
    explicit System(Core *_core) : core(_core) {};
    virtual ~System()  = default;
    std::set<Entity> entities;
    Core *core;
};
#endif //ECS_SYSTEM_H
