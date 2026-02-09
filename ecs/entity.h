#ifndef ECS_ENTITY_H
#define ECS_ENTITY_H
#include <bitset>
#include <cstdint>

#include "component.h"

#define MAX_ENTITIES 8192 * 2

typedef uint16_t Entity;
typedef std::bitset<MAX_COMPONENTS> EntityBitset; //Used to show which components an entity has

#endif //ECS_ENTITY_H
