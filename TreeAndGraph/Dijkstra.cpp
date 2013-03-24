#include "Dijkstra.h"


void main(int argc, char* argv[])
{
	Dijkstra* sPath = new Dijkstra();

	Vertex* head = new Vertex(0,"v1");

	//BUG: the comparison on the Vertex* will fail during insert/remove
	BinaryHeap<Vertex*>* pQ = new BinaryHeap<Vertex*>();
	pQ->Insert(head);

	Vertex* current = pQ->RemoveMin();
	sPath->ShortestPath(current, pQ);

	getchar();
}
