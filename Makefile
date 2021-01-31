all:
	make compile
	make run

compile:
	g++ main.cpp -O2 -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system -o main.out

run:
	./main.out
