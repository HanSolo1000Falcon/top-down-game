#include <entities/entity.hpp>
#include <objects/object.hpp>

Entity::Entity() { Awake(); }
void Entity::CallTick(const float &frameDelta) { Tick(frameDelta); }
void Entity::CallRender() { Render(); }

bool Entity::IsCurrentlyColliding() {
  for (const auto object : Object::AllObjects) {
    const auto ourRight = position.x + size.x;
    const auto ourBottom = position.y + size.y;

    const auto theirRight = object->position.x + object->size.x;
    const auto theirBottom = object->position.y + object->size.y;

    const auto overlapsX =
        ourRight > object->position.x && position.x < theirRight;
    const auto overlapsY =
        ourBottom > object->position.y && position.y < theirBottom;

    if (overlapsX && overlapsY) {
      return true;
    }
  }

  return false;
}
