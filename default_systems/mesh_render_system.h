#include "../ecs/system.h"

class MeshRenderSystem : public System {
public:
    using System::System;
    ~MeshRenderSystem() override = default;

    void init();

    void render_all();
};