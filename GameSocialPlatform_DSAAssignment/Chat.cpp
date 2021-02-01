#include "Chat.h"

bool Chat::push(ChatBubble item)
{
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	if (isEmpty())
	{
		topNode = newNode;
	}
	else
	{
		newNode->next = topNode;
		topNode = newNode;
	}

	return true;
}

bool Chat::pop()
{
	if (!isEmpty())
	{
		Node* tempNode = topNode;
		topNode = topNode->next;

		delete tempNode;
		tempNode = NULL;
	}

	return true;
}

bool Chat::pop(ChatBubble& item)
{
	if (!isEmpty())
	{
		Node* tempNode = topNode;
		item = topNode->item;
		topNode = topNode->next;

		delete tempNode;
		tempNode = NULL;

		return true;
	}
	return false;
}

ChatBubble Chat::getTop()
{
	if (!isEmpty())
		return topNode->item;

	//return NULL;
	//^maybe return a message that says "You have not started a conversation with this user." or something
}

bool Chat::isEmpty()
{
	if (topNode == NULL)
		return true;
	else
		return false;
}

void Chat::displayInOrder()
{
	Node* current = topNode;

	while (current != NULL)
	{
		std::cout << current->item.getMessage() << "\t";
		current = current->next;
	}

	std::cout << std::endl;

}

// display messages, including system-generated messages

void Chat::displayInOrderOfInsertion()
{
	Chat temp;
	while (!isEmpty())
	{
		ChatBubble item;
		pop(item);
		temp.push(item);
	}

	temp.displayInOrder();

	while (!temp.isEmpty())
	{
		ChatBubble item;
		temp.pop(item);
		push(item);
	}
}

// recursion ? (for reference sake)
void Chat::printForward() { printForward(topNode); std::cout << std::endl; }
void Chat::printForward(Node* temp)
{
	if (temp != NULL)
	{
		printForward(temp->next);
		std::string senderName = temp->item.getSender().getName();
		std::string recipientName = temp->item.getRecipient().getName();
		std::string message = temp->item.getMessage();

		if (senderName == temp->user.getName())
		{
			std::cout << senderName << " ::> " << message << "\t";
		}
		else
		{
			std::cout << message << " <:: " << recipientName << "\t";
		}
	}
}