#pragma once
#include <iostream>
#include "Tabla.h"
#include "Grafo.h"

typedef std::string string;
typedef unsigned int uint;

class GrafoNombres
{

private:

Tabla<string, uint> tn; // string -> index
string* nombres; // index -> string
Grafo* _G; // grafo con v�rtices numerados


public:
GrafoNombres(string filename, string delimiter);
~GrafoNombres();
bool contiene(string s) const; // existe un v�rtice de nombre s?
int indice(string s) const; // devuelve el n�mero asociado al v�rtice s
const string& nombre(int v) const; // devuelve el nombre asociado al n�mero v
const Grafo& G() const; // devuelve el grafo de n�meros
};


