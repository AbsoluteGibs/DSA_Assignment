#pragma once

#include "gameBinarySearchTree.h"
#include "userBinarySearchTree.h"

static class platform
{

public:
	gameBinarySearchTree storeGames; // all games in the platform store
	userBinarySearchTree userBase; // our "database" for all users in the platform

	void initialize(); // initialize platform with hardcoded games and users. to be placed in GameSocialPlatform_DSAAssignment.cpp.
};