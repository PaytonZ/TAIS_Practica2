#pragma once
#include "Lista.h"
#include <iostream>
#include <vector>


typedef std::vector<Lista<int>*> vector;

class Grafo
{

private:
	int _V;
	vector _adj;

public:
	Grafo(int v){
		_V=v;
		_adj.resize(_V);
		
		for(int i=0; i < _V ; i++)
		{
			_adj[i] = new Lista<int>;
		}
		
	}
	~Grafo()
	{
		for(int i=0; i <_V ; i++)
		{
			
			Lista<int> *a = _adj[i];
			 
		}
	}

	void addEdge(int v, int w);
	Lista<int>::Iterador adj(int v);
	

};
