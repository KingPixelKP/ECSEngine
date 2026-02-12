#ifndef PHYSICS_H
#include "../ecs/system.h"

#define FIXED_DELTA 0.1f

#ifndef DEBUG_VELOCITY
#define DEBUG_VELOCITY false
#endif

#ifndef DEBUG_ACCELERATION
#define DEBUG_ACCELERATION false
#endif

class PhysicsSystem : public System {
public:
    using System::System;

    ~PhysicsSystem() override = default;

    void init();

    void update();
};
#endif