#include <entities/entity.hpp>
#include <entities/temp.hpp>
#include <game-manager.hpp>
#include <objects/object.hpp>
#include <objects/temp.hpp>
#include <raylib.h>

int StartTick() {
  Entity::Create<TempEntity>();

  Object::Create<TempObject>();

  while (!WindowShouldClose()) {
    const auto frameDelta = GetFrameTime();

    for (auto i = 0; i < Entity::AllEntities.size(); ++i) {
      Entity::AllEntities.at(i)->CallTick(frameDelta);
    }

    BeginDrawing();
    ClearBackground(WHITE);

    for (auto i = 0; i < Object::AllObjects.size(); ++i) {
      Object::AllObjects.at(i)->CallRender();
    }

    for (auto i = 0; i < Entity::AllEntities.size(); ++i) {
      Entity::AllEntities.at(i)->CallRender();
    }

    EndDrawing();
  }
  return 0;
}
