#include "../ecs/system.h"

class PhysicsSystem : public System {
public:
    using System::System;

    ~PhysicsSystem() override = default;

    void init();

    void update(float delta);
};