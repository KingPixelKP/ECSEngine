#ifndef ECSDODLEARNING_SPRITE_COMPONENT_H
#define ECSDODLEARNING_SPRITE_COMPONENT_H

#include <raylib.h>

#define NOT_DEFINED -1.0f


class SpriteComponent {
public:
    SpriteComponent() : texture(nullptr), source_rect({NOT_DEFINED,NOT_DEFINED,NOT_DEFINED,NOT_DEFINED}),
                        dest_rect({0.0f, 0.0f, 100.0f, 100.0f}), origin({0.0f, 0.0f}), rotation(0.0f), color(RAYWHITE) {
    } ;

    //Methods to set the origin point
    //They will use the width and height of source_rect as reference
    void center();

    void top_left();

    void top_right();

    void bottom_left();

    void bottom_right();

    void left();

    void right();

    void bottom();

    void top();

    /**
     * Will set the source_rect to point into some part of a texture (spritesheet usually)
     * @param num_columns Total number of columns the sprite sheet has
     * @param num_rows Total number of rows the sprite sheet has
     * @param column The selected column (Array notation)
     * @param row The selected row (Array notation)
     */
    void set_source(int num_columns, int num_rows, int column, int row);

    bool is_init();

    Texture2D *texture;
    Rectangle source_rect, dest_rect;
    Vector2 origin;
    float rotation;
    Color color;
private:
    bool is_source_defined();
};

#include "sprite_component.cpp"

#endif //ECSDODLEARNING_SPRITE_COMPONENT_H
