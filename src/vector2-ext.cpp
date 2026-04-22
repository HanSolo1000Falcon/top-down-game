#include "vector2-ext.hpp"
#include <cmath>
#include <raylib.h>

float Vector2Ext::Distance(Vector2 a, Vector2 b) {
  const float xDist = a.x - b.x;
  const float yDist = a.y - b.y;

  return sqrt(xDist * xDist + yDist * yDist);
}

float Vector2Ext::SquaredSize(Vector2 a) { return a.x * a.x + a.y * a.y; }

Vector2 Vector2Ext::Difference(Vector2 a, Vector2 b) {
  return {a.x - b.x, a.y - b.y};
}

Vector2 Vector2Ext::Add(Vector2 a, Vector2 b) { return {a.x + b.x, a.y + b.y}; }

Vector2 Vector2Ext::Multiply(Vector2 a, float b) { return {a.x * b, a.y * b}; }

float Vector2Ext::DistanceSquared(Vector2 a, Vector2 b) {
  return SquaredSize(Difference(a, b));
}

float Vector2Ext::Dot(Vector2 a, Vector2 b) { return a.x * b.x + a.y * b.y; }
