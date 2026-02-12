#pragma once
#ifndef ECS_ENTITY_H
#define ECS_ENTITY_H
#include <bitset>
#include <cstdint>

#include "component.h"

#ifndef MAX_ENTITIES
#define MAX_ENTITIES 8192 * 2
#endif

typedef uint16_t Entity;
typedef std::bitset<MAX_COMPONENTS> EntityBitset; //Used to show which components an entity has

#endif //ECS_ENTITY_H
