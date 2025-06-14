﻿#include <SFML/Graphics.hpp>

#include "DeveloperLevel.h"
#include "Engine.h"
#include "LevelManager.h"
#include "Logger.h"
#include "Matrix2D.h"
#include "Player.h"
#include "ResourceSystem.h"

using namespace RogaliqueGame;

int main() {
    RenderSystem::Instance()->SetMainWindow(
        new sf::RenderWindow(sf::VideoMode(1280, 720), "XYZRoguelike"));

    ResourceSystem::Instance()->LoadTextureMap(
        "player", "Resources/Textures/Player.png", {48, 63}, 4, false);
    ResourceSystem::Instance()->LoadTextureMap(
        "AI", "Resources/Textures/Player.png", {48, 63}, 4, false);
    ResourceSystem::Instance()->LoadTextureMap(
        "level_floors", "Resources/Textures/Floor.png", {128, 128}, 1, false);
    ResourceSystem::Instance()->LoadTextureMap(
        "level_walls", "Resources/Textures/Wall.png", {128, 128}, 1, false);

    ResourceSystem::Instance()->LoadSound("music", "Resources/Music/Fon.wav");

    // Logger
    auto logger = std::make_shared<Logger>();
    logger->addSink(std::make_shared<ConsoleSink>());
    logger->addSink(std::make_shared<FileSink>("log.txt"));

    LoggerRegistry::getInstance().registerLogger("global", logger);
    LoggerRegistry::getInstance().setDefaultLogger(logger);
    //////////

    // make levels
    LevelManager& levelManager = LevelManager::Instance();

    auto level1 = std::make_shared<DeveloperLevel>(15, 15, 3, sf::Color::White);
    levelManager.AddLevel(level1);

    auto level2 = std::make_shared<DeveloperLevel>(20, 20, 5, sf::Color::Blue);
    levelManager.AddLevel(level2);

    auto level3 = std::make_shared<DeveloperLevel>(15, 15, 3, sf::Color::Red);
    levelManager.AddLevel(level3);

    levelManager.StartFirstLevel();

    Engine::Instance()->Run();

    return 0;
}
