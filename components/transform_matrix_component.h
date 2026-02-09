#ifndef ECS_TRANSFORM_MATRIX_COMPONENT_H
#define ECS_TRANSFORM_MATRIX_COMPONENT_H

#include <raylib.h>
#include <raymath.h>

class TransformMatrixComponent {
public:
    TransformMatrixComponent();
    void translate(float x, float y, float z);
    void scale(float x, float y, float z);
    void rotate(float x, float y, float z);
    void set_translation(float x, float y, float z);
    void set_scale(float x, float y, float z);
    void set_rotation(float x, float y, float z);
    Matrix transform;

    private:
};

#include "transform_matrix_component.cpp"

#endif //ECS_TRANSFORM_MATRIX_COMPONENT_H
