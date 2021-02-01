#include "UserBinarySearchTree.h"

UserBinarySearchTree::UserBinarySearchTree()
{
	root = NULL;
}

void UserBinarySearchTree::inorder()
{
	if (isEmpty())
		std::cout << "No item found" << std::endl;
	else
		inorder(root);
}

void UserBinarySearchTree::inorder(UserBinaryNode* t)
{
	if (t != NULL)
	{
		inorder(t->left);
		std::cout << t->item.getName() << std::endl;
		inorder(t->right);
	}
}

void UserBinarySearchTree::preorder()
{
	if (isEmpty())
		std::cout << "No item found" << std::endl;
	else
		preorder(root);
}

void UserBinarySearchTree::preorder(UserBinaryNode* t)
{
	if (t != NULL)
	{
		std::cout << t->item.getName() << std::endl;
		preorder(t->left);
		preorder(t->right);
	}
}

void UserBinarySearchTree::postorder()
{
	if (isEmpty())
		std::cout << "No item found" << std::endl;
	else
		postorder(root);
}

void UserBinarySearchTree::postorder(UserBinaryNode* t)
{
	if (t != NULL)
	{
		postorder(t->left);
		postorder(t->right);
		std::cout << t->item.getName() << std::endl;
	}
}

UserBinaryNode* UserBinarySearchTree::search(User target)
{
	return search(root, target);
}

UserBinaryNode* UserBinarySearchTree::search(UserBinaryNode* t, User target)
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

void UserBinarySearchTree::insert(User target)
{
	insert(root, target);
}

void UserBinarySearchTree::insert(UserBinaryNode*& t, User target)
{
	if (t == NULL)
	{
		UserBinaryNode* newNode = new UserBinaryNode;
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

void UserBinarySearchTree::remove(User target)
{
	remove(root, target);
	balanceTree(root);
}

void UserBinarySearchTree::remove(UserBinaryNode*& t, User target)
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
				UserBinaryNode* temp = t;
				t = NULL;
				delete temp;
			}
			//if node has one child
			else if (t->left == NULL)
			{
				UserBinaryNode* temp = t;
				if (t == root)
					root = t->right;
				else
					t = t->right;
				delete temp;
			}
			else if (t->right == NULL)
			{
				UserBinaryNode* temp = t;
				if (t == root)
					root = t->left;
				else
					t = t->left;
				delete temp;
			}
			//if node has 2 children
			else
			{
				UserBinaryNode* successor = t->left;
				while (successor->right != NULL)
					successor = successor->right;

				User item = successor->item;
				remove(t->left, item);
				t->item = item;
			}
		}
	}
}

bool UserBinarySearchTree::isEmpty()
{
	return root == NULL;
}

int UserBinarySearchTree::countNodes()
{
	int count = 0;
	if (!isEmpty())
	{
		count = countNodes(root);
	}

	return count;
}

int UserBinarySearchTree::countNodes(UserBinaryNode* t)
{
	int count = 1;

	if (t != NULL)
	{
		count += countNodes(t->left);
		count += countNodes(t->right);
	}

	return count;
}

int UserBinarySearchTree::getHeight()
{
	int h = 1;
	if (!isEmpty())
	{
		h += getHeight(root);
	}

	return h;
}

int UserBinarySearchTree::getHeight(UserBinaryNode* t)
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

bool UserBinarySearchTree::isBalanced()
{
	return isBalanced(root);
}

bool UserBinarySearchTree::isBalanced(UserBinaryNode* t)
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

void UserBinarySearchTree::display()
{
	inorder();
}