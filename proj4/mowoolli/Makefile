proj4.exe: EventClass.o main.o
	g++ -Wall EventClass.o main.o -o proj4.exe

main.o: main.cpp ListNodeClass.inl ListNodeClass.h SortedListClass.inl SortedListClass.h
	g++ -Wall -c main.cpp -o main.o

EventClass.o: EventClass.cpp EventClass.h
	g++ -Wall -c EventClass.cpp -o EventClass.o

clean:
	rm -rf main.o EventClass.o proj4.exe
