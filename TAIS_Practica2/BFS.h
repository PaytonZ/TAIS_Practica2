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
#include <queue>
#include <memory>

typedef std::queue<int> cola;
typedef std::vector<int> vectorInt;

class BFS
{
private:
	cola p;
	vectorBool marked;
	vectorInt edgeTo;
	vectorInt dist;
	int source;
	

public:
	BFS(Grafo &G, int s)
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
		BFSprv(G,source);
	}
	void BFSprv(Grafo &G,int s);
std::shared_ptr<std::list<int>> BFS::pathTo(const int &v) const;
	int costeRutaMinima(const int &v) const;
	~BFS(void);
};

