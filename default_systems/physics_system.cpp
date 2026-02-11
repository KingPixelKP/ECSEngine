#include <iostream>
#include <raylib.h>
#include <raymath.h>

#include "../ecs/system.h"
#include "../core.h"
#include "../default_components/rigid_body_component.h"
#include "../default_components/transform_component.h"

class PhysicsSystem : public System {
public:
    using System::System;

    ~PhysicsSystem() override = default;

    void init();

    void update(float delta);
};

void PhysicsSystem::init() {
    core->register_component<TransformComponent>();
    core->register_component<RigidBodyComponent>();
    core->add_component<PhysicsSystem, TransformComponent>();
    core->add_component<PhysicsSystem, RigidBodyComponent>();
}

void PhysicsSystem::update(const float delta) {
    for (auto it = entities.begin(); it != entities.end(); ++it) {
        auto &t = core->get_component<TransformComponent>(*it);
        auto &r = core->get_component<RigidBodyComponent>(*it);


        r.acceleration.y = r.gravity * delta;
        r.velocity = (Vector3){
            r.velocity.x + r.acceleration.x * delta, r.velocity.y + r.acceleration.y * delta,
            r.velocity.z + r.acceleration.z * delta
        };
        t.translate = (Vector3){
            t.translate.x + r.velocity.x * delta, t.translate.y + r.velocity.y * delta,
            t.translate.z + r.velocity.z * delta
        };

        //For some reason raylib's defaults are very slow
        //r.velocity = Vector3Add(r.velocity, Vector3Scale(r.acceleration, delta));
        //t.translate = Vector3Add(t.translate, Vector3Scale(r.velocity, delta));
    }
}
