/********************************************************************************
*																				*
*		Practica 2 TAIS - ORACLE OF BACON										*
*		Autor:			Juan Luis Perez Valbuena	                 			*
*																				*
*********************************************************************************/

#pragma once

#include <iostream>
#include "Grafo.h"
#include "SplitString.h"
#include <fstream>
#include <memory>
#include <map>

typedef std::string string;
typedef unsigned int uint;

class GrafoNombres
{

private:

	std::map<string, uint> tn; // string -> index
	string* nombres; // index -> string
	Grafo* _G; // grafo con vértices numerados


public:
	GrafoNombres(string filename, string delimiter)
	{

		string linea;
		string p;
		int tam_grafo=0,num_actores,  index=0, indice_aux=0 , indice_peli=0;

		std::ifstream file(filename);
		while(std::getline(file,linea))
		{
			auto pelicula = split(linea,delimiter,num_actores);
			for(int i=0; i < num_actores ; i++)
			{
				if(!contiene(pelicula.get()[i]))
				{
					tn.insert(std::pair<string,uint>(pelicula.get()[i],index));
					index ++;
				}
			}
		}
		_G = new Grafo(index);
		nombres= new string[index]();

		file.close();
		file.open(filename);

		while(std::getline(file,linea))
		{
			auto pelicula = split(linea,delimiter,num_actores);
			indice_peli=indice(pelicula.get()[0]);
			nombres[indice_peli] = pelicula.get()[0];

			for(int i=1; i < num_actores ; i++)
			{
				indice_aux=indice(pelicula.get()[i]);
				nombres[indice_aux] = pelicula.get()[i];
				_G->addEdge(indice_aux,indice_peli);
			}

		}

		std::cout <<  "Se cargaron " << index << " actores/peliculas" << std::endl ;
		file.close();

	}
	~GrafoNombres()
	{
		delete _G;
		delete []nombres;

	}
	bool contiene(string s) const; // existe un vértice de nombre s?
	int indice(string s) const ;// devuelve el número asociado al vértice s
	const string& nombre(int v) const; // devuelve el nombre asociado al número v
	Grafo& G() const; // devuelve el grafo de números
};


