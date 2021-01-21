#pragma once
#include "userBinaryNode.h"

class userBinarySearchTree
{
private:
	userBinaryNode* root;

public:
	userBinarySearchTree();

	//search
	userBinaryNode* search(user target);
	userBinaryNode* search(userBinaryNode* t, user target);

	//insert
	void insert(user item);
	void insert(userBinaryNode*& t, user item);

	//remove
	void remove(user target);
	void remove(userBinaryNode*& t, user target);

	//traverse inorder
	void inorder();
	void inorder(userBinaryNode* t);

	//traverse preorder
	void preorder();
	void preorder(userBinaryNode* t);

	//traverse postorder
	void postorder();
	void postorder(userBinaryNode* t);

	//check if binary search tree is empty
	bool isEmpty();

	//count number of nodes in binary search tree
	int countNodes();
	int countNodes(userBinaryNode* t);

	//compute height of binary search tree
	int getHeight();
	int getHeight(userBinaryNode* t);

	//check if binary search tree is balanced
	bool isBalanced();
	bool isBalanced(userBinaryNode* t);

	void display();
};
