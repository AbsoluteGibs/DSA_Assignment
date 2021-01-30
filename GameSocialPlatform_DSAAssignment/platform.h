#pragma once

#include "GameBinarySearchTree.h"
#include "UserBinarySearchTree.h"

static class platform
{

public:
	GameBinarySearchTree storeGames; // all games in the platform store
	UserBinarySearchTree userBase; // our "database" for all users in the platform

	void initialize(); // initialize platform with hardcoded games and users. to be placed in GameSocialPlatform_DSAAssignment.cpp.
};