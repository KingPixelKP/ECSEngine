#include <cassert>

#include "sprite_component.h"

bool SpriteComponent::is_source_defined() {
    return source_rect.x != NOT_DEFINED & source_rect.y != NOT_DEFINED & source_rect.width != NOT_DEFINED & source_rect.
           height != NOT_DEFINED;
}

void SpriteComponent::top_left() {
    assert(is_source_defined());
    origin = {0.0f, 0.0f};
}

void SpriteComponent::top_right() {
    assert(is_source_defined());
    origin = {1.0f, 0.0f};
}

void SpriteComponent::bottom_left() {
    assert(is_source_defined());
    origin = {0.0f, 1.0f};
}

void SpriteComponent::bottom_right() {
    assert(is_source_defined());
    origin = {1.0f, 1.0f};
}

void SpriteComponent::center() {
    assert(is_source_defined());
    origin = {0.5, 0.5f};
}

void SpriteComponent::left() {
    assert(is_source_defined());
    origin = {0.0f, 0.5f};
}

void SpriteComponent::right() {
    assert(is_source_defined());
    origin = {1.0f, 0.5f};
}

void SpriteComponent::bottom() {
    assert(is_source_defined());
    origin = {0.5f, 1.0f};
}

void SpriteComponent::top() {
    assert(is_source_defined());
    origin = {0.5f, 0.0f};
}

void SpriteComponent::set_source(int num_columns, int num_rows, int column, int row) {
    int frame_width = texture->width / num_columns;
    int frame_height = texture->height / num_rows;
    source_rect.x = frame_width * column;
    source_rect.y = frame_height * row;
    source_rect.width = frame_width;
    source_rect.height = frame_height;
}

bool SpriteComponent::is_init() {
    return texture != nullptr && is_source_defined();
}
