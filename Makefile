all:
	make compile
	make link
	make run

compile:
	g++ -c main.cpp

link:
	g++ main.o -o t3 -lsfml-graphics -lsfml-window -lsfml-system

run:
	./t3
