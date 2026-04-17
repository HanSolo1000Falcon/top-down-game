#include "constants.hpp"
#include "game-manager.hpp"
#include <raylib.h>

int main() {
  InitWindow(constants::WINDOW_WIDTH, constants::WINDOW_HEIGHT,
             "Top Down Game");
  SetTargetFPS(60);
  return StartTick();
}
