#include "entities/entity.hpp"
#include "entities/colliding-result.hpp"
#include "objects/object.hpp"

std::vector<std::unique_ptr<Entity>> Entity::AllEntities;

void Entity::CallTick(const float &frameDelta) {
  Tick(frameDelta);
  position.x += velocity.x * frameDelta;
  position.y += velocity.y * frameDelta;
}
void Entity::CallRender() { Render(); }

CollidingResult Entity::IsCurrentlyColliding() {
  for (auto i = 0; i < Object::AllObjects.size(); ++i) {
    const auto object = Object::AllObjects.at(i).get();

    const auto ourRight = position.x + size.x;
    const auto ourBottom = position.y + size.y;

    const auto theirRight = object->position.x + object->size.x;
    const auto theirBottom = object->position.y + object->size.y;

    const auto overlapsX =
        ourRight > object->position.x && position.x < theirRight;
    const auto overlapsY =
        ourBottom > object->position.y && position.y < theirBottom;

    if (overlapsX && overlapsY) {
      return {true, object};
    }
  }

  return {false, nullptr};
}
