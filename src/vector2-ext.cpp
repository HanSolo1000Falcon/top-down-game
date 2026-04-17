#include "vector2-ext.hpp"
#include <cmath>

float Vector2Ext::Distance(Vector2 a, Vector2 b) {
  const float xDist = a.x - b.x;
  const float yDist = a.y - b.y;

  return sqrt(xDist * xDist + yDist * yDist);
}
