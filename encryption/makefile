# VARIABLES:
CXX=g++
CXXFLAGS=-std=c++20 -O3 -pedantic-errors

# SOURCES AND EXECUTABLE
SOURCES=$(wildcard *.cpp)
EXECUTABLE=encryption

# BUILD RULES
all: $(EXECUTABLE)

$(EXECUTABLE):
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@

clean:
	rm -f $(EXECUTABLE)

