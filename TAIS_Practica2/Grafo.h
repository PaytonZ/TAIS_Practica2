/********************************************************************************
*																				*
*		Practica 2 TAIS - ORACLE OF BACON										*
*		Autor:			Juan Luis Perez Valbuena	                 			*
*																				*
*********************************************************************************/
#pragma once
#include "Lista.h"
#include <iostream>
#include <vector>
#include <list>


typedef std::vector<std::list<int>*> vectorLista;

class Grafo
{

private:
	int _V;
	vectorLista _adj;

public:
	Grafo(int v){
		_V=v;
		_adj.resize(_V);

		for(int i=0; i < _V ; i++)
		{
			_adj[i] = new std::list<int>;
		}

	}
	~Grafo()
	{
		for(int i=0; i <_V ; i++)
		{
			delete _adj[i];

		}
	}

	void addEdge(int v, int w);
	int V() const;
	const std::list<int>* adj(int v);


};
