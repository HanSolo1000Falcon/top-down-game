#include <objects/object.hpp>

std::vector<std::unique_ptr<Object>> Object::AllObjects;

void Object::CallRender() { Render(); }
