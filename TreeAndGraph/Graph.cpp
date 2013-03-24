//#include "Graph.h"
//
//Graph* buildGraph()
//{
//	Graph* g = new Graph();
//
//	Vertex* v1 = new Vertex(1, "v1");
//	Vertex* v2 = new Vertex(2, "v2");
//	Vertex* v3 = new Vertex(3, "v3");
//	Vertex* v4 = new Vertex(4, "v4");
//	Vertex* v5 = new Vertex(5, "v5");
//
//	Edge* e12 = new Edge(4, v2, "e12");
//	Edge* e13 = new Edge(3, v3, "e13");
//	v1->Edges->push_back(e12);
//	v1->Edges->push_back(e13);
//
//	Edge* e23 = new Edge(1, v3, "e23");
//	Edge* e24 = new Edge(1, v4, "e24");
//	Edge* e25 = new Edge(2, v5, "e25");
//	//v2->Edges->push_back(e23);
//	v2->Edges->push_back(e24);
//	v2->Edges->push_back(e25);
//
//	Edge* e32 = new Edge(1, v2, "e32");
//	Edge* e34 = new Edge(6, v4, "e34");
//	//v3->Edges->push_back(e32);
//	v3->Edges->push_back(e34);
//
//	Edge* e45 = new Edge(7, v5, "e45");
//	v4->Edges->push_back(e45);
//
//	g->Vertices->push_back(v1);
//	g->Vertices->push_back(v2);
//	g->Vertices->push_back(v3);
//	g->Vertices->push_back(v4);
//	g->Vertices->push_back(v5);
//
//	g->Edges->push_back(e12);
//	g->Edges->push_back(e13);
//	g->Edges->push_back(e23);
//	g->Edges->push_back(e24);
//	g->Edges->push_back(e25);
//	g->Edges->push_back(e32);
//	g->Edges->push_back(e34);
//	g->Edges->push_back(e45);
//
//	g->Head = v1;
//	return g;
//}
//
//void printGraph(Graph* g)
//{
//	std::cout << "\n";
//
//	std::list<Vertex*>* vertices = g->Vertices;
//
//	while(!vertices->empty())
//	{
//		Vertex* v = vertices->front();
//		vertices->pop_front();
//		std::cout << "\n\n" <<   v->Name;
//
//		std::list<Edge*>* edges = v->Edges;
//		while(!edges->empty())
//		{
//			Edge* e = edges->front();
//			edges->pop_front();
//			std::cout << "\n   " << e->Name;
//		}
//	}
//
//}
//
//void DFS(Vertex* v)
//{
//	if(v == nullptr || v->Visited)
//	{
//		return;
//	}
//
//	std::cout << v->Name << "\n";
//	v->Visited = true;
//
//	std::list<Edge*>* edges = v->Edges;
//	for(std::list<Edge*>::iterator itr = edges->begin(); itr != edges->end(); ++itr)
//	{
//		Edge* edge = *itr;
//		DFS(edge->Vtx);
//	}
//}
//
//void BFS(Queue<Vertex*>* q)
//{
//	while(!q->IsEmpty())
//	{
//		Vertex* v = q->top();
//		if(!v->Visited)
//		{
//			std::cout << v->Name << "\n";
//			v->Visited = true;
//		}
//
//		std::list<Edge*>* edges = v->Edges;
//		for(std::list<Edge*>::iterator itr = edges->begin(); itr != edges->end(); ++itr)
//		{
//			Edge* edge = *itr;
//			if(!edge->Vtx->Visited)
//			{
//				q->insert(edge->Vtx);
//			}
//		}
//	}
//}
//
////void main()
////{
////	Graph* g = buildGraph();
////
////	//std::cout << "Depth First Search" << "\n";
////	//DFS(g->Head);
////
////	std::cout << "Breadth First Search" << "\n";
////	Queue<Vertex*>* q = new Queue<Vertex*>();
////	q->insert(g->Head);
////	BFS(q);
////
////	getchar();
////}
