all: hello

hello: main.o
	g++ main.o Cell.o ConnectFourAbstract.o ConnectFourPlus.o ConnectFourDiag.o ConnectFourPlusUndo.o -o exe

main.o: main.cpp
	g++ -c -std=c++11 main.cpp Cell.cpp ConnectFourAbstract.cpp ConnectFourPlus.cpp ConnectFourDiag.cpp ConnectFourPlusUndo.cpp

clean:
	rm *.o exe
