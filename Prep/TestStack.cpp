//#include "Stack.h"
//
//IList* BuildStack()
//{
//	IList* s = new Stack();
//	s->insert(new Node(1));
//	s->insert(new Node(2));
//	s->insert(new Node(3));
//	s->insert(new Node(4));
//	s->insert(new Node(5));
//	s->insert(new Node(6));
//	s->insert(new Node(7));
//
//	return s;
//}
//
//void main(int argc, char* argv[])
//{
//	IList* stack = BuildStack();
//
//	Node* current = stack->top();
//	while(current != nullptr)
//	{
//		printf("%d ", current->item);
//		current = stack->top();
//	}
//	getchar();
//}