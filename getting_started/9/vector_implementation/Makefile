# MIT 6.s096
# Getting Problem 8
# Hao Zhang
# 2016.09.23
# Makefile

MAIN_OBJ = main.o print_permutations.o
TEST_OBJ = test.o print_permutations.o
EXE = main
TEST = test
CXX = g++
CXXFLAGS = -O0 -std=c++11 -Wall -Wextra -Weffc++ -Werror -pedantic

main: CXXFLAGS += -D NDEBUG
main: $(MAIN_OBJ)
	$(CXX) -o $(EXE) $(MAIN_OBJ)

test: $(TEST_OBJ)
	$(CXX) -o $(TEST) $(TEST_OBJ)

main.o: print_permutations.h
test.o: print_permutations.h
print_permutations.o: print_permutations.h

.PHONY = clean
clean:
	-rm $(EXE) $(TEST) $(MAIN_OBJ) $(TEST_OBJ)
