#pragma once
#include <map>
#include "BinaryHeap.h"

/*
Dijkstra single source shortest path algorithm
PreReq:
=======
- The data structure must be a graph i.e all verticies must be connected
- All verticies must have a inital value (say a high number == infinity)
- All edges must have a weight

Concept:
=======
- Choose the min distance vertex and mark it as settled
- Relax its neighbours
- Update the neighbour with its predecessor
- Continue from step 1 untill all vertices are marked as settled
- Now the predecessor path from any vertex gives the shortest path to the source (ie head Vertex)

Pseudo code:
===========
- Choose a vertex as a starting point(head) and assign its value to 0
- Since the starting point doesnt have a predecessor, assign its predecessor to null
- Insert it to a BinaryHeap (priority queue, pQ)
1. Remove the min vertex from the pQ
2. Check if min vertex is present in map data structure [(ie settled queue, sQ) with key = vertex->Name : value = vertext]
  -- if min vertex is present in sQ , proceed from step 1
  -- if min vertex is not present in the sQ, mark it as settled and add to the sQ
3. Start relaxing the min vertex[Vcurrent] neighbours and updating the neighbour predecessor with the min vertex
  -- Using the edges, get the vertex[Vneighbour] that is not settled yet
  -- if the distance from (Vcurrent + Ecurrent-neighbour) is less than the Vneighbour value, then
     --- update the Vneighbour value with (Vcurrent + Ecurrent-neighbour)
	 --- updated the Vneighbour predecessor with Vcurrent
	 --- insert the Vneighbour to the pQ
4. Continue from Step 1, untill the pQ is empty
5. The sQ contains the vertices with shortest path to the source

*/
class Dijkstra
{
private:
	std::map<std::string, Vertex*> sQ;

public:
	void ShortestPath(Vertex* current, BinaryHeap<Vertex*>* pQ);
	Dijkstra();
	~Dijkstra();
};

void Dijkstra::ShortestPath(Vertex* current, BinaryHeap<Vertex*>* pQ)
{
	if(current == nullptr)
	{
		return;
	}

	std::map<std::string, Vertex*>::iterator itr;
	itr = sQ.find(current->Name);

	if(itr == sQ.end())
	{
		// current vertex is not present in sQ, so 
		// mark the current as settled and add it to sQ
		current->Visited = true;
		sQ[current->Name] = current;

		// relax the neighbours and update the neighbour predecessor
		std::list<Edge*>* edges = current->Edges;
		for(std::list<Edge*>::iterator itr = edges->begin(); itr != edges->end(); ++itr)
		{
			Edge* e = (*itr);
			Vertex* Vneighbour = e->Vtx;
			if(!Vneighbour->Visited)
			{
				// relax and update the predecessor for unsettled vertex
				// whose value is less then minDistance
				int minDistance = current->VertexValue + e->EdgeValue;
				if(minDistance < Vneighbour->VertexValue)
				{
					Vneighbour->VertexValue = minDistance;
					//Vneighbour->Predecessor = current;
					pQ->Insert(Vneighbour);
				}
			}
		}
	}
	
	// continue by removing the next min vertex
	Vertex* min = pQ->RemoveMin();
	ShortestPath(min, pQ);
}

Dijkstra::Dijkstra()
{
}

Dijkstra::~Dijkstra()
{
}

