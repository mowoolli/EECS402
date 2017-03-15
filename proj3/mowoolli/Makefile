main.exe: printMenu.o ImageClass.o RectangleClass.o ColorClass.o main.o
	g++ -Wall printMenu.o ImageClass.o RectangleClass.o ColorClass.o main.o -o main.exe

main.o: main.cpp
	g++ -Wall -c main.cpp -o main.o

printMenu.o: printMenu.cpp printMenu.h
	g++ -Wall -c printMenu.cpp -o printMenu.o

ImageClass.o: ImageClass.cpp ImageClass.h
	g++ -Wall -c ImageClass.cpp -o ImageClass.o

RectangleClass.o: RectangleClass.cpp RectangleClass.h
	g++ -Wall -c RectangleClass.cpp -o RectangleClass.o

ColorClass.o: ColorClass.cpp ColorClass.h
	g++ -Wall -c ColorClass.cpp -o ColorClass.o

clean:
	rm -rf main.o printMenu.o ImageClass.o RectangleClass.o ColorClass.o main.exe
