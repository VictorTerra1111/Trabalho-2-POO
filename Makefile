#PRECISA SER MODIFICADO 

CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: programa

programa: TBmain.cpp File_manage.cpp Obras.cpp perguntas.cpp 
	$(CXX) $(CXXFLAGS) -o  TBmain.cpp File_manage.cpp Obras.cpp perguntas.cpp 

clean:
	rm -f *.o a