#include "Macierz3x3.hh"


Macierz3x3::Macierz3x3()
{
	for(unsigned int i = 0; i < rozmiar; ++i)
		for(unsigned int j = 0; j < rozmiar; ++j)
			mac[i][j] = 1;
}

Macierz3x3::Macierz3x3(const char& znak, double degree)
{
	switch(znak)
	{
		case 'x':	mac[0][0] = mac[1][1] = cos(degree * PI / 180.0);
					mac[0][1] = -sin(degree * PI / 180.0);
					mac[1][0] = sin(degree * PI / 180.0);	
					mac[2][2] = 1;
					mac[2][0] = mac[2][1] = mac[0][2] = mac[1][2] = 0;
					break;

		case 'y':	mac[0][0] = mac[2][2] = cos(degree * PI / 180.0);
					mac[0][2] = -sin(degree * PI / 180.0);
					mac[2][0] = sin(degree * PI / 180.0);	
					mac[1][1] = 1;
					mac[1][0] = mac[0][1] = mac[2][1] = mac[1][2] = 0;
					break;

		case 'z':	mac[1][1] = mac[2][2] = cos(degree * PI / 180.0);
					mac[1][2] = -sin(degree * PI / 180.0);
					mac[2][1] = sin(degree * PI / 180.0);	
					mac[0][0] = 1;
					mac[1][0] = mac[2][0] = mac[0][1] = mac[0][2] = 0;
					break;

		default: 	std::cout << "Wprowadzono bledny znak osi!" << std::endl;
					break;
	}	
	
}

Macierz3x3 operator * (const Macierz3x3& macierz1, const Macierz3x3& macierz2)
{
	Macierz3x3 temp;

	for(unsigned int i = 0; i < macierz1.rozmiar; ++i)
		for(unsigned int j = 0; j < macierz1.rozmiar; ++j)
			temp.mac[i][j] += macierz1.mac[i][j] * macierz2.mac[j][i];

	return temp; 
	
}

std::ostream& operator << (std::ostream &Strm, const Macierz3x3 &macierz)
{
		
	for(unsigned int i = 0; i < macierz.rozmiar; ++i)
	{
		for(unsigned int j = 0; j < macierz.rozmiar; ++j)
		{  		
			Strm << std::setw(16) << std::fixed << std::setprecision(10) << macierz.mac[i][j];
		}
		std::cout << std::endl;	
	}

	return Strm << std::endl;
}
