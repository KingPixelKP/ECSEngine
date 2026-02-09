#ifndef ECS_SYSTEM_H
#define ECS_SYSTEM_H

#include <vector>
#include <set>

#include "ecs/entity.h"

class System {
public:
    std::set<Entity> entities;
};
#endif //ECS_SYSTEM_H
