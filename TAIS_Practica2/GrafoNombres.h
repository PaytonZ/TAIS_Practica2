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
#include <memory>

typedef std::string string;
typedef unsigned int uint;

class GrafoNombres
{

private:

	Tabla<string, uint> tn; // string -> index
	string* nombres; // index -> string
	Grafo* _G; // grafo con v�rtices numerados


public:
	GrafoNombres(string filename, string delimiter)
	{
		string linea;
		
		string p;
		int tam_grafo=0;
		int num_actores;

		int indice=0;
		int indice_aux=0;
		int indice_peli=0;

		std::ifstream file(filename);
		while(std::getline(file,linea))
		{
			auto pelicula = split(linea,delimiter,num_actores);
			tam_grafo+=num_actores;
		}

		_G = new Grafo(tam_grafo);
		nombres= new string[tam_grafo]();


		file.close();

		file.open(filename);


		while(std::getline(file,linea))
		{
		auto	pelicula = split(linea,delimiter,num_actores);
			indice_peli = indice;
			assert(!tn.esta(pelicula.get()[0]));
			tn.inserta(pelicula.get()[0],indice_peli);
			p =  pelicula.get()[0];
			nombres[indice_peli] = p;
			indice++;

			for(int i=1; i < num_actores ; i++)
			{
				if(contiene(pelicula.get()[i]))
				{
					indice_aux = tn.consulta(pelicula.get()[i]);
					assert(nombres[indice_aux]==pelicula.get()[i]);
					_G->addEdge(indice_peli,indice_aux);
				}
				else
				{
					tn.inserta(pelicula.get()[i],indice);
					p = pelicula.get()[i];
					nombres[indice] = p;
					_G->addEdge(indice_peli,indice);
					indice++;
				}
			}
		}
		std::cout <<  "Se cargaron " << indice << " actores/peliculas" << std::endl ;
		file.close();

	}
	~GrafoNombres()
	{
		delete _G;
		delete []nombres;

	}
	bool contiene(string s) const; // existe un v�rtice de nombre s?
	int indice(string s) const ;// devuelve el n�mero asociado al v�rtice s
	const string& nombre(int v) const; // devuelve el nombre asociado al n�mero v
	Grafo& G() const; // devuelve el grafo de n�meros
};


