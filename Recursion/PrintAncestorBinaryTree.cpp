#include "PrintAncestorBinaryTree.h"

void main(int argc, char* argv[])
{
	Node<int>* head = BuildTree();

	PrintAncestorBinaryTree<int>* ancestor = new PrintAncestorBinaryTree<int>(7);

	ancestor->PrintAncestor(head);

	getchar();
}
