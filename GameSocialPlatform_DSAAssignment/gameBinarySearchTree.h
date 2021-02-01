#pragma once
#include <string>
#include <iostream>
#include "AVL_Tree.h"

class GameBinarySearchTree
{
private:
	GameBinaryNode* root;

public:
	GameBinarySearchTree();

	// to compute which of the 2 is more "alphabetically forward", with A < Z. Returns true if target > result.
	// bool isAlphabeticallyForward(std::string result, std::string target);

	//search
	GameBinaryNode* search(Game target);
	GameBinaryNode* search(GameBinaryNode* t, Game target);

	//insert
	void insert(Game item);
	void insert(GameBinaryNode*& t, Game item);

	//remove
	void remove(Game target);
	void remove(GameBinaryNode*& t, Game target);

	//traverse inorder
	void inorder();
	void inorder(GameBinaryNode* t);

	//traverse preorder
	void preorder();
	void preorder(GameBinaryNode* t);

	//traverse postorder
	void postorder();
	void postorder(GameBinaryNode* t);

	//check if binary search tree is empty
	bool isEmpty();

	//count number of nodes in binary search tree
	int countNodes();
	int countNodes(GameBinaryNode* t);

	//compute height of binary search tree
	int getHeight();
	int getHeight(GameBinaryNode* t);

	//check if binary search tree is balanced
	bool isBalanced();
	bool isBalanced(GameBinaryNode* t);

	void display();
};