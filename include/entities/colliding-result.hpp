#pragma once

#include "objects/object.hpp"

struct CollidingResult {
public:
  bool isColliding;
  Object *collidingWith;
};
