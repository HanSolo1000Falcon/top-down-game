#include <game-manager.hpp>
#include <objects/temp.hpp>
#include <raylib.h>

int StartTick() {
  Object::AllObjects = std::vector<Object>();

  const auto obj1 = TempObject();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    EndDrawing();
  }
  return 0;
}
