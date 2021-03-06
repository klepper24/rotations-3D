#include <iostream>
#include <iomanip>
#include <fstream>
#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "Scena.hh"
#include "lacze_do_gnuplota.hh"


void zapisWspolrzednychDoStrumienia(std::ostream& StrmWy, Prostopadloscian& Pr)
{

	StrmWy << Pr;
	StrmWy << Pr.punkty[0] << std::endl;
                             // Jeszcze raz zapisujemy pierwszy punkt,
                             // aby gnuplot narysowal zamkniętą linię.
}

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] sNazwaPliku - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i prostokata
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
bool zapisWspolrzednychDoPliku(const char *sNazwaPliku, Prostopadloscian& Pr)
{
  std::ofstream StrmPlikowy;

  StrmPlikowy.open(sNazwaPliku);
  if (!StrmPlikowy.is_open())  {
    std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
	 << ":(  nie powiodla sie." << std::endl;
    return false;
  }

  zapisWspolrzednychDoStrumienia(StrmPlikowy, Pr);

  StrmPlikowy.close();
  return !StrmPlikowy.fail();
}

void obracanieProstopadloscianu(Prostopadloscian& pro, Scena& sc)
{
	std::cout << "Podaj sekwencje oznaczen osi oraz katy obrotu w stopniach " << std::endl;
	char os = 'a';
	while(os != '.')
	{
				
		std::cin >> os; 
		
		if(os == 'x' || os == 'y' || os == 'z')
		{
			float kat;			
			std::cin >> kat;			
			Macierz3x3 mac1(os, kat);
			sc.macObrotu = sc.macObrotu * mac1;
		}
		else if(os == '.') {}
		else
		{
			std::cout << "Bledne oznaczenie osi. Dopuszczalne znaki to: x  y  z  . " << std::endl;		
			std::cout << ":( Sprobuj jeszcze raz." << std::endl;
		}
	}


	std::cout << "Ile razy operacja obrotu ma byc powtorzona?" << std::endl;
	unsigned int ile = 0;
	std::cin >> ile;
	for(unsigned int i = 0; i < ile; ++i)
		pro.obroc(sc.macObrotu); 
		
}

void wyswietlanieMacierzyRotacji(const Scena& sc)
{
	std::cout << sc.macObrotu;
}

void przesuwanieProstopadloscianu(Prostopadloscian& pro)
{
	std::cout << "Wprowadz wspolrzedne wektora translacji w postaci dwoch liczb, tzn. wspolrzednej x oraz wspolrzednej y: " << std::endl;

	Wektor3D wek;
	std::cin >> wek;
	
	pro.przesun(wek);
}

void wyswietlanieWspolrzednych(const Prostopadloscian& pro)
{
	std::cout << pro;
}

void sprawdzenieBokow(Prostopadloscian& pro)
{
	pro.sprawdzDlugoscPrzeciwleglychBokow();
}

void wyswietlMenu()
{
		std::cout << std::endl
			 << "o - obrot bryly o zadana sekwencje katow" << std::endl
			 << "t - powtorzenie poprzedniego obrotu" << std::endl
			 << "r - wyswietlenie macierzy rotacji" << std::endl
			 << "p - przesuniecie bryly o zadany wektor" << std::endl
			 << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl
			 << "s - sprawdzenie dlugosci przeciwleglych bokow" << std::endl
			 << "m - wyswietl menu" << std::endl
			 << "k - koniec dzialania programu" << std::endl;
}

int main()
{
	//getopt do robienia menu - poczytać!!!
	Prostopadloscian pro1{Wektor3D(1,1,0),Wektor3D(11,1,0),Wektor3D(1,6,0),Wektor3D(11,6,0), 
							Wektor3D(1,6,7),Wektor3D(11,6,7),Wektor3D(1,1,7),Wektor3D(11, 1,7)};

	Scena s1;

	PzG::LaczeDoGNUPlota  Lacze;  // Ta zmienna jest potrzebna do wizualizacji
                                // rysunku prostokata

   //-------------------------------------------------------
   //  Wspolrzedne wierzcholkow beda zapisywane w pliku "prostokat.dat"
   //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
   //  na dwa sposoby:
   //   1. Rysowane jako linia ciagl o grubosci 2 piksele
   //
  Lacze.DodajNazwePliku("prostokat.dat",PzG::RR_Ciagly,2);
   //
   //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
   //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
   //  jako wspolrzedne punktow podajemy x,y,z.
   //
  Lacze.ZmienTrybRys(PzG::TR_3D);

   // Ustawienie zakresow poszczegolnych osi
  Lacze.UstawZakresY(-150,150);
  Lacze.UstawZakresX(-150,150);
  Lacze.UstawZakresZ(-150,150);

	wyswietlMenu();

	
	char wybor = 'a';
	while(wybor != 'k')
	{

		std::cout << "Twoj wybor?\t";
		std::cin >> wybor;

		switch(wybor)
		{
			case 'o': 	obracanieProstopadloscianu(pro1, s1);
						zapisWspolrzednychDoStrumienia(std::cout,pro1);
  						if (!zapisWspolrzednychDoPliku("prostokat.dat",pro1)) 								
							return 1;
  						Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
						break;

			case 't': 	pro1.obroc(s1.macObrotu);
						zapisWspolrzednychDoStrumienia(std::cout,pro1);
  						if (!zapisWspolrzednychDoPliku("prostokat.dat",pro1)) 								
							return 1;
  						Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
						break;
						break;

			case 'r': 	std::cout << s1.macObrotu;
						break;

			case 'p':   przesuwanieProstopadloscianu(pro1);
						zapisWspolrzednychDoStrumienia(std::cout,pro1);
  						if (!zapisWspolrzednychDoPliku("prostokat.dat",pro1)) 								
							return 1;
  						Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
						break;

			case 'w': 	wyswietlanieWspolrzednych(pro1);
						break;

			case 's':   sprawdzenieBokow(pro1);
						break;

			case 'm':   wyswietlMenu();
						break;

			case 'k': 
						break;

			default:  std::cout << std::endl << "Bledny znak! Sprobuj jeszcze raz!" << std::endl;
						break;
		}
				
	}


	return 0;
}

