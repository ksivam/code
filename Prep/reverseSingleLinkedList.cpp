//#include "Node.h"
//
//Node* generateLinkedList()
//{
//	Node* node1 = new Node(1);
//	//Node* node2 = new Node(2);
//	//Node* node3 = new Node(3);
//	//Node* node4 = new Node(4);
//
//	//node1->right = node2;
//	//node2->right = node3;
//	//node3->right = node4;
//
//	return node1;
//}
//
//void reverseSingleLinkedList(Node **head)
//{
//	Node* currentNode = *head;
//	Node* previousNode = nullptr;
//
//	while(currentNode != nullptr)
//	{
//		Node* nextNode = currentNode->right;
//		currentNode->right = previousNode;
//		previousNode = currentNode;
//		currentNode = nextNode;
//	}
//
//	*head = previousNode;
//}
//
//void main(int argc, char* argv[])
//{
//	Node* head = generateLinkedList();
//
//	reverseSingleLinkedList(&head);
//
//	printList(head);
//
//	getchar();
//}
