#include <entities/entity.hpp>
#include <objects/object.hpp>

std::vector<std::unique_ptr<Entity>> Entity::AllEntities;

void Entity::CallTick(const float &frameDelta) { Tick(frameDelta); }
void Entity::CallRender() { Render(); }

bool Entity::IsCurrentlyColliding() {
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
      return true;
    }
  }

  return false;
}
