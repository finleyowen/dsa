#ifndef __AVL_HPP__
#define __AVL_HPP__

#include "bst.hpp" // for BST, CHECK_ALLOC

/// @brief Represents an AVL tree. Extends the `BST` class.
/// @tparam T The data type of the data items stored on the tree.
template <typename T>
class AVL : public BST<T>
{
public:
	/// @brief Overridden insertion method to ensure tree is AVL-
	/// balanced after the insertion.
	/// @param data Data to insert onto the tree.
	void insert(T data) override
	{
		BST<T>::insert(data);
		BST<T>::avl_balance();
	}
};

#endif