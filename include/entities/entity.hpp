#include <raylib.h>

class Entity {
protected:
  virtual void Awake() = 0;
  virtual void Tick(const float &frameDelta) = 0;
  virtual void Render() = 0;

public:
  int rotation = 0;
  Vector2 size{0, 0};
  Vector2 position{0, 0};
  Vector2 velocity{0, 0};

  // Awake() gets called in the constructor.
  Entity();
  virtual ~Entity() = 0;

  // I keep Awake(), Tick(), and Render() private as to be able to do stuff to
  // every single (think; hitbox rendering for debugging).
  void CallTick(const float &frameDelta);
  void CallRender();

  bool IsCurrentlyColliding();
};
