#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int Data;
	struct Node* next;
};


//struct node* BuildOneTwoThree() {
//struct node* head = NULL;
//struct node* second = NULL;
//struct node* third = NULL;
//head = malloc(sizeof(struct node)); // allocate 3 nodes in the heap
//second = malloc(sizeof(struct node));
//third = malloc(sizeof(struct node));
//head->data = 1; // setup first node
//head->next = second; // note: pointer assignment rule
//second->data = 2; // setup second node
//second->next = third;
//third->data = 3; // setup third link
//third->next = NULL;
//// At this point, the linked list referenced by "head"
//// matches the list in the drawing.
//return head;
//}


struct Node* BuildOneTwoThree()
{
	struct Node* head = NULL;

	return head;
}

int main()
{
	struct Node* headPtr = NULL;
	printf("Hello World");
}

int Length(struct Node * list)
{
	int length = 0;

	struct Node * curr = list;

	while(curr != NULL)
	{
		curr = curr->next;
		length++;
	}

	return length;
}


void Display(struct Node * list)
{
	struct Node * curr = list;

	while(curr != NULL)
	{
		printf("%d -->", curr->Data);
		curr = curr->next;
	}
}

void Push(struct Node** headRef, int data)
{
	struct Node* newNode = malloc(sizeof(struct Node));
	
	newNode->Data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}
