#include "entities/player.hpp"
#include "constants.hpp"
#include <raylib.h>

void Player::Awake() {
  position = {constants::WINDOW_WIDTH / 2.0f, constants::WINDOW_HEIGHT / 2.0f};
  size = {50, 50};
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
}

void Player::Render() { DrawRectangleV(position, size, GRAY); }
