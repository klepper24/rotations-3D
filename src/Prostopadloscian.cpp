#include "Prostopadloscian.hh"


void Prostopadloscian::obroc(Macierz3x3 macierz)
{
	for(auto& i : punkty)	
		i = macierz * i;	
}

void Prostopadloscian::przesun(Wektor3D wektor)
{
	for(auto& i : punkty)	
		i = i + wektor;
}

void Prostopadloscian::sprawdzDlugoscPrzeciwleglychBokow()
{	
/*
	if((punkty[3] - punkty[0]) == (punkty[2] - punkty[1]))
		std::cout << "Dluzsze przeciwlegle boki sa sobie rowne!" << std::endl;
	else
		std::cout << "Ups! Dluzsze przeciwlegle boki NIE sa sobie rowne! Uwaga na niedokladnosci!" << std::endl;

	if((punkty[1] - punkty[0]) == (punkty[2] - punkty[3]))
		std::cout << "Krotsze przeciwlegle boki sa sobie rowne!" << std::endl;
	else
		std::cout << "Ups! Krotsze przeciwlegle boki NIE sa sobie rowne! Uwaga na niedokladnosci!" << std::endl;*/
}

std::ostream& operator << (std::ostream& Strm, const Prostopadloscian& Pr)
{	
	for(const auto& i : Pr.punkty)  
		Strm << std::setw(16) << std::fixed << std::setprecision(10) << i;		
	
	return Strm;
}


