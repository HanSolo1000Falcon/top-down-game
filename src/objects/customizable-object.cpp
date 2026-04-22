#include "objects/customizable-object.hpp"
#include <raylib.h>

void CustomizableObject::Render() { DrawRectangleV(position, size, GRAY); }
