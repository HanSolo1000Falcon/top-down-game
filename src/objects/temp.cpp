#include <constants.hpp>
#include <objects/temp.hpp>
#include <raylib.h>

void TempObject::Awake() {
  position = {constants::WINDOW_WIDTH / 2.0f, constants::WINDOW_HEIGHT / 2.0f};
  size = {100, 100};
}

void TempObject::Render() { DrawRectangleV(position, size, BLACK); }
