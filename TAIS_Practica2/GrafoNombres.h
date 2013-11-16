/********************************************************************************
*																				*
*		Practica 2 TAIS - ORACLE OF BACON										*
*		Autor:			Juan Luis Perez Valbuena	                 			*
*																				*
*********************************************************************************/

#pragma once

#include <iostream>
#include "Tabla.h"
#include "Grafo.h"
#include "SplitString.h"
#include <fstream>

typedef std::string string;
typedef unsigned int uint;

class GrafoNombres
{

private:

	Tabla<string, uint> tn; // string -> index
	string* nombres; // index -> string
	Grafo* _G; // grafo con vértices numerados


public:
	GrafoNombres(string filename, string delimiter)
	{

		nombres= new string[3000000]();
		std::ifstream file(filename);

		string linea;
		string *pelicula;
		string p;
		int num_actores;
		_G = new Grafo(3000000);
		int indice=0;
		int indice_aux=0;
		int indice_peli=0;



		while(std::getline(file,linea))
		{
			pelicula = split(linea,delimiter,num_actores);
			indice_peli = indice;
			assert(!tn.esta(pelicula[0]));
			tn.inserta(pelicula[0],indice_peli);
			p =  pelicula[0];
			nombres[indice_peli] = p;
			indice++;

			for(int i=1; i < num_actores ; i++)
			{
				if(contiene(pelicula[i]))
				{
					indice_aux = tn.consulta(pelicula[i]);
					assert(nombres[indice_aux]==pelicula[i]);
					//std::cout << "ADDING EDGE! Desde " << nombres[indice_peli] << " ----> " << nombres[indice_aux] <<std::endl;

					_G->addEdge(indice_peli,indice_aux);
				}
				else
				{
					tn.inserta(pelicula[i],indice);
					p = pelicula[i];
					nombres[indice] = p;
					_G->addEdge(indice_peli,indice);

					//std::cout << "ADDING EDGE! Desde " << nombres[indice_peli] << " ----> " << nombres[indice_aux] <<std::endl;
					indice++;
				}


			}


		}

		std::cout <<  "Se cargaron " << indice << " actores/peliculas xD" << std::endl ;




	}
	~GrafoNombres()
	{


	}
	bool contiene(string s); // existe un vértice de nombre s?
	int indice(string s); // devuelve el número asociado al vértice s
	const string& nombre(int v) const; // devuelve el nombre asociado al número v
	Grafo& G() const; // devuelve el grafo de números
};


