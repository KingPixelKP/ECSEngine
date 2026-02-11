#ifndef ECSDODLEARNING_MESH_COMPONENT_H
#define ECSDODLEARNING_MESH_COMPONENT_H

#include <raylib.h>

typedef struct MeshComponent {
    MeshComponent();
    Mesh mesh;
    Material material;
} MeshComponent;

inline MeshComponent::MeshComponent() {
}

#endif //ECSDODLEARNING_MESH_COMPONENT_H