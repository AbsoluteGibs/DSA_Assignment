#pragma once
#include "UserBinarySearchTree.h"
#include "GameBinarySearchTree.h"
#include "UserMessageRecords.h"

class User
{
private:
	std::string name;
	std::string bio;
	float accountBalance;
	UserBinarySearchTree friendsList;
	UserBinarySearchTree userInvitations; //accept/decline friend request
	GameBinarySearchTree gameLibrary;

	UserMessageRecords records;

	bool online; //true - online, false - offline

public:
	User();
	User(std::string n, std::string b, float bal);
	bool purchaseGame(Game g); //add a game into the game library, unless the game already exists in the library
	void playGame(Game g); //play a game to notify friends who are online
	void browseGameLibrary();
	void browseFriends(); //can add the following options: online friends only/all friends
	void editBio();
	void messageFriend(User f);
	void topUpBalance(double amt);
	void addFriend(User u); //add invitation to the other user's list
	void acceptFriend(); //add both users into respective friends list, delete invitation
	void declineFriend(); //delete invitation

	// getters
	std::string getName() { return name; }
	std::string getBio() { return bio; }
	UserBinarySearchTree getFriendsList() { return friendsList; }
};

#pragma once