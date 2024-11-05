exe: main_giovanelli_zachary.o zombie_giovanelli.o
	g++ -g -Wall main_giovanelli_zachary.o zombie_giovanelli.o -o exe

main_giovanelli_zachary.o: linkedlist_giovanelli.hpp zombie_giovanelli.h
	g++ -g -Wall -c main_giovanelli_zachary.cpp

zombie_giovanelli.o: linkedlist_giovanelli.hpp zombie_giovanelli.h
	g++ -g -Wall -c zombie_giovanelli.cpp

