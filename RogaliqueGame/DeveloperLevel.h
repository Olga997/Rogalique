#pragma once
#include <array>
#include <iostream>

#include "Floor.h"
#include "Music.h"
#include "Player.h"
#include "Scene.h"
#include "Spawner.h"
#include "Wall.h"

using namespace XYZEngine;

namespace RogaliqueGame {
class DeveloperLevel : public Scene {
   public:
    void Start() override;
    void Restart() override;
    void Stop() override;

    std::vector<std::unique_ptr<Wall>> walls;
    std::vector<std::unique_ptr<Floor>> floors;

   private:
    std::shared_ptr<Player> player;
    std::unique_ptr<Music> music;
};
}  // namespace RogaliqueGame
