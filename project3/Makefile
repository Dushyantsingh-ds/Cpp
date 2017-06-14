CC = g++
CFLAGS = -c -Wall
LFLAGS  = -Wall
CXXFLAGS := -std=c++0x

default: fraction

fraction: FractDriver.o Fract.o
	$(CC) $(LFLAGS) FractDriver.o Fract.o -o fraction

FractDriver.o: FractDriver.cpp
	$(CC) $(CFLAGS) $(CXXFLAGS) FractDriver.cpp -o FractDriver.o

Fract.o : FractImp.cpp Fraction.h
	$(CC) $(CFLAGS) $(CXXFLAGS) FractImp.cpp -o Fract.o

clean:
	$(RM) count *.o *.gch
