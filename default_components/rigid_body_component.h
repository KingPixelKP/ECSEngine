#ifndef ECS_RIGID_BODY_H
#define ECS_RIGID_BODY_H
#include "raylib.h"

typedef struct RigidBodyComponent {
    RigidBodyComponent();

    Vector3 velocity;
    Vector3 acceleration;
    float gravity;
} RigidBodyComponent;

inline RigidBodyComponent::RigidBodyComponent() : velocity((Vector3){0.0f, 0.0f, 0.0f}),
                                                  acceleration((Vector3){0.0f, 0.0f, 0.0f}), gravity(9800) {
};

#endif //ECS_RIGID_BODY_H
