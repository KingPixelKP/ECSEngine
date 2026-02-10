#ifndef ECS_RIGID_BODY_H
#define ECS_RIGID_BODY_H
#include "raylib.h"

typedef struct RigidBodyComponent {
    Vector3 velocity;
    Vector3 acceleration;
}RigidBodyComponent;

#endif //ECS_RIGID_BODY_H