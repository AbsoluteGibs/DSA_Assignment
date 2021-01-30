#pragma once
#include "User.h"

struct Message
{
	User to;
	User from;
	std::string text;
};

struct ChatBubble
{
	User user;
	Message message;

	ChatBubble(){}

	// replace user into SYSTEM for system-generated messages
	ChatBubble(User u, Message m)
	{
		user = u;
		message = m;
	}

	~ChatBubble()
	{
		//deallocate user and message
		//delete object
	}
};