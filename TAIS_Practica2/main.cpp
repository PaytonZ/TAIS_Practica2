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
#include "g2_chrono.h"

void GradoSeparacion(const string& origen);
void NumeroDeBacon(const string& actor);


int main()

{
	string actor;
	std::cout << "Funcion Grado Separacion" << std::endl;

	std::cout << "Introduce actor origen:";
	std::getline(std::cin,actor);


	GradoSeparacion(actor);

	std::cout << "Funcion Numero de Bacon" << std::endl;

	std::cout << "Introduce actor origen:";
	std::getline(std::cin,actor);

	NumeroDeBacon(actor);



	std::cout << "Fin ej";

	string a ;

	std::cin >> a ;
}

void GradoSeparacion(const string& origen) {

	std::cout << "Cargando grafo de peliculas... " << std::endl;
	g2::StopWatch watch;
	GrafoNombres pelis("movies.txt", "/");
	auto time = watch.elapsedMs().count();
	std::cout << "Grafo Nombres tardo ... " << time <<"ms" << std::endl;
	if(pelis.contiene(origen))
	{
		int vorigen = pelis.indice(origen);
		string actordestino;
		g2::StopWatch watch;
		BFS bfs(pelis.G(),vorigen);
		auto time = watch.elapsedMs().count();
		std::cout << "BFS tardo ... " << time <<"ms" << std::endl;
		std::cout << "Escribe actor destino:" ;

		std::getline(std::cin,actordestino);
		while(actordestino !="")
		{
			if(pelis.contiene(actordestino))
			{
				int vdestino = pelis.indice(actordestino);

				if(bfs.hayRuta(vdestino))
				{

					auto camino = bfs.pathTo(vdestino);
					std::cout << actordestino << " tiene un numero de Bacon de " << bfs.costeRutaMinima(vdestino) /2 << std::endl;
					bool actor=true;
					for (std::list<int>::const_iterator iterator =camino->begin(), end =camino->end(); iterator != end; ++iterator) {
						uint v = *iterator;

						std::cout << pelis.nombre(v) << std::endl;
						if(v != vdestino) 
						{if (actor) {
							std::cout << "\twas in" << std::endl;
							actor=!actor;
						}
						else
						{
							std::cout << "\twith" << std::endl;
							actor=!actor;
						}
						}

					}
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
			std::cout << "Escribe actor destino:" ;
			std::getline(std::cin,actordestino);
		}
	}
	else 
	{
		std::cout << "El actor '" << origen << "' no se encuentra en nuestra base de datos" << std::endl;
	}

}

void NumeroDeBacon(const string& actor)
{
	std::cout << "Cargando grafo de peliculas... " << std::endl;
	GrafoNombres pelis("movies.txt", "/");
	if(pelis.contiene(actor))
	{
		int vorigen = pelis.indice(actor);
		BFS bfs(pelis.G(),vorigen);
		int v[11];
		for(int k=0; k < 11; k++)
			v[k]=0;
		for(int i=0; i < pelis.G().V() ; i++)
		{

			int bacon = bfs.costeRutaMinima(i) ;
			if(bacon % 2 ==0)//Son actores y no peliculas.
			{
				bacon/=2;
				v[bacon]++;
			}
		}

		std::cout << "Origen: " << pelis.nombre(vorigen) <<std::endl; 
		std::cout << "Numero" << "\t" << "# de actores" <<std::endl; 
		for(int i=0; i < 11 ; i++)
		{
			std::cout << i << "\t" << v[i] <<std::endl; 
		}

	}

}

