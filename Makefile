CXX = g++
CXXFLAGS = -std=c++11 -Wall -IHPPS

CPP = CPPS
HPP = HPPS
TARGET = programa

SRCS = $(wildcard $(CPP)/*.cpp)

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
