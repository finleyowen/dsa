#ifndef __AVL_HPP__
#define __AVL_HPP__

#include "bst.hpp"

template <typename T>
struct AVL : public BST<T>
{
	void insert(T data) override
	{
		BST<T>::insert(data);
		BST<T>::avl_balance();
	}
};

#endif