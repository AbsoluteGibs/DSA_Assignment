#include "Game.h"

Game::Game()
{
	gameId = -1;
	name = "";
	description = "";
	price = 0.0;
}

Game::Game(int gId, std::string n, std::string d, float p)
{
	gameId = gId;
	name = n;
	description = d;
	price = p;
}

Game::~Game() {}

std::string Game::getName() { return name; }
std::string Game::getDescription() { return description; }
float Game::getPrice() { return price; }