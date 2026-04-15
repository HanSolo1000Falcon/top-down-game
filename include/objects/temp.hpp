#include <objects/object.hpp>

class TempObject : public Object {
  friend class Object;

protected:
  void Awake() override;
  void Render() override;

public:
  ~TempObject() override = default;
};
