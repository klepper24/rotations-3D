#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH


#include <iostream>
#include <iomanip>
#include <cmath>

constexpr double PI = atan2(0,-1);       //zamiast #define PI 3.14159265 

class Macierz3x3 {

public:

	Macierz3x3();
	~Macierz3x3() {}
	Macierz3x3(const char& znak, double degree);
	double operator () (unsigned int a, unsigned int b) const
	{
		return mac[a][b];	
	}
	friend Macierz3x3 operator * (const Macierz3x3& macierz1, const Macierz3x3& macierz2);	
	friend std::ostream& operator << (std::ostream &Strm, const Macierz3x3 &macierz);

private:

	static constexpr unsigned int rozmiar = 3;  
	double mac[rozmiar][rozmiar];  

};


#endif
