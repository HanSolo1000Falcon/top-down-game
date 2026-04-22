#pragma once

#include <raylib.h>

namespace Vector2Ext {
float Distance(Vector2 a, Vector2 b);
float SquaredSize(Vector2 a);
Vector2 Difference(Vector2 a, Vector2 b);
Vector2 Add(Vector2 a, Vector2 b);
Vector2 Multiply(Vector2 a, float b);
float DistanceSquared(Vector2 a, Vector2 b);
float Dot(Vector2 a, Vector2 b);
}; // namespace Vector2Ext
