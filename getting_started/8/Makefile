# MIT 6.s096
# Getting Problem 8
# Hao Zhang
# 2016.09.23
# Makefile

OBJ = test.o is_prime.o
EXE = test
CXX = g++
CXXFLAGS = -O0 -std=c++11 -Wall -Wextra -Weffc++ -Werror -pedantic

$(EXE): $(OBJ)
	$(CXX) -o $(EXE) $(OBJ)

main.o: is_prime.h
is_prime.o: is_prime.h

release: clean
release: CXXFLAGS += -D NDEBUG
release: $(EXE)

.PHONY = clean
clean:
	-rm $(EXE) $(OBJ)
