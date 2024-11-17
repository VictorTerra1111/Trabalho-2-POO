CXX = g++
CXXFLAGS = -std=c++11 -Wall -IHPPS
SRCDIR = CPPS
INCDIR = HPPS
TARGET = a

SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: $(SRCDIR)/%.cpp $(INCDIR)/%.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
