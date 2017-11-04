#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

#include <iostream>
#include "Macierz3x3.hh"

class Wektor3D {

	
public:

 	Wektor3D() 
	{ 
		for(unsigned int i = 0; i < rozmiar; i++)
			wek[i] = 0.0; //bo double 
	}

	Wektor3D(double a, double b, double c) 
	{
		wek[0] = a;
		wek[1] = b;
		wek[2] = c;
	}
	~Wektor3D() = default;                      //obczaic default
	double& operator [] (unsigned int index)    //przeciazenie operatorow w momencie const!!! najpierw kompilator szuka operatorow const
	{
		return wek[index];
	}

	double operator [] (unsigned int index) const   //nie mozna zwrocic referencji, bo metoda jest const, czyli zapewnia, ze pole klasy nie
	{												//											zostanie zmienione
		return wek[index];
	}

	Wektor3D operator + (const Wektor3D& wektor) const;
	Wektor3D operator - (const Wektor3D& wektor) const;
	bool operator == (const Wektor3D& wektor) const;
	friend Wektor3D operator * (const Macierz3x3& macierz, const Wektor3D& wektor);	
	friend std::istream& operator >> (std::istream &Strm, Wektor3D &wektor);
	friend std::ostream& operator << (std::ostream &Strm, const Wektor3D &wektor);


private:
	
	//static const unsigned int rozmiar = 2; //zeby tylko byla jedna zmienna dla ilus tam obiektow

	static constexpr unsigned int rozmiar = 3;						
	double wek[rozmiar];

};


#endif
