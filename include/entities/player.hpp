#pragma once

#include "entities/entity.hpp"

class Player : public Entity {
  friend class Entity;

protected:
  void Awake() override;
  void Tick(const float &frameDelta) override;
  void Render() override;

public:
  ~Player() override = default;
};
