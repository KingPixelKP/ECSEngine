#pragma once
#ifndef ECSDODLEARNING_TRANSFORM_COMPONENT_H
#define ECSDODLEARNING_TRANSFORM_COMPONENT_H
#include <raylib.h>

class TransformComponent {
public:
    TransformComponent();

    Vector3 translate;
    Vector3 rotate;
    Vector3 scale;

    Matrix get_matrix();
};

//#include "transform_component.cpp"

#endif //ECSDODLEARNING_TRANSFORM_COMPONENT_H
