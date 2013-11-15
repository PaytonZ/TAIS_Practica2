#include <iostream>
#include "Grafo.h"
#include "Tabla.h"
#include "GrafoNombres.h"




int main()

{
	//Grafo g(10);
	GrafoNombres pelis("movies.txt", "/");


	string *a;

	a= new string();

	a[0] = "juanita";

	std::cout << a[0];

	string ab;
	std::cin >> ab;

	return 0;
}