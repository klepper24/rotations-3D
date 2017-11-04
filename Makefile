#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -Wextra -Werror -pedantic -std=c++11

__start__: obroty_3D
	./obroty_3D

obroty_3D: obj obj/main.o obj/Prostopadloscian.o obj/Macierz3x3.o obj/Wektor3D.o\
           obj/lacze_do_gnuplota.o
	g++ -Wall -Werror -Wextra -pedantic -std=c++11 -o obroty_3D obj/main.o obj/Wektor3D.o\
                        obj/Macierz3x3.o obj/Prostopadloscian.o obj/lacze_do_gnuplota.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Scena.hh inc/Prostopadloscian.hh inc/Macierz3x3.hh inc/Wektor3D.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh cpp inc/Prostopadloscian.hh cpp inc/Macierz3x3.hh
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh inc/Wektor3D.hh inc/Macierz3x3.hh
	g++ -c ${CXXFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Macierz3x3.o: src/Macierz3x3.cpp inc/Macierz3x3.hh 
	g++ -c ${CXXFLAGS} -o obj/Macierz3x3.o src/Macierz3x3.cpp

obj/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor3D.o src/Wektor3D.cpp

clean:
	rm -f obj/*.o obroty_3D
