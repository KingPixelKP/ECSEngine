#include <random>
#include <raylib.h>

#include "system.h"
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
    static auto t_type = core.get_component_type<Transform>();
    static auto r_type = core.get_component_type<RigidBody>();
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> disd(0.0f, 80.0f);

    int i = entities.size();

    for (Entity e: entities) {
        auto &t = core.get_component_by_type<Transform>(e, t_type);
        if (t.translation.y <= -100) {
            auto &r = core.get_component_by_type<RigidBody>(e,r_type);
            t.translation = (Vector3){0.0f, 0.0f, 0.0f};
            r.velocity.y = disd(gen);
            r.velocity.x = disd(gen);
            r.velocity.z = disd(gen);
        }
    }
}
