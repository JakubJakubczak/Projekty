
#
#  To sa opcje dla kompilacji
#
CXXFLAGS= -c -g -Iinc -Wall -pedantic

__start__: Szachy
	./Szachy

Szachy: obj/main.o 
	g++ -Wall -pedantic -o Szachy obj/main.o -lsfml-graphics -lsfml-window -lsfml-system

obj/main.o: src/main.cpp inc/AI.hpp inc/plansza.hpp
	g++ ${CXXFLAGS} -o obj/main.o src/main.cpp

clean:
	rm -f obj/*.o main.o