#include <objects/object.hpp>

class TempObject : public Object {
protected:
  void Awake() override;
  void Render() override;

public:
  ~TempObject() override;
};
