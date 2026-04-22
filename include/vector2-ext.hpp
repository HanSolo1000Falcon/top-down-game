#pragma once

#include <raylib.h>

namespace Vector2Ext {
float Distance(Vector2 a, Vector2 b);
int SquaredSize(Vector2 a);
Vector2 Difference(Vector2 a, Vector2 b);
Vector2 Add(Vector2 a, Vector2 b);
Vector2 Multiply(Vector2 a, int b);
int DistanceSquared(Vector2 a, Vector2 b);
int Dot(Vector2 a, Vector2 b);
}; // namespace Vector2Ext
