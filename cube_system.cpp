#include <random>
#include <raylib.h>

#include "system.h"
#include "core.h"
#include "components/rigid_body.h"

class CubeSystem : public System {
public:
    void update();
};

void CubeSystem::update() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> disd(0.0f, 80.0f);

    for (Entity e: entities) {
        auto t = core.get_component<Transform>(e);
        if (t->translation.y <= -100) {
            auto r = core.get_component<RigidBody>(e);
            t->translation.y = disd(gen);
            r->velocity.y = disd(gen);
        }
    }
}
