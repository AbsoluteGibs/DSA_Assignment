#pragma once
#include "gameBinaryNode.h"

class gameBinarySearchTree
{
private:
	gameBinaryNode* root;

public:
	gameBinarySearchTree();

	//search
	gameBinaryNode* search(game target);
	gameBinaryNode* search(gameBinaryNode* t, game target);

	//insert
	void insert(game item);
	void insert(gameBinaryNode*& t, game item);

	//remove
	void remove(game target);
	void remove(gameBinaryNode*& t, game target);

	//traverse inorder
	void inorder();
	void inorder(gameBinaryNode* t);

	//traverse preorder
	void preorder();
	void preorder(gameBinaryNode* t);

	//traverse postorder
	void postorder();
	void postorder(gameBinaryNode* t);

	//check if binary search tree is empty
	bool isEmpty();

	//count number of nodes in binary search tree
	int countNodes();
	int countNodes(gameBinaryNode* t);

	//compute height of binary search tree
	int getHeight();
	int getHeight(gameBinaryNode* t);

	//check if binary search tree is balanced
	bool isBalanced();
	bool isBalanced(gameBinaryNode* t);

	void display();
};