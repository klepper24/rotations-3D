#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>



class Prostopadloscian
{

	
	Prostopadloscian(std::initializer_list<Wektor3D> l) : punkty(l) {} //konstruktor dla vectora z std na bazie initializer_list
	~Prostopadloscian() = default;
    void obroc(Macierz3x3 macierz);
	void przesun(Wektor3D wektor);
	void sprawdzDlugoscPrzeciwleglychBokow();
	friend void zapisWspolrzednychDoStrumienia(std::ostream& StrmWy, Prostopadloscian& Pr);
    friend std::ostream& operator << ( std::ostream& Strm, const Prostopadloscian& Pr);

private:
	     
	std::vector<Wektor3D> punkty;

};


#endif
