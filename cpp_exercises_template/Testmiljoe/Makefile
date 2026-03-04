CXX = g++
CXXFLAGS = -Wall -g -pthread
target = main.out
HEADERS = $(wildcard *.h)

.PHONY: all 
all: $(target)

%.out: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $< -o $@