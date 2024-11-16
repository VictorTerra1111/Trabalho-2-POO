CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: programa

programa: main.cpp Livro.cpp
	$(CXX) $(CXXFLAGS) -o a main.cpp Livro.cpp

clean:
	rm -f *.o a