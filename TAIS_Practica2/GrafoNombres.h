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

	nombres= new string();

	


	std::ifstream file(filename);
	
	string linea;
	string *pelicula;
	string p;
	int num_actores;
	_G = new Grafo(100);
	int indice=0;
		int indice_aux=0;
		int indice_peli=0;


//	while(!file.eof())
	//{
		
		std::getline(file,linea);
		pelicula = split(linea,delimiter,num_actores);
		std::cout << "out" << num_actores << std::endl;
		
		
		indice_peli = indice;
		tn.inserta(pelicula[0],indice_peli);
		 p =  pelicula[0];
		nombres[indice_peli] = p;
		indice++;
		
		for(int i=1; i < num_actores ; i++)
		{
			if(tn.esta(pelicula[i]))
			{
				indice_aux = tn.consulta(pelicula[i]);
				_G->addEdge(indice_peli,indice_aux);
			}
			else
			{
				tn.inserta(pelicula[i],indice);
				std::cout << pelicula[indice].length();
				p = pelicula[i];
				nombres[indice] = p;
				_G->addEdge(indice_peli,indice);
				indice++;
			}

			std::cout << pelicula[i] << std::endl;
		}
		

	//}
	

}
~GrafoNombres()
{

}
bool contiene(string s) const; // existe un vértice de nombre s?
int indice(string s) const; // devuelve el número asociado al vértice s
const string& nombre(int v) const; // devuelve el nombre asociado al número v
const Grafo& G() const; // devuelve el grafo de números
};


