/********************************************************************************
*																				*
*		Practica 2 TAIS - ORACLE OF BACON										*
*		Autor:			Juan Luis Perez Valbuena	                 			*
*																				*
*********************************************************************************/



#include <iostream>
#include "Grafo.h"
#include "Tabla.h"
#include "GrafoNombres.h"
#include "DFS.h"
#include "BFS.h"

void GradoSeparacion(const string& origen);


int main()

{


	GradoSeparacion("Kevin Bacon");

/*	GrafoNombres pelis("movies.txt", "/");

	
	int bacon=0;
	const std::list<int> *a = pelis.G().adj(pelis.indice("Kevin Bacon"));
	//std::list<int> *a = pelis.G().adj(pelis.indice("'Breaker' Morant (1980)"));
	const std::list<int> *b;
	for (std::list<int>::const_iterator iterator =a->begin(), end =a->end(); iterator != end; ++iterator) {
	
		int w= *iterator ;
		std::cout << "peli:" ;
		std::cout << pelis.nombre(w) << std::endl;
		b = pelis.G().adj(w);
		std::cout << "actores:" << std::endl;
		for (std::list<int>::const_iterator iterator2 =b->begin(), end =b->end(); iterator2 != end; ++iterator2) {
			int z= *iterator2 ;
				
			std::cout << pelis.nombre(z) << std::endl;
		}
	}


	//	std::cout <<  " baaacon" << bacon << std::endl;
	*/
	std::cout << "Fin ej";
	string ab;
	std::cin >> ab;

	std::cout << "Fin ej";

	std::cin >> ab;

	return 0;
}

void GradoSeparacion(const string& origen) {

	std::cout << "Cargando grafo de peliculas... " << std::endl;
	GrafoNombres pelis("movies.txt", "/");
	if(pelis.contiene(origen))
	{
		int vorigen = pelis.indice(origen);
		string actordestino;
		std::cout << "Escribe actor destino:" ;
		std::getline(std::cin,actordestino);
		//	while(actordestino != "")
		//	{
		if(pelis.contiene(actordestino))
		{
			int vdestino = pelis.indice(actordestino);
			DFS dfs(pelis.G(),vorigen);
			if(dfs.marked(vdestino))
			{
				BFS bfs(pelis.G(),vorigen,vdestino);
				std::list<int> * camino = bfs.pathTo(vdestino);
				/*for (std::list<int>::const_iterator iterator =camino->begin(), end =camino->end(); iterator != end; ++iterator) {
					int a= *iterator;
					//std::cout << pelis.nombre(a) << std::endl;
				}*/
				

			}
			else
			{
				std::cout << "No existe una conexion entre '" << origen << "' y '" << actordestino << "'" << std::endl; 
			}
		}
		else
		{
			std::cout << "El actor '" << actordestino << "' no se encuentra en nuestra base de datos" << std::endl;
		}
		//	}



	}

	else 
	{
		std::cout << "El actor '" << origen << "' no se encuentra en nuestra base de datos" << std::endl;
	}



}