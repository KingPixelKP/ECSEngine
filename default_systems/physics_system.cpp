#include <raylib.h>
#include <raymath.h>

#include "physics_system.h"

#include "../ecs/system.h"
#include "../core.h"
#include "../default_components/rigid_body_component.h"
#include "../default_components/transform_component.h"

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
    }
}
