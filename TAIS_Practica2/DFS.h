/********************************************************************************
*																				*
*		Practica 2 TAIS - ORACLE OF BACON										*
*		Autor:			Juan Luis Perez Valbuena	                 			*
*																				*
*********************************************************************************/
#pragma once
#include "Grafo.h"
typedef std::vector<bool> vectorBool;
class DFS
{
private:
	vectorBool mark;
	void DFSprv(Grafo &g,int v);

public:
	DFS(Grafo &g,int s)
	{
		mark.resize(g.V());
		DFSprv(g,s);

	}
	~DFS();
	bool marked(int v); 
};

