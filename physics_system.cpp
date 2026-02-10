#include <iostream>
#include <raylib.h>
#include <raymath.h>

#include "ecs/system.h"
#include "core.h"
#include "components/rigid_body.h"

#define SCALE 100.0f
#define GRAVITY (9.8f * SCALE)

class PhysicsSystem : public System {
public:
    void update(float delta) {
        for (auto it = entities.begin(); it != entities.end(); ++it) {
            auto &t = core->get_component<Transform>(*it);
            auto &r = core->get_component<RigidBody>(*it);

            r.acceleration.z = -GRAVITY * delta;
            r.velocity = Vector3Add(r.velocity, Vector3Scale(r.acceleration, delta));
            t.translation = Vector3Add(t.translation, Vector3Scale(r.velocity, delta));
        }
    }

private:
};
