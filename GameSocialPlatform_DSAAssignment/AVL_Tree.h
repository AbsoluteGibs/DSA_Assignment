#pragma once
// AVL_Tree.h - AVL functions(Specification)
#pragma once
#include<iostream>
#include "UserBinaryNode.h"
#include "GameBinaryNode.h"

using namespace std;

template <typename Node>
void balanceTree(Node*& t);

// AVL Tree functions
template <typename Node>
Node* balance(Node* t);

template <typename Node>
Node* rotateLeft(Node* node);

template <typename Node>
Node* rotateRight(Node* node);

template <typename Node>
Node* rotateLeftRight(Node* node);

template <typename Node>
Node* rotateRightLeft(Node* node);

template <typename Node>
int diff(Node* t);

template <typename Node>
int getHeight(Node* t);