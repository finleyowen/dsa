#ifndef __BST_HPP__
#define __BST_HPP__

#include "check_alloc.hpp" // for CHECK_ALLOC

/// @brief Represents a node in a Binary Search Tree (BST).
/// @tparam T The data type stored in the BST.
template <typename T>
class BSTNode
{
private:
	/// @brief Data item stored in the node.
	T data;

	/// @brief Pointers to the left and right subtrees.
	BSTNode<T> *left, *right;

	/// @brief Pointer to the parent node.
	BSTNode<T> *parent;

	/// @brief Perform an AVL left-rotation on this node and
	/// its right child.
	void avl_rotate_l()
	{
		BSTNode *right_left = right->left;

		right->parent = parent;
		right->left = this;
		right = right_left;
		parent = right;
		right_left->parent = this;
	}

	/// @brief Perform an AVL right-rotation on this node and
	/// its left child.
	void avl_rotate_r()
	{
		BSTNode *left_right = left->right;

		left->parent = parent;
		left->right = this;
		left = left_right;
		parent = left;
		left_right->parent = this;
	}

	/// @brief Search for a data item at this node and the ones below it.
	/// @param data Data item to search for.
	/// @return The matching node if one was found, else `nullptr`.
	BSTNode<T> *find(T data)
	{
		// data > this->data => search right
		if (data > this->data)
		{
			if (right)
				return right->find(data);
			else
				return nullptr;
		}

		// data < this->data => search left
		else if (data < this->data)
		{
			if (left)
				return left->find(data);
			else
				return nullptr;
		}

		// data == this.data
		return this;
	}

public:
	/// @brief Create a new node.
	/// @param data Data to store in the node.
	BSTNode(T data) : data(data), left(nullptr), right(nullptr) {}

	/// @brief Insert a node underneath this one in the tree.
	/// @param data Data to insert into the tree.
	virtual void insert(T data)
	{
		// insert left
		if (data < this->data)
		{
			if (left)
				left->insert(data);
			else
			{
				left = new BSTNode(data);
				CHECK_ALLOC(left);
			}
		}

		// insert right
		else if (data > this->data)
		{
			if (right)
				right->insert(data);
			else
			{
				right = new BSTNode(data);
				CHECK_ALLOC(right);
			}
		}
	}

	/// @brief Search for a data item at this node and the ones below it.
	/// @param data Data item to search for.
	/// @return Boolean indicating whether the data was found on the tree..
	bool contains(T data)
	{
		BSTNode<T> *node = find(data);
		return node != nullptr;
	}

	/// @brief Get the height below this node.
	/// @return The height below this node. May be 0.
	unsigned int height_below()
	{
		unsigned int lh = left ? left->height_below() : 0;
		unsigned int rh = right ? right->height_below() : 0;

		// special case: leaf node, no height below.
		if (lh == 0 && rh == 0)
		{
			return 0;
		}

		return 1 + (lh > rh ? lh : rh);
	}

	/// @brief Get the AVL balance factor of this node.
	/// @return The AVL balance factor of this node. Should be
	/// greater than 1 when tree is left-heavy, less than -1 when
	/// tree is right-heavy, between -1 and 1 when tree is balanced.
	int avl_balance_factor()
	{
		unsigned int lh = left ? left->height_below() : 0;
		unsigned int rh = right ? right->height_below() : 0;

		return lh - rh;
	}

	/// @brief Perform AVL rotations on the node until it is balanced.
	void avl_balance()
	{
		// balance subtrees first if they exist
		if (left)
			left->avl_balance();
		if (right)
			right->avl_balance();

		// balance this node
		int bf;
		do
		{
			bf = avl_balance_factor();
			if (bf > 1)
				avl_rotate_l();
			else if (bf < -1)
				avl_rotate_r();
		} while (bf > 1 || bf < -1);
	}

	/// @brief Free the node's children before freeing the node.
	virtual ~BSTNode()
	{
		delete left;
		delete right;
	}
};

/// @brief Represents a Binary Search Tree (BST).
/// @tparam T The data type stored in the BST.
template <typename T>
class BST
{
private:
	/// @brief Root node of the BST.
	BSTNode<T> *root;

public:
	/// @brief Create a new, empty BST.
	BST() : root(nullptr) {}

	/// @brief Get the root node of the tree.
	/// @return The root node of the tree. May be `nullptr`.
	BSTNode<T> *get_root()
	{
		return root;
	}

	/// @brief Insert an item into this BST.
	/// @param data Data item to insert.
	virtual void insert(T data)
	{
		// tree is already non-empty
		if (root)
			root->insert(data);

		// tree is currently empty
		else
		{
			root = new BSTNode(data);
			CHECK_ALLOC(root);
		}
	}

	/// @brief Search for an item in this BST.
	/// @param data The item to search for.
	/// @return Indicates whether the item was found.
	bool contains(T data)
	{
		// tree not empty
		if (root)
			return root->contains(data);
		// tree empty
		else
			return false;
	}

	/// @brief Perform AVL rotations on the tree until it's balanced.
	void avl_balance()
	{
		if (root)
			root->avl_balance();
	}

	/// @brief Free the nodes before freeing the tree.
	virtual ~BST()
	{
		delete root;
	}
};

#endif