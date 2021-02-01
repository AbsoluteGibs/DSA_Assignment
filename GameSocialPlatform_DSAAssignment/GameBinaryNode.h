#pragma once
#include "Game.h"

struct GameBinaryNode
{
	Game item;
	GameBinaryNode* right;
	GameBinaryNode* left;
};