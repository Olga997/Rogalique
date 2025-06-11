#pragma once
#include "GameObject.h"


namespace RogaliqueGame {
class PlaingZone {
public :
    PlaingZone(int width, int heigh);


   private:
    XYZEngine::GameObject* gameObject;
};
}  // namespace RogaliqueGame