#include <random>
#include <raylib.h>

#include "ecs/system.h"
#include "core.h"
#include "components/rigid_body.h"

class CubeSystem : public System {
public:
    void update();
};

int func(float x) {
    return std::pow(x, 2);
}

void CubeSystem::update() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> disd(-80.0f, 80.0f);

    int i = entities.size();

    for (Entity e: entities) {
        auto &t = core->get_component<Transform>(e);
        if (t.translation.z <= -100) {
            auto &r = core->get_component<RigidBody>(e);
            t.translation = (Vector3){0.0f, 0.0f, 0.0f};
            r.velocity.z = disd(gen);
            r.velocity.x = disd(gen);
            r.velocity.y = 0.0f;
        }
    }
}
