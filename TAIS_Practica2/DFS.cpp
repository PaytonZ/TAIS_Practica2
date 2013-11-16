/********************************************************************************
*																				*
*		Practica 2 TAIS - ORACLE OF BACON										*
*		Autor:			Juan Luis Perez Valbuena	                 			*
*																				*
*********************************************************************************/

#include "DFS.h"


void DFS::DFSprv(Grafo &g,int v)
{
	mark[v]=true;
const	std::list<int> *lista= g.adj(v);
	for (std::list<int>::const_iterator iterator =lista->begin(), end =lista->end(); iterator != end; ++iterator) {
		int w= *iterator;
		if(!marked(w))
		{
			DFSprv(g,w);
		}
	}
}

bool DFS::marked(int v)
{
	return mark[v];

}
DFS::~DFS(void)
{
}
