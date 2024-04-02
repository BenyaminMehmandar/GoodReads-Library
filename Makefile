

all: Goodreads.out

Goodreads.out: main.o Authors.o Users.o Books.o Reviews.o GoodReads.o FollowEdges.o Functions.o
	g++ -std=c++11 main.o Authors.o Users.o Books.o Reviews.o GoodReads.o FollowEdges.o Functions.o

main.o: main.cpp Users.hpp Authors.hpp Reviews.o FollowEdges.o Functions.o
	g++ -std=c++11 -c main.cpp

Users.o: Users.hpp Users.cpp
	g++ -std=c++11 -c Users.cpp

Authors.o: Authors.hpp Authors.cpp
	g++ -std=c++11 -c Authors.cpp

Books.o: Books.cpp Books.hpp Authors.hpp 
	g++ -std=c++11 -c Books.cpp

Reviews.o: Reviews.cpp Reviews.hpp Users.hpp Books.hpp
	g++ -std=c++11 -c Reviews.cpp

GoodReads.o: GoodReads.cpp GoodReads.hpp Reviews.hpp Books.hpp Authors.hpp Users.hpp FollowEdges.hpp
	g++ -std=c++11 -c GoodReads.cpp

FollowEdges.o: FollowEdges.cpp FollowEdges.hpp
	g++ -std=c++11 -c FollowEdges.cpp
Functions.o: Functions.cpp Functions.cpp  Users.hpp FollowEdges.hpp Reviews.hpp Books.hpp Authors.hpp
	g++ -std=c++11 -c Functions.cpp