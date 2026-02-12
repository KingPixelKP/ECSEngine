#include "../ecs/system.h"

class SpriteRenderSystem : public System {
public:
    using System::System;
    ~SpriteRenderSystem() override = default;

    void init();

    void render_all();
};
