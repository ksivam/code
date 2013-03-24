//#include "IList.h"
//
//
//Node<int>* BuildTree()
//{
//	Node<int>* head = new Node<int>(1);
//	Node<int>* n1 = new Node<int>(2);
//	Node<int>* n2 = new Node<int>(3);
//	Node<int>* n3 = new Node<int>(4);
//	Node<int>* n4 = new Node<int>(5);
//	Node<int>* n5 = new Node<int>(6);
//	Node<int>* n6 = new Node<int>(7);
//	Node<int>* n7 = new Node<int>(8);
//	Node<int>* n8 = new Node<int>(9);
//	Node<int>* n9 = new Node<int>(10);
//	Node<int>* n10 = new Node<int>(11);
//	Node<int>* n11 = new Node<int>(12);
//	Node<int>* n12 = new Node<int>(13);
//	Node<int>* n13 = new Node<int>(14);
//	Node<int>* n14 = new Node<int>(15);
//
//	head->left = n1;
//	head->right = n2;
//
//	n1->left = n3;
//	n1->right = n4;
//
//	n2->left = n5;
//	n2->right = n6;
//
//	n3->left = n7;
//	n3->right = n8;
//
//	n4->left = n9;
//	n4->right = n10;
//
//	n5->left = n11;
//	n5->right = n12;
//
//	n6->left = n13;
//	n6->right = n14;
//
//
//	return head;
//}
//
///*
//
//printList
//-------------------------
//| 0	| 1	| 2	| 3	| 4	| 5	|
//-------------------------
//even index: Queue
//odd index: Stack
//
//Stack, Queue :- contains inserted items
//
//*/
//
//Node<IList<int>*>* BFS(Node<int>* node)
//{
//	Node<IList<int>*>* printResultHead;
//	Node<IList<int>*>* currentPrintResult;
//	bool leftToRightToggle = false;
//	Queue<int>* q = new Queue<int>();
//	node->visited = true;
//	q->insert(node);
//	q->insert(new Node<int>(-1)); // new line
//
//	// create print list
//	IList<int>* printList = new Queue<int>();
//	printResultHead = new Node<IList<int>*>(printList);
//	currentPrintResult = printResultHead;
//
//	while(!q->IsEmpty())
//	{
//		Node<int>* n = q->top();
//		if(n->item == -1) // new line
//		{
//			//printf("\n");			
//			if(!q->IsEmpty())
//			{
//				q->insert(new Node<int>(-1)); // new line
//			}
//
//			if(leftToRightToggle)
//			{
//				// create queue
//				printList = new Queue<int>();
//				leftToRightToggle = false;
//			}
//			else
//			{
//				// create stack
//				printList = new Stack<int>();
//				leftToRightToggle = true;
//			}
//			currentPrintResult->right = new Node<IList<int>*>(printList); 
//			currentPrintResult = currentPrintResult->right;
//		}
//		else
//		{
//			//printf("%d ", n->item);
//			// add to print list
//			printList->insert(n);
//
//			// visit all edges of the current Node<int>
//			if(n->left != nullptr && !n->left->visited)
//			{
//				// check left sub tree
//				n->left->visited = true;
//				q->insert(n->left);	
//			} 
//			if(n->right != nullptr && !n->right->visited)
//			{
//				//check right sub tree
//				n->right->visited = true;
//				q->insert(n->right);
//			}
//		}
//	}
//
//	return printResultHead;
//}
//
//
//void main(int argc, char* argv[])
//{
//	Node<int>* head = BuildTree();
//
//	Node<IList<int>*>* print = BFS(head);
//
//	Node<IList<int>*>* current = print;
//	while(current != nullptr)
//	{
//
//		IList<int>* item = current->item;
//		while(!item->IsEmpty())
//		{
//		 	Node<int>* node = item->top();
//			printf("%d ", node->item);
//		}
//		printf("\n");
//		current = current->right;
//	}
//
//	getchar();
//}