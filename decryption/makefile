# VARIABLES:
CXX=g++
CXXFLAGS=-std=c++23 -O3 -pedantic-errors

# SOURCES AND EXECUTABLE
SOURCES=$(wildcard *.cpp)
EXECUTABLE=decryption

# BUILD RULES
all: $(EXECUTABLE)

$(EXECUTABLE):
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@

clean:
	rm -f $(EXECUTABLE)

