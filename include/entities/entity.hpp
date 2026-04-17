#pragma once

#include "entities/colliding-result.hpp"
#include <memory>
#include <raylib.h>
#include <vector>

class Entity {
protected:
  virtual void Awake() = 0;
  virtual void Tick(const float &frameDelta) = 0;
  virtual void Render() = 0;

public:
  static std::vector<std::unique_ptr<Entity>> AllEntities;

  // Awake() gets called in our beautiful Create() method.
  template <typename T, typename... Args> static T *Create(Args &&...args) {
    auto object = std::make_unique<T>(std::forward<Args>(args)...);
    T *raw = object.get();
    AllEntities.emplace_back(std::move(object));
    raw->Awake();
    return raw;
  }

  int rotation = 0;
  Vector2 size{0, 0};
  Vector2 position{0, 0};
  Vector2 velocity{0, 0};

  virtual ~Entity() = default;

  // Virtual method calls are abstracted away as to be able to apply stuff like
  // hitbox rendering to every entity, etc.
  void CallTick(const float &frameDelta);
  void CallRender();

  CollidingResult IsCurrentlyColliding();
};
