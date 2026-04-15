#include <game-manager.hpp>
#include <objects/temp.hpp>
#include <raylib.h>

int StartTick() {
  Object::Create<TempObject>();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);

    for (auto i = 0; i < Object::AllObjects.size(); ++i) {
      Object::AllObjects.at(i)->CallRender();
    }

    EndDrawing();
  }
  return 0;
}
