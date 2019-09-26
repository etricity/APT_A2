.default: all

all: qwirkle

run: 
	./qwirkle

clean:
	rm -rf qwirkle *.o *.dSYM

qwirkle: Tile.o Node.o LinkedList.o Qwirkle.o GameMechanics.o BoardPosition.o Board.o FileIO.o Player.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^

build: 
	g++ -Wall  -std=c++14 -O -o qwirkle *.cpp
