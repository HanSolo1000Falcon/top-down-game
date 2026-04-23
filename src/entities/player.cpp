#include "entities/player.hpp"
#include "constants.hpp"
#include "vector2-ext.hpp"
#include <algorithm>
#include <cfloat>
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
                                             0.0f, 1.0f)));
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
    auto ithPoint = GetPoint(i, objectPosition, objectSize);
    auto nextIthPoint = GetPoint(nextI, objectPosition, objectSize);
    points.emplace_back(ClosestPointOnSegment(ithPoint, nextIthPoint, point));
  }

  Vector2 closestPoint = points[0];
  float closestDistance = FLT_MAX;

  for (auto i = 0; i < points.size(); ++i) {
    float distance = Vector2Ext::DistanceSquared(point, points[i]);
    if (distance < closestDistance) {
      closestDistance = distance;
      closestPoint = points[i];
    }
  }

  return closestPoint;
}

void Player::Tick(const float &frameDelta) {
  const auto movingUp = IsKeyDown(KEY_W) || IsKeyDown(KEY_UP);
  const auto movingDown = IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN);
  const auto movingLeft = IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT);
  const auto movingRight = IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT);

  Vector2 inputDir = {0, 0};
  if (movingUp) {
    inputDir.y -= 1.0f;
  }
  if (movingDown) {
    inputDir.y += 1.0f;
  }
  if (movingLeft) {
    inputDir.x -= 1.0f;
  }
  if (movingRight) {
    inputDir.x += 1.0f;
  }

  if (inputDir.x != 0 || inputDir.y != 0) {
    float mag = Vector2Ext::Magnitude(inputDir);
    inputDir = Vector2Ext::Multiply(inputDir, 1.0f / mag);

    Vector2 targetVelocity =
        Vector2Ext::Multiply(inputDir, constants::MAX_PLAYER_SPEED);
    float accel = constants::PLAYER_SPEED * frameDelta;
    velocity.x =
        std::clamp(velocity.x + (targetVelocity.x - velocity.x) * accel /
                                    constants::MAX_PLAYER_SPEED,
                   -constants::MAX_PLAYER_SPEED, constants::MAX_PLAYER_SPEED);
    velocity.y =
        std::clamp(velocity.y + (targetVelocity.y - velocity.y) * accel /
                                    constants::MAX_PLAYER_SPEED,
                   -constants::MAX_PLAYER_SPEED, constants::MAX_PLAYER_SPEED);
  } else {
    float frictionFactor =
        1.0f - std::min(constants::PLAYER_FRICTION * frameDelta /
                            constants::MAX_PLAYER_SPEED,
                        1.0f);
    velocity.x *= frictionFactor;
    velocity.y *= frictionFactor;

    if (std::abs(velocity.x) < 1.0f) {
      velocity.x = 0;
    }
    if (std::abs(velocity.y) < 1.0f) {
      velocity.y = 0;
    }
  }

  const auto collidingResult = IsCurrentlyColliding();

  if (collidingResult.isColliding) {
    auto &other = *collidingResult.collidingWith;

    const auto overlapLeft = (position.x + size.x) - other.position.x;
    const auto overlapRight = (other.position.x + other.size.x) - position.x;
    const auto overlapTop = (position.y + size.y) - other.position.y;
    const auto overlapBottom = (other.position.y + other.size.y) - position.y;

    const auto minOverlapX = std::min(overlapLeft, overlapRight);
    const auto minOverlapY = std::min(overlapTop, overlapBottom);

    if (minOverlapX < minOverlapY) {
      if (overlapLeft < overlapRight) {
        position.x -= overlapLeft;
        if (velocity.x > 0) {
          velocity.x = 0;
        }
      } else {
        position.x += overlapRight;
        if (velocity.x < 0) {
          velocity.x = 0;
        }
      }
    } else {
      if (overlapTop < overlapBottom) {
        position.y -= overlapTop;
        if (velocity.y > 0) {
          velocity.y = 0;
        }
      } else {
        position.y += overlapBottom;
        if (velocity.y < 0) {
          velocity.y = 0;
        }
      }
    }
  }

  if (position.x < -size.x - constants::PLAYER_TELEPORT_PADDING) {
    position.x = constants::WINDOW_WIDTH;
  } else if (position.x >
             constants::WINDOW_WIDTH + constants::PLAYER_TELEPORT_PADDING) {
    position.x = -size.x;
  }

  if (position.y < -size.y - constants::PLAYER_TELEPORT_PADDING) {
    position.y = constants::WINDOW_HEIGHT;
  } else if (position.y >
             constants::WINDOW_HEIGHT + constants::PLAYER_TELEPORT_PADDING) {
    position.y = -size.y;
  }
}

void Player::Render() { DrawRectangleV(position, size, GRAY); }
