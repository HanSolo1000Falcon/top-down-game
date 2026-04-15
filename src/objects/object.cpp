#include <objects/object.hpp>

std::vector<Object *> Object::AllObjects;

Object::Object() {
  AllObjects.emplace_back(this);
  Awake();
}

void Object::CallRender() { Render(); }
