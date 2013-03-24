//#include "TreeListRecursion.h"
//
//
//void main(int argc, char* argv[])
//{
//	TreeListRecurion<int>* r = new TreeListRecurion<int>();
//
//	BST<int>* tree = new BST<int>();
//	tree->insert(&tree->Root, 0);
//	tree->insert(&tree->Root, 2);
//	tree->insert(&tree->Root, 3);
//	tree->insert(&tree->Root, 1);
//	tree->insert(&tree->Root, 5);
//	tree->insert(&tree->Root, 0);
//
//	r->TreeToList(tree->Root);
//
//	r->Head->left = r->Tail;
//	r->Tail->right = r->Head;
//
//	getchar();
//}
