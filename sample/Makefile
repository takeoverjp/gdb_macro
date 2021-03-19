PROGRAMS=animal
CXX=g++
CXXFLAGS=-g3 -O0 -W -Wall -Werror

all: $(PROGRAMS)

clean:
	rm -f $(PROGRAMS) *~

format:
	clang-format -i *.cc

animal: animal.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: all clean
