#pragma once

#include "objects/object.hpp"

class CustomizableObject : public Object {
  friend class Object;

protected:
  void Awake() override {};
  void Render() override;

public:
  ~CustomizableObject() override = default;
};
