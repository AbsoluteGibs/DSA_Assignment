#include "ChatBubble.h"

ChatBubble::ChatBubble()
{

}

ChatBubble::~ChatBubble()
{
	//deallocate user and message
	//delete object
}

ChatBubble::ChatBubble(User t, User f, std::string m)
{
	to = t;
	from = f;
	message = m;
}

//getters
std::string ChatBubble::getMessage() { return message; }
User ChatBubble::getSender() { return from; }
User ChatBubble::getRecipient() { return to; }