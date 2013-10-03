#include "Node.h"

// Using Recursion
Node<int>* FindCommonParent(Node<int>* root, Node<int>* node1, Node<int>* node2)
{
	// base condition
	if(root == nullptr)
		return nullptr;

	// if node1 or node2 is root, then root is the common ancestor.
	if(root == node1 || root == node2)
	{
		return root;
	}

	// traverse down the left subtree and find the common ancestor
	Node<int>* left = FindCommonParent(root->left, node1, node2);

	// traverse down the right subtree and find the common ancestor
	Node<int>* right = FindCommonParent(root->right, node1, node2);

	// root is the common ancestor if node1 or node2 is 
	// present in left subree and node1 or node2 is present 
	// in right subtree
	if(left != nullptr && right != nullptr)
	{
		return root;
	}
	else
	{
		// else, left is the common ancestor is its not null 
		// and right is the common ancestor if its not null
		return (left != nullptr) ? left : right;
	}
}

void main(int argc, char* argv[])
{
	Node<int>* head = new Node<int>(0);
	Node<int>* n1 = new Node<int>(1);
	Node<int>* n2 = new Node<int>(2);
	Node<int>* n3 = new Node<int>(3);
	Node<int>* n4 = new Node<int>(4);
	Node<int>* n5 = new Node<int>(5);


	head->left = n1;
	head->right = n2;

	n1->left = n3;
	n1->right = n4;

	n4->left = n5;

	Node<int>* result = FindCommonParent(head, n5, n2);

	printf("Common ancestor: %d", result->item);
	getchar();
}
