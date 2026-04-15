#include <raylib.h>
#include <vector>

class Object {
protected:
  virtual void Awake() = 0;
  virtual void Render() = 0;

public:
  static std::vector<Object *> AllObjects;

  Vector2 size{0, 0};
  Vector2 position{0, 0};

  // Yet again Render() and Awake() calls are abstracted away.
  Object();
  virtual ~Object() = 0;

  void CallRender();
};
