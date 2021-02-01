#pragma once
#include <string>

class Game
{
private:
	int gameId;
	std::string name;
	std::string description;
	float price;
	
public:
	Game();
	Game(int gId, std::string n, std::string d, float p);
	~Game();

	// getters
	std::string getName();
	std::string getDescription();
	float getPrice();
};