#include <memory>
#include <raylib.h>
#include <vector>

class Object {
protected:
  virtual void Awake() = 0;
  virtual void Render() = 0;

public:
  static std::vector<std::unique_ptr<Object>> AllObjects;

  template <typename T, typename... Args> static T *Create(Args &&...args) {
    auto object = std::make_unique<T>(std::forward<Args>(args)...);
    T *raw = object.get();
    AllObjects.emplace_back(std::move(object));
    raw->Awake();
    return raw;
  }

  Vector2 size{0, 0};
  Vector2 position{0, 0};

  virtual ~Object() = default;

  void CallRender();
};
