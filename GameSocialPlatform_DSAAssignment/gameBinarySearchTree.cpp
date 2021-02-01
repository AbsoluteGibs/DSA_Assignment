#include "GameBinarySearchTree.h"

GameBinarySearchTree::GameBinarySearchTree()
{
	root = NULL;
}

void GameBinarySearchTree::inorder()
{
	if (isEmpty())
		std::cout << "No item found" << std::endl;
	else
		inorder(root);
}

void GameBinarySearchTree::inorder(GameBinaryNode* t)
{
	if (t != NULL)
	{
		inorder(t->left);
		std::cout << t->item.getName() << std::endl;
		inorder(t->right);
	}
}

void GameBinarySearchTree::preorder()
{
	if (isEmpty())
		std::cout << "No item found" << std::endl;
	else
		preorder(root);
}

void GameBinarySearchTree::preorder(GameBinaryNode* t)
{
	if (t != NULL)
	{
		std::cout << t->item.getName() << std::endl;
		preorder(t->left);
		preorder(t->right);
	}
}

void GameBinarySearchTree::postorder()
{
	if (isEmpty())
		std::cout << "No item found" << std::endl;
	else
		postorder(root);
}

void GameBinarySearchTree::postorder(GameBinaryNode* t)
{
	if (t != NULL)
	{
		postorder(t->left);
		postorder(t->right);
		std::cout << t->item.getName() << std::endl;
	}
}

GameBinaryNode* GameBinarySearchTree::search(Game target)
{
	return search(root, target);
}

GameBinaryNode* GameBinarySearchTree::search(GameBinaryNode* t, Game target)
{
	if (t == NULL)
		return NULL;
	else
	{
		if (t->item.getName() == target.getName())
			return t;
		else
		{
			if (target.getName() < t->item.getName())
				return search(t->left, target);
			else
				return search(t->right, target);
		}
	}
}

void GameBinarySearchTree::insert(Game target)
{
	insert(root, target);
}

void GameBinarySearchTree::insert(GameBinaryNode*& t, Game target)
{
	if (t == NULL)
	{
		GameBinaryNode* newNode = new GameBinaryNode;
		newNode->item = target;
		newNode->left = NULL;
		newNode->right = NULL;
		t = newNode;
	}
	else if (target.getName() < t->item.getName())
		insert(t->left, target);
	else
		insert(t->right, target);

	t = balance(t);
}

void GameBinarySearchTree::remove(Game target)
{
	remove(root, target);
	balanceTree(root);
}

void GameBinarySearchTree::remove(GameBinaryNode*& t, Game target)
{
	if (t != NULL)
	{
		if (target.getName() < t->item.getName())
			remove(t->left, target);
		else if (target.getName() > t->item.getName()) 
			remove(t->right, target);
		else //found node with same item val
		{
			//if node has no child
			if (t->left == NULL && t->right == NULL)
			{
				GameBinaryNode* temp = t;
				t = NULL;
				delete temp;
			}
			//if node has one child
			else if (t->left == NULL)
			{
				GameBinaryNode* temp = t;
				if (t == root)
					root = t->right;
				else
					t = t->right;
				delete temp;
			}
			else if (t->right == NULL)
			{
				GameBinaryNode* temp = t;
				if (t == root)
					root = t->left;
				else
					t = t->left;
				delete temp;
			}
			//if node has 2 children
			else
			{
				GameBinaryNode* successor = t->left;
				while (successor->right != NULL)
					successor = successor->right;

				Game item = successor->item;
				remove(t->left, item);
				t->item = item;
			}
		}
	}
}

bool GameBinarySearchTree::isEmpty()
{
	return root == NULL;
}

int GameBinarySearchTree::countNodes()
{
	int count = 0;
	if (!isEmpty())
	{
		count = countNodes(root);
	}

	return count;
}

int GameBinarySearchTree::countNodes(GameBinaryNode* t)
{
	int count = 1;

	if (t != NULL)
	{
		count += countNodes(t->left);
		count += countNodes(t->right);
	}

	return count;
}

int GameBinarySearchTree::getHeight()
{
	int h = 1;
	if (!isEmpty())
	{
		h += getHeight(root);
	}

	return h;
}

int GameBinarySearchTree::getHeight(GameBinaryNode* t)
{
	//or can use countNodes and plug a formula to determine the height

	int leftH = 0;
	int rightH = 0;

	if (t != NULL)
	{
		leftH += getHeight(t->left);
		rightH += getHeight(t->right);
		return (leftH > rightH ? leftH : rightH);
	}

	return 0;
}

bool GameBinarySearchTree::isBalanced()
{
	return isBalanced(root);
}

bool GameBinarySearchTree::isBalanced(GameBinaryNode* t)
{
	if (t != NULL)
	{
		return true;
	}

	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);

	if (abs(leftHeight - rightHeight) > 1)
		return false;

	return isBalanced(root->left) && isBalanced(root->right);
}

void GameBinarySearchTree::display()
{
	inorder();
}