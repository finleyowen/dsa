#ifndef __AVL_HPP__
#define __AVL_HPP__

#include "bst.hpp"

/// @brief Represents an AVL tree. Extends the `BST` class.
/// @tparam T The data type of the data items stored on the tree.
template <typename T>
struct AVL : public BST<T>
{
	/// @brief Overridden insertion method to ensure tree is AVL-
	/// balanced after the insertion.
	/// @param data
	void insert(T data) override
	{
		BST<T>::insert(data);
		BST<T>::avl_balance();
	}
};

#endif