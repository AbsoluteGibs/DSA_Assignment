#pragma once
#include "User.h"

struct UserBinaryNode
{
	User item;
	UserBinaryNode* right;
	UserBinaryNode* left;
};

class UserBinarySearchTree
{
private:
	UserBinaryNode* root;

public:
	UserBinarySearchTree();

	//search
	UserBinaryNode* search(User target);
	UserBinaryNode* search(UserBinaryNode* t, User target);

	//insert
	void insert(User item);
	void insert(UserBinaryNode*& t, User item);

	//remove
	void remove(User target);
	void remove(UserBinaryNode*& t, User target);

	//traverse inorder
	void inorder();
	void inorder(UserBinaryNode* t);

	//traverse preorder
	void preorder();
	void preorder(UserBinaryNode* t);

	//traverse postorder
	void postorder();
	void postorder(UserBinaryNode* t);

	//check if binary search tree is empty
	bool isEmpty();

	//count number of nodes in binary search tree
	int countNodes();
	int countNodes(UserBinaryNode* t);

	//compute height of binary search tree
	int getHeight();
	int getHeight(UserBinaryNode* t);

	//check if binary search tree is balanced
	bool isBalanced();
	bool isBalanced(UserBinaryNode* t);

	void display();
};