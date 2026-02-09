#include "transform_matrix_component.h"

TransformMatrixComponent::TransformMatrixComponent() {
    transform = MatrixIdentity();
}

void TransformMatrixComponent::translate(float x, float y, float z) {
    transform = MatrixMultiply(transform, MatrixTranslate(x, y, z));
}

void TransformMatrixComponent::scale(float x, float y, float z) {
    transform = MatrixMultiply(transform, MatrixScale(x,y,a));
}

void TransformMatrixComponent::rotate(float angle, float x, float y, float z) {
    transform = MatrixMultiply(transform, MatrixRotateXYZ(x,y,z));
}
