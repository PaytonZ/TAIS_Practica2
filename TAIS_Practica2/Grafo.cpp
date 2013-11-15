#include "Grafo.h"


void Grafo::addEdge(int v, int w)
{
	_adj[v]->ponDr(w);
	_adj[w]->ponDr(v);
}
Lista<int>::Iterador Grafo::adj(int v)
{
	return _adj[v]->principio();

}