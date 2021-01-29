all:
	make compile
	make link
	make run

compile:
	g++ -c main.cpp

link:
	g++ main.o -lsfml-graphics -lsfml-window -lsfml-system

run:
	./a.out
