#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH


#include <iostream>
#include <iomanip>
#include <cmath>

constexpr double PI = atan2(0,-1);       //zamiast #define PI 3.14159265 

class Macierz3x3 {

public:

	//Macierz2x2() {}
	~Macierz3x3() {}
	Macierz3x3(double degree);
	//operator () do odczytywania wartosci z macierzy, do zapisywania nalezaloby zrobic kolejny operator, patrz: 
	double operator () (unsigned int a, unsigned int b) const
	{
		return mac[a][b];	
	}

	friend std::ostream& operator << (std::ostream &Strm, const Macierz3x3 &macierz);
	//funkcja niepotrzebna ze wzgledu na przeciazony operator funkcyjny ()
	/*
	double get_mac(int a, int b) const
	{
		return mac[a][b];	
	}*/

private:

	static constexpr unsigned int rozmiar = 3;  
	double mac[rozmiar][rozmiar];  

};


#endif
