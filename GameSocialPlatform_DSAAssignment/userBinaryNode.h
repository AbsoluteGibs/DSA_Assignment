#pragma once
#include "user.h"
#include <string>

struct userBinaryNode
{
	user item;
	userBinaryNode* right;
	userBinaryNode* left;
};