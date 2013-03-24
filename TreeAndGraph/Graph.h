#pragma once
#include "MyList.h"
#include <stdio.h>
#include <iostream>
#include <list>
#include <string>

class Vertex;

class Edge
{
public:
	std::string Name;
	int EdgeValue;
	Vertex* Vtx;
	Edge(std::string name);
	Edge(int ev, Vertex* vtx, std::string name);
	~Edge();
};

class Vertex
{
public:
	std::string Name;
	bool Visited;
	int VertexValue;
	std::list<Edge*>* Edges;
	bool operator > (Vertex& other);
	bool operator < (Vertex& other);
	Vertex();
	Vertex(std::string name);
	Vertex(int v, std::string name);
	~Vertex();
};

class Graph
{
public:
	Vertex* Head;
	std::list<Vertex*>* Vertices;
	std::list<Edge*>* Edges;
	Graph();
	~Graph();
};

Edge::Edge(std::string name)
{
	Name = name;
	EdgeValue = -1;
	Vtx = nullptr;
}

Edge::Edge(int ev, Vertex* vtx, std::string name)
{
	Name = name;
	EdgeValue = ev;
	Vtx = vtx;
}

Edge::~Edge()
{
}

Vertex::Vertex()
{
	Name = "";
	Visited = false;
	VertexValue = -1;
	Edges = new std::list<Edge*>();

}

Vertex::Vertex(std::string name)
{
	Name = name;
	Visited = false;
	VertexValue = -1;
	Edges = new std::list<Edge*>();
}

Vertex::Vertex(int v, std::string name)
{
	Name = name;
	Visited = false;
	VertexValue = v;
	Edges = new std::list<Edge*>();
}

Vertex::~Vertex()
{
}

bool Vertex::operator>(Vertex& v)
{
	return VertexValue > v.VertexValue;
}

bool Vertex::operator<(Vertex& v)
{
	return VertexValue < v.VertexValue;
}

Graph::Graph()
{
	Head = nullptr;
	Vertices = new std::list<Vertex*>();
	Edges = new std::list<Edge*>();
}

Graph::~Graph()
{
}
