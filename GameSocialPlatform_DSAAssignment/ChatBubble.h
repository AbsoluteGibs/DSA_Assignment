#pragma once
#include "User.h"

class ChatBubble
{
private:
	User to;
	User from;
	std::string message;

public:
	ChatBubble();
	~ChatBubble();

	// replace user into SYSTEM for system-generated messages
	ChatBubble(User t, User f, std::string m);

	//getters
	std::string getMessage();
	User getSender();
	User getRecipient();
};