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
    DeveloperLevel(int width, int height, int enemyCount, sf::Color levelColor) ;
    void Start() override;
    void Restart() override;
    void Stop() override;
    bool IsPlayerAtExit() const;
    void Update(float deltaTime);

    std::vector<std::unique_ptr<Wall>> walls;
    std::vector<std::unique_ptr<Floor>> floors;

   private:
    int width_ = 0;
    int height_ = 0;
    int enemyCount_ = 0;
    sf::Color levelColor_;
    std::shared_ptr<Player> player;
    std::unique_ptr<Music> music;

};
}  // namespace RogaliqueGame
