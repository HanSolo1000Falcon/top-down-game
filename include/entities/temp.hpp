#pragma once

#include <entities/entity.hpp>

class TempEntity : public Entity {
  friend class Entity;

protected:
  void Awake() override;
  void Tick(const float &frameDelta) override;
  void Render() override;

public:
  ~TempEntity() override = default;
};
