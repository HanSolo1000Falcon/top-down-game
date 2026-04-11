#include <entities/entity.hpp>

Entity::Entity() { Awake(); }
void Entity::CallTick(const float &frameDelta) { Tick(frameDelta); }
void Entity::CallRender() { Render(); }

bool Entity::IsCurrentlyColliding() {
  return false; /* Nothing to collide with yet! */
}
