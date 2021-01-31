#include "UserMessageRecords.h"

UserMessageRecords::UserMessageRecords()
{
	firstNode = NULL;
	size = 0;
}

UserMessageRecords::~UserMessageRecords()
{
	delete firstNode;
	firstNode = NULL;
}

bool UserMessageRecords::add(Chat item)
{
	Node* newNode = new Node;

	newNode->item = item;
	newNode->next = NULL;

	if (isEmpty())
		firstNode = newNode;
	else
	{
		Node* current = firstNode;
		for (int i = 0; i < size - 1; i++)
		{
			current = current->next;
		}
		current->next = newNode;
	}

	size++;
	return true;
}

//only add chats into messageRecords when there isn't a chat open between the users
//use search function to loop through the records and look for said user
bool UserMessageRecords::add(int index, Chat item)
{
	if (index >= 0 && index < size)
	{
		Node* newNode = new Node;
		newNode->item = item;
		newNode->next = NULL;

		if (index == 0)
		{
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else
		{
			Node* current = firstNode;
			for (int i = 0; i < index - 1; i++)
			{
				current = current->next;
			}

			newNode->next = current->next;
			current->next = newNode;
		}

		size++;
		return true;
	}
	else
		return false;
}

void UserMessageRecords::remove(int index)
{
	if (index >= 0 && index < size)
	{
		Node* forwardNode;
		if (index == 0)
		{
			forwardNode = firstNode;
			firstNode = forwardNode->next;
		}
		else
		{
			Node* current = firstNode;
			forwardNode = current->next;
			for (int i = 0; i < index - 1; i++)
			{
				current = current->next;
				forwardNode = forwardNode->next;
			}
			current->next = forwardNode->next;
			delete forwardNode;
			forwardNode = NULL;
		}
		size--;
	}
}

Chat UserMessageRecords::get(int index)
{
	if (index >= 0 && index < size)
	{
		Node* current = firstNode;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->item;
	}
}

bool UserMessageRecords::isEmpty()
{
	if (size == 0)
		return true;
	return false;
}

int UserMessageRecords::getLength()
{
	return size;
}

void UserMessageRecords::print()
{
	Node* current;
	current = firstNode;
	//std::cout << current->user.getName() << "\t";

	while (current->next != NULL)
	{
		std::cout << current->user.getName() << "\t";
		current = current->next;
	}

	std::cout << std::endl;
}