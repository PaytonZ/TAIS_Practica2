/********************************************************************************
*																				*
*		Practica 2 TAIS - ORACLE OF BACON										*
*		Autor:			Juan Luis Perez Valbuena	                 			*
*																				*
*********************************************************************************/

#include "BFS.h"


void BFS::BFSprv(Grafo &G,int s)
{
	marked[s]=true;
	p.push(s);
	dist[s]=0;
	while(!p.empty())
	{
		int v= p.front();
		p.pop();
		const std::list<int>* lista= G.adj(v);
		for (std::list<int>::const_iterator iterator =lista->begin(), end =lista->end(); iterator != end; ++iterator) {
			int w = *iterator;
			if(!marked[w])
			{
				edgeTo[w] = v; // save last edge on a shortest path,
				marked[w] = true; // mark it because path is known,
				p.push(w); // and add it to the queue.
				dist[w]= dist[v]+1;
			}
		}

	}

}
std::list<int>* BFS::pathTo(const int &v) const
{
	assert(marked[v]==true);
	std::list<int> *resultado = new std::list<int>;
	for (int x = v; x != source; x = edgeTo[x])
		resultado->push_front(x);
	resultado->push_front(source);

	return resultado;

}
int BFS::costeRutaMinima(const int &v) const
{

	return dist[v];
}

BFS::~BFS(void)
{
}
