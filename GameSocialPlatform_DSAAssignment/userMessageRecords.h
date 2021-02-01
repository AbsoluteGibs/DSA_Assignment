#pragma once
#include "Chat.h"

// LINKED LIST (Doubly maybe?)
class User;

class UserMessageRecords
{
private:
	struct Node
	{
		User user; // another user the current user is talking to
		Chat item;	// data item
		Node* next;	// pointer pointing to next item
	};

	Node* firstNode;	// point to the first item
	int size = 0;		// number of items in the List

public:
	UserMessageRecords();
	~UserMessageRecords();

	// pre : size < MAX_SIZE
	// post: item is added to the back of the List
	//       size of List is increased by 1
	bool add(Chat item);

	// add an item at a specified position in the List (insert)
	// pre : 0 <= index <= size
	// post: item is added to the specified position in the List
	//       items after the position are shifted back by 1 position
	//       size of List is increased by 1
	bool add(int index, Chat item);

	// remove an item at a specified position in the List
	// pre : 0 <= index < size
	// post: item is removed the specified position in the List
	//       items after the position are shifted forward by 1 position
	//       size of List is decreased by 1
	void remove(int index);

	// get an item at a specified position of the List (retrieve)
	// pre : 0 <= index < size
	// post: none
	// return the item in the specified index of the List
	Chat get(int index);

	// check if the List is empty
	// pre : none
	// post: none
	// return true if the List is empty; otherwise returns false
	bool isEmpty();

	// check the size of the List
	// pre : none
	// post: none
	// return the number of items in the List
	int getLength();

	//------------------- Other useful functions -----------------

	// display the items in the List
	void print();

	// void replace(int index, Chat item);
	// int search(Chat item);
};