//#include "Queue.h"
//
//IList* BuildQueue()
//{
//	IList* q = new Queue();
//	q->insert(new Node(1));
//	q->insert(new Node(2));
//	q->insert(new Node(3));
//	q->insert(new Node(4));
//	q->insert(new Node(5));
//	q->insert(new Node(6));
//	q->insert(new Node(7));
//
//	return q;
//}
//
//void main(int argc, char* argv[])
//{
//	IList* queue = BuildQueue();
//
//	Node* current = queue->top();
//	while(current != nullptr)
//	{
//		printf("%d ", current->item);
//		current = queue->top();
//	}
//	getchar();
//}