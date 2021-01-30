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
	User u;
	Message mInstance;
};