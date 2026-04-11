#include <raylib.h>

class Entity {
private:
  int rotation = 0;
  Vector2 size{0, 0};
  Vector2 position{0, 0};
  Vector2 velocity{0, 0};

  virtual void Awake();
  virtual void Tick(const float &frameDelta);
  virtual void Render();

public:
  // Awake() gets called in the constructor.
  Entity();
  virtual ~Entity();

  // I keep Awake(), Tick(), and Render() private as to be able to do stuff to
  // every single (think; hitbox rendering for debugging).
  void CallTick(const float &frameDelta);
  void CallRender();

  bool IsCurrentlyColliding();
};
