#ifndef PROSTOKAT_HH
#define PROSTOKAT_HH

#include <iostream>



class Prostopadloscian {

	
	Prostokat(std::initializer_list<Wektor3D> l) : punkty(l) {} //konstruktor dla vectora z std na bazie initializer_list
	~Prostokat() = default;
    void obroc(Macierz3x3 macierz);
	void przesun(Wektor3D wektor);
	void sprawdzDlugoscPrzeciwleglychBokow();
	friend void zapisWspolrzednychDoStrumienia(std::ostream& StrmWy, Prostokat& Pr);
    friend std::ostream& operator << ( std::ostream& Strm, const Prostokat& Pr);

private:
	     
	std::vector<Wektor3D> punkty;

};


#endif
