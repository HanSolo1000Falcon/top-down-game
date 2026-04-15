#include <entities/temp.hpp>
#include <iostream>
#include <raylib.h>

void TempEntity::Awake() {
  position = {20, 20};
  size = {70, 70};
}

void TempEntity::Tick(const float &frameDelta) {
  if (IsKeyDown(KEY_W)) {
    position.y -= 100 * frameDelta;
  } else if (IsKeyDown(KEY_S)) {
    position.y += 100 * frameDelta;
  }

  if (IsKeyDown(KEY_D)) {
    position.x += 100 * frameDelta;
  } else if (IsKeyDown(KEY_A)) {
    position.x -= 100 * frameDelta;
  }

  if (IsCurrentlyColliding()) {
    std::cout << "COLLIDING\n";
  } else {
    std::cout << "NOT COLLIDING\n";
  }
}

void TempEntity::Render() { DrawRectangleV(position, size, GRAY); }
