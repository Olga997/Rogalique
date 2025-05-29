#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Engine.h"
#include "ResourceSystem.h"
#include "DeveloperLevel.h"
#include "Matrix2D.h"

using namespace RogaliqueGame;

int main()
{
	RenderSystem::Instance()->SetMainWindow(new sf::RenderWindow(sf::VideoMode(1280, 720), "XYZRoguelike"));

	ResourceSystem::Instance()->LoadTextureMap("player", "Resources/Textures/Player.png", { 48, 63 }, 4, false);
	ResourceSystem::Instance()->LoadTextureMap("AI", "Resources/Textures/Player.png", { 48, 63 }, 4, false);
	ResourceSystem::Instance()->LoadTextureMap("level_floors", "Resources/Textures/Floor.png", { 128, 128 }, 1, false);
	ResourceSystem::Instance()->LoadTextureMap("level_walls", "Resources/Textures/Wall.png", { 128, 128 }, 1, false);

	ResourceSystem::Instance()->LoadSound("music", "Resources/Music/Fon.wav");

	auto developerLevel = std::make_shared<DeveloperLevel>();
	developerLevel->Start();

	Engine::Instance()->Run();

	return 0;
}
