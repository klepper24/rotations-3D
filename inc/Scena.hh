#ifndef SCENA_HH
#define SCENA_HH

#include <iostream>
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"

class Scena
{
public:
	Macierz3x3 macObrotu;
	Prostopadloscian bryla;
	Scena() : macObrotu(), bryla() {}
};

#endif
