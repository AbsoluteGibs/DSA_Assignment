#pragma once

#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include "GameBinarySearchTree.h"
#include "UserBinarySearchTree.h"

static class Platform
{

public:
	static GameBinarySearchTree storeGames; // all games in the platform store
	static UserBinarySearchTree userBase; // our "database" for all users in the platform

	static void initialize() // initialize platform with hardcoded games and users. to be placed in GameSocialPlatform_DSAAssignment.cpp.
	{
		std::ifstream infile("initList.txt");
		storeGames = GameBinarySearchTree();
		userBase = UserBinarySearchTree();

		int i = 0;
		std::string gameName, userName;
		while (infile >> gameName >> userName)
		{
			srand(time(NULL));

			// replace $ with spacebar character
			std::replace(gameName.begin(), gameName.end(), '$', ' ');
			std::replace(userName.begin(), userName.end(), '$', ' ');

			// games can range from $5 to $25
			Game game = Game(i, gameName, "description" + to_string(i), (float)(rand() % 21 + 5));

			// user created with each starting off with 0 balance
			User user = User(userName, "userBio" + to_string(i), 0.00);

			storeGames.insert(game);
			userBase.insert(user);
			i++;
		}

		std::cout << "Initialization Finished." << std::endl;
	}
};