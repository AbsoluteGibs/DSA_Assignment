#pragma once
#include "User.h"

class User;

struct UserBinaryNode
{
	User item;
	UserBinaryNode* right;
	UserBinaryNode* left;
};