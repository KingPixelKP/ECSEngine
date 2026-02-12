#pragma once
#ifndef ECS_RIGID_BODY_H
#define ECS_RIGID_BODY_H
#include <raylib.h>

#define KG1 1

typedef struct RigidBodyComponent {
    RigidBodyComponent();

    Vector3 velocity;
    Vector3 acceleration;
    float gravity;
    float mass;
} RigidBodyComponent;

inline RigidBodyComponent::RigidBodyComponent() : velocity((Vector3){0.0f, 0.0f, 0.0f}),
                                                  acceleration((Vector3){0.0f, 0.0f, 0.0f}), gravity(-9.8f),
                                                  mass(KG1) {
};

#endif //ECS_RIGID_BODY_H
