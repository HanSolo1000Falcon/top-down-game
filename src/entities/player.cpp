#include "entities/player.hpp"
#include "constants.hpp"
#include "vector2-ext.hpp"
#include <algorithm>
#include <raylib.h>
#include <vector>

void Player::Awake() {
  position = {constants::WINDOW_WIDTH / 2.0f, constants::WINDOW_HEIGHT / 2.0f};
  size = {50, 50};
}

Vector2 ClosestPointOnSegment(Vector2 a, Vector2 b, Vector2 point) {
  Vector2 ap = Vector2Ext::Difference(point, a);
  Vector2 ab = Vector2Ext::Difference(b, a);
  return Vector2Ext::Add(
      a, Vector2Ext::Multiply(ab, std::clamp(Vector2Ext::Dot(ap, ab) /
                                                 Vector2Ext::SquaredSize(ab),
                                             0, 1)));
}

Vector2 GetPoint(int i, Vector2 position, Vector2 size) {
  switch (i) {
  case 1:
    return {position.x + size.x, position.y};

  case 2:
    return {position.x + size.x, position.y + size.y};

  case 3:
    return {position.x, position.y + size.y};

  default:
    return position;
  }
}

Vector2 ClosestPointOnObject(Vector2 objectSize, Vector2 objectPosition,
                             Vector2 point) {
  std::vector<Vector2> points{};

  for (auto i = 0; i < 4; ++i) {
    auto nextI = (i + 1) % 4;
    auto ithPoint = GetPoint(i, position, size);
    auto nextIthPoint = GetPoint(nextI, position, size);
    points.emplace_back(ClosestPointOnSegment(ithPoint, nextIthPoint, point));
  }

  std::vector<int> distances{};

  for (auto closestPoint : points) {
    distances.emplace_back(Vector2Ext::DistanceSquared(point, closestPoint));
  }

  Vector2 closestPoint;
}

void Player::Tick(const float &frameDelta) {
  const auto movingUp = IsKeyDown(KEY_W) || IsKeyDown(KEY_UP);
  const auto movingDown = IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN);
  const auto movingLeft = IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT);
  const auto movingRight = IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT);

  if (movingUp || movingDown || movingLeft || movingRight) {
    const auto velocityAddition = constants::PLAYER_SPEED * frameDelta;
    if (movingUp) {
      velocity.y -= velocityAddition;
    } else if (movingDown) {
      velocity.y += velocityAddition;
    }

    if (movingLeft) {
      velocity.x -= velocityAddition;
    } else if (movingRight) {
      velocity.x += velocityAddition;
    }
  } else {
    const auto frictionAddition = constants::PLAYER_FRICTION * frameDelta;

    if (velocity.y != 0) {
      velocity.y -= frictionAddition * (velocity.y > 0 ? 1 : -1);
    }
    if (velocity.x != 0) {
      velocity.x -= frictionAddition * (velocity.x > 0 ? 1 : -1);
    }
  }

  if (velocity.y > constants::MAX_PLAYER_SPEED) {
    velocity.y = constants::MAX_PLAYER_SPEED;
  } else if (velocity.y < -constants::MAX_PLAYER_SPEED) {
    velocity.y = -constants::MAX_PLAYER_SPEED;
  }

  if (velocity.x > constants::MAX_PLAYER_SPEED) {
    velocity.x = constants::MAX_PLAYER_SPEED;
  } else if (velocity.x < -constants::MAX_PLAYER_SPEED) {
    velocity.x = -constants::MAX_PLAYER_SPEED;
  }

  const auto collidingResult = IsCurrentlyColliding();

  if (collidingResult.isColliding) {
  }
}

void Player::Render() { DrawRectangleV(position, size, GRAY); }
