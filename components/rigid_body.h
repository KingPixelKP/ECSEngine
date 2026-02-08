#ifndef ECS_RIGID_BODY_H
#define ECS_RIGID_BODY_H
#include "raylib.h"

typedef struct RigidBody {
    Vector3 velocity;
    Vector3 acceleration;
}RigidBody;

#endif //ECS_RIGID_BODY_H