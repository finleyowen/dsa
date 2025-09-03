#ifndef __BTREE_HPP__
#define __BTREE_HPP__

#include <vector>
using namespace std;

template <typename T, unsigned int order>
class BTreeNode
{
private:
	vector<T> items;
	vector<BTreeNode<T, order> *> children;

public:
	BTreeNode() : items({}), children({}) {}
};

template <typename T, unsigned int order>
class BTree
{
private:
	BTreeNode<T, order> *root;

public:
	BTree() : root(nullptr) {}

	~BTree()
	{
		delete root;
	}
};

#endif