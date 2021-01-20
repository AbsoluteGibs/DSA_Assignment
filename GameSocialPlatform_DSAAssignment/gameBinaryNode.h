#pragma once
#include <string>

struct game
{
	std::string name;
	std::string description;
	double price;
};

struct gameBinaryNode
{
	game item;
	gameBinaryNode* right;
	gameBinaryNode* left;
};