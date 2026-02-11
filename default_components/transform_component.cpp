#include <raylib.h>
#include <raymath.h>

#include "transform_component.h"

TransformComponent::TransformComponent() {
    translate = Vector3(0.0f, 0.0f, 0.0f);
    rotate = Vector3(0.0f, 0.0f, 0.0f);
    scale = Vector3(1.0f, 1.0f, 1.0f);
}

Matrix TransformComponent::get_matrix() {
    return MatrixMultiply(MatrixTranslate(translate.x,translate.y,translate.z),
                          MatrixMultiply(MatrixRotateXYZ(rotate), MatrixScale(scale.x, scale.y, scale.z)));
}
