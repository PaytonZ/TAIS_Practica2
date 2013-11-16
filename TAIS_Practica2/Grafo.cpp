/********************************************************************************
*																				*
*		Practica 2 TAIS - ORACLE OF BACON										*
*		Autor:			Juan Luis Perez Valbuena	                 			*
*																				*
*********************************************************************************/

#include "Grafo.h"


void Grafo::addEdge(int v, int w)
{
	_adj[v]->push_back(w);
	_adj[w]->push_back(v);
}
const std::list<int>* Grafo::adj(int v)
{
	return _adj[v];
}

int Grafo::V() const
{
	return _V;
}