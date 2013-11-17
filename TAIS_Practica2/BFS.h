/********************************************************************************
*																				*
*		Practica 2 TAIS - ORACLE OF BACON										*
*		Autor:			Juan Luis Perez Valbuena	                 			*
*																				*
*********************************************************************************/
#pragma once
#include "Grafo.h"
#include <stack>
#include "DFS.h"
#include <list>
typedef std::stack<int> pila;
typedef std::vector<int> vectorInt;

class BFS
{
private:
	pila p;
	vectorBool marked;
	vectorInt edgeTo;
	vectorInt dist;
	int source;
	int dest;

public:
	BFS(Grafo &G, int s,int d)
	{
		marked.resize(G.V());
		for(unsigned int i=0; i < marked.size(); i++)
		{
			marked[i]=false;
		}

		edgeTo.resize(G.V());
		dist.resize(G.V());
			for(unsigned int i=0; i < marked.size(); i++)
		{
			dist[i]=INT_MAX;
		}

		source=s;
		dest=s;
		BFSprv(G,source);
	}
	void BFSprv(Grafo &G,int s);
	std::list<int>* pathTo(int v);
	~BFS(void);
};

