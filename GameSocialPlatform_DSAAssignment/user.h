#pragma once
#include "userBinarySearchTree.h"
#include "gameBinarySearchTree.h"
#include "userMessageRecords.h"

class User
{
private:
	std::string name;
	std::string bio;
	double accountBalance;
	UserBinarySearchTree friendsList;
	UserBinarySearchTree userInvitations; //accept/decline friend request
	GameBinarySearchTree gameLibrary;

	// this will be a dictionary, with the key being another user, and the value being a message record (to, from, message)
	// I'll let you handle these zech, can refer to dictionary practical, stacks can be used to undo message
	UserMessageRecords records;

	bool online; //true - online, false - offline

public:
	User();
	void purchaseGame(); //add a game into the game library, unless the game already exists in the library
	void playGame(); //play a game to notify friends who are online
	void browseGameLibrary();
	void browseFriends(); //can add the following options: online friends only/all friends
	void editBio();
	void messageFriend(); //creates a message 'record' between 1 user and another, only from friends in friends list
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