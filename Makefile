all:
	make compile
	make link
	make run

compile:
	g++ -c main.cpp

link:
	g++ -Wall -Wextra -O2 main.o -lsfml-graphics -lsfml-window -lsfml-system

run:
	./a.out
