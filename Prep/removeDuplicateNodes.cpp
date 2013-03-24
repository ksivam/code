//#include <stdio.h>
//#include "Node.h"
//
//Node* generateLinkedList()
//{
//	Node* node1 = new Node(2);
//	Node* node2 = new Node(3);
//	Node* node3 = new Node(2);
//	Node* node4 = new Node(2);
//
//	node1->right = node2;
//	node2->right = node3;
//	node3->right = node4;
//
//	return node1;
//}
//
//void removeDuplicateNodes(Node* head)
//{
//	Node* currentNode = head;
//	while(currentNode != nullptr)
//	{
//		int currentValue = currentNode->item;
//		Node* previousNode = currentNode;
//		Node* currentNode1 = currentNode->right;
//		while(currentNode1 != nullptr)
//		{
//			if(currentValue == currentNode1->item)
//			{
//				// remove duplicate node
//				previousNode->right = currentNode1->next;
//			}
//			else
//			{
//				// move to next node
//				previousNode = currentNode1;
//			}
//			currentNode1 = currentNode1->right;
//		}
//		currentNode = currentNode->right;
//	}
//}
//
////
////void main(int argc, char* argv[])
////{
////	Node* head = generateLinkedList();
////
////	removeDuplicateNodes(head);
////
////	printList(head);
////
////	getchar();
////}
//
