#include <raylib.h>
#include <raymath.h>

#include "physics_system.h"

#include "../core.h"
#include "../default_components/rigid_body_component.h"
#include "../default_components/transform_component.h"
#include "../ecs/system.h"

void PhysicsSystem::init() {
  core->register_component<TransformComponent>();
  core->register_component<RigidBodyComponent>();
  core->add_component<PhysicsSystem, TransformComponent>();
  core->add_component<PhysicsSystem, RigidBodyComponent>();
}

void PhysicsSystem::update() {
  for (auto it = entities.begin(); it != entities.end(); ++it) {
    auto &t = core->get_component<TransformComponent>(*it);
    auto &r = core->get_component<RigidBodyComponent>(*it);

    Ray v1 = (Ray){t.translate, r.velocity};

    if (DEBUG_VELOCITY) DrawLine3D(t.translate, r.velocity + t.translate, RED);
    if (DEBUG_ACCELERATION) DrawLine3D(t.translate, r.acceleration + t.translate, GREEN);

    r.acceleration.y = r.gravity * FIXED_DELTA;
    r.velocity = (Vector3){r.velocity.x + r.acceleration.x * FIXED_DELTA,
                           r.velocity.y + r.acceleration.y * FIXED_DELTA,
                           r.velocity.z + r.acceleration.z * FIXED_DELTA};
    t.translate = (Vector3){t.translate.x + r.velocity.x * FIXED_DELTA,
                            t.translate.y + r.velocity.y * FIXED_DELTA,
                            t.translate.z + r.velocity.z * FIXED_DELTA};
  }
}
