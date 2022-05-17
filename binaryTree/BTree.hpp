#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <iostream>

template<typename T>
struct TreeNode
{
	T value;
	TreeNode* left;
	TreeNode* right;
};

template<typename T>
class BTree
{
public:
	BTree();
	virtual ~BTree();
public:
	static TreeNode<T>* createNode(T value);
	static void insertNode(TreeNode<T>* parent, TreeNode<T>* left, TreeNode<T>* right);
	static void preOrderTraversal(TreeNode<T>* root);
	static void midOrderTraversal(TreeNode<T>* root);
	static void lastOrderTraversal(TreeNode<T>* root);
	static void preOrderTraversalByStack(TreeNode<T>* root);
	static void midOrderTraversalByStack(TreeNode<T>* root);
	static void lastOrderTraversalByStack(TreeNode<T>* root);
	static int getTotal(TreeNode<T>* root);
	static void releaseTree(TreeNode<T>* root);
	static void printNode(TreeNode<T>* node);

	void insert(T value, TreeNode<T>* left, TreeNode<T>* right);
private:
	TreeNode<T>* m_binaryTree;
};

template<typename T>
int BTree<T>::getTotal(TreeNode<T>* root)
{
	if (nullptr == root) {
		return 0;
	}
	return (getTotal(root->left) + getTotal(root->right) + 1);
}

template<typename T>
void BTree<T>::lastOrderTraversalByStack(TreeNode<T>* root)
{
}

template<typename T>
void BTree<T>::midOrderTraversalByStack(TreeNode<T>* root)
{
}

template<typename T>
void BTree<T>::preOrderTraversalByStack(TreeNode<T>* root)
{
}

template<typename T>
void BTree<T>::releaseTree(TreeNode<T>* root)
{
	if (nullptr == root) {
		return;
	}
	releaseTree(root->left);
	releaseTree(root->right);
	std::cout << "delete " << root->value << std::endl;
	delete root;
}

template<typename T>
void BTree<T>::lastOrderTraversal(TreeNode<T>* root)
{
	if (nullptr == root) {
		return;
	}
	lastOrderTraversal(root->left);
	lastOrderTraversal(root->right);
	printNode(root);
}

template<typename T>
void BTree<T>::midOrderTraversal(TreeNode<T>* root)
{
	if (nullptr == root) {
		return;
	}
	midOrderTraversal(root->left);
	printNode(root);
	midOrderTraversal(root->right);
}

template<typename T>
void BTree<T>::preOrderTraversal(TreeNode<T>* root)
{
	if (nullptr == root) {
		return;
	}
	printNode(root);
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

template<typename T>
void BTree<T>::printNode(TreeNode<T>* node)
{
	if (nullptr == node) {
		return;
	}
	std::cout << node->value << "\t";
}

template<typename T>
void BTree<T>::insertNode(TreeNode<T>* parent, TreeNode<T>* left, TreeNode<T>* right)
{
	parent->left = left;
	parent->right = right;
}

template<typename T>
TreeNode<T>* BTree<T>::createNode(T value)
{
	TreeNode<T>* node = new TreeNode<T>;
	node->value = value;
	node->left = nullptr;
	node->right = nullptr;

	return node;
}

template<typename T>
void BTree<T>::insert(T value, TreeNode<T>* left, TreeNode<T>* right)
{
}

template<typename T>
BTree<T>::~BTree()
{
}

template<typename T>
BTree<T>::BTree()
{
	m_binaryTree = new TreeNode<T>;
}

#endif // !_BINARYTREE_H