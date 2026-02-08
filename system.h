#ifndef ECS_SYSTEM_H
#define ECS_SYSTEM_H

#include <vector>
#include <algorithm>

#include "ecs/entity.h"

class System {
public:
    virtual void add_entity(const Entity entity) { entities.push_back(entity); }

    virtual void remove_entity(const Entity entity) {
        entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
    }

protected:
    std::vector<Entity> entities;
};
#endif //ECS_SYSTEM_H
