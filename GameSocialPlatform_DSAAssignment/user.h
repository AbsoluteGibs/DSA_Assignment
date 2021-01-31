#pragma once
#include "userBinarySearchTree.h"
#include "gameBinarySearchTree.h"
#include "userMessageRecords.h"
#include "Game.h"
#include <list>
using namespace std;


class User
{
private:
	string bio;
	string name;
	bool online;					//true - online, false - offline
	string password;
	float accountBalance;

	userBinarySearchTree friendsList;
	userBinarySearchTree userInvitations;	//accept/decline friend request
	gameBinarySearchTree gameLibrary;

	// this will be a dictionary, with the key being another user, and the value being a message record (to, from, message)
	// I'll let you handle these zech, can refer to dictionary practical, stacks can be used to undo message
	userMessageRecords records;


public:
	User();
	User (string n, string b, string p);

	void editBio();
	void viewProfile ();
	
	// Basic getters
	float getBalance ();
	string getName ();
	string getBio ();

	//Game related 
	void purchaseGame(Game g);		//add a game into the game library, unless the game already exists in the library
	void playGame();				//play a game to notify friends who are online
	void browseGameLibrary();
	
	// Balance related
	void topUpBalance(float amt);

	// Friend related
	void acceptFriend();			//add both users into respective friends list, delete invitation
	void messageFriend();			//creates a message 'record' between 1 user and another, only from friends in friends list
	void browseFriends();			//can add the following options: online friends only/all friends
	void declineFriend();			//delete invitation
	void addFriend(User u);			//add invitation to the other user's list
};

#pragma once