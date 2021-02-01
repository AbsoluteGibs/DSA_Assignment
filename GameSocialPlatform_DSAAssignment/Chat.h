#pragma once
#include <iostream>
#include "ChatBubble.h"

// STACK DATA STRUCTURE

class User;

class Chat
{
private:
	struct Node
	{
		User user;
		ChatBubble item;
		Node* next;
	};

	Node* topNode;


public:
	Chat() { topNode = NULL; }		// constructor
	~Chat() { while (topNode != NULL) { pop(); } }		// destructor

	bool push(ChatBubble item);
	bool pop();
	bool pop(ChatBubble& item);
	ChatBubble getTop(); //get latest message
	bool isEmpty();
	void displayInOrder();
	void displayInOrderOfInsertion();
	void printForward();
	void printForward(Node* temp);
};