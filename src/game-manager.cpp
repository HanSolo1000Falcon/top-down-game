#include <game-manager.hpp>
#include <raylib.h>

int StartTick() {
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    EndDrawing();
  }
  return 0;
}
