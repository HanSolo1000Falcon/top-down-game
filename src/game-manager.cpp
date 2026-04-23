#include "game-manager.hpp"
#include "constants.hpp"
#include "entities/entity.hpp"
#include "entities/player.hpp"
#include "objects/customizable-object.hpp"
#include "objects/object.hpp"
#include <raylib.h>

CustomizableObject *CreateCustomizableObject(Vector2 position, Vector2 size) {
  auto object = Object::Create<CustomizableObject>();
  object->position = position;
  object->size = size;
  return object;
}

int StartTick() {
  Entity::Create<Player>();

  /*CreateCustomizableObject({0, 0}, {constants::WINDOW_WIDTH, 100});
  CreateCustomizableObject({0, constants::WINDOW_HEIGHT - 100},
                           {constants::WINDOW_WIDTH, 100});*/

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
