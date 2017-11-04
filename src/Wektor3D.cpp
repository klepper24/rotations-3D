#include "Wektor3D.hh"



Wektor3D Wektor3D::operator + (const Wektor3D& wektor) const
{
	Wektor3D temp;
	for(unsigned int i = 0; i < rozmiar; ++i)
	{
		temp.wek[i] = wek[i] + wektor.wek[i];
	}
	
	return temp;
}


Wektor3D Wektor3D::operator - (const Wektor3D& wektor) const
{
	Wektor3D temp;  
	for(unsigned int i = 0; i < rozmiar; ++i)
	{
		temp.wek[i] = wek[i] - wektor.wek[i];
	}
	
	return temp;
}

bool Wektor3D::operator == (const Wektor3D& wektor) const
{
	for(unsigned int i = 0; i < rozmiar; ++i)
	{		
		if(wek[i] != wektor.wek[i])
			return false;
	}

	return true;
}

Wektor3D operator * (const Macierz3x3& macierz, const Wektor3D& wektor)
{
	Wektor3D prim;

	for(unsigned int i = 0; i < wektor.rozmiar; ++i)
		for(unsigned int j = 0; j < wektor.rozmiar; ++j)
				prim.wek[i] += macierz(i,j) * wektor[j];
		
	return prim;
}


std::istream& operator >> (std::istream &Strm, Wektor3D &wektor)
{
	for(unsigned int i = 0; i < wektor.rozmiar; ++i)	
		Strm >> wektor.wek[i];

	return Strm;
}


std::ostream& operator << (std::ostream &Strm, const Wektor3D &wektor)
{
	for(unsigned int i = 0; i < wektor.rozmiar; ++i)	
	  Strm << std::setw(16) << std::fixed << std::setprecision(10) << wektor.wek[i];
	
	Strm << std::endl;

	return Strm;
} 



