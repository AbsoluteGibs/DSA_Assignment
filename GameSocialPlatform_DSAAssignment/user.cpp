#include "User.h"

User::User()
{
	name = "";
	bio = "";
	accountBalance = 0.0;
	friendsList = UserBinarySearchTree();
	userInvitations = UserBinarySearchTree();
	gameLibrary = GameBinarySearchTree();
}

User::User(std::string n, std::string b, float bal)
{
	name = n;
	bio = b;
	accountBalance = bal;
	friendsList = UserBinarySearchTree();
	userInvitations = UserBinarySearchTree();
	gameLibrary = GameBinarySearchTree();
}

bool User::purchaseGame(Game g)
{
	if (accountBalance < g.getPrice())
	{
		return false;
	}
	else
	{
		std::cout << "Successfully purchased '" << g.getName() << "'. Your game is added to your game library.";
		return true;
	}
}

void User::playGame(Game g)
{
	std::cout << "You are now playing: " << g.getName() << std::endl;
}

void User::browseGameLibrary()
{
	gameLibrary.display();
}

void User::browseFriends()
{
}

void User::editBio()
{
}

void User::messageFriend(User f)
{
}

void User::topUpBalance(double amt)
{
}

void User::addFriend(User u)
{
}

void User::acceptFriend()
{
}

void User::declineFriend()
{
}

