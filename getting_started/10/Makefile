# MIT 6.s096
# Getting startted Problem 10
# Hao Zhang
# 2016.09.24
# Makefile

MAIN = main
TEST = test
MAIN_OBJ = main.o search.o
TEST_OBJ = test.o search.o
CXX = g++
CXXFLAGS = -O0 -std=c++11 -Wall -Wextra -Weffc++ -Werror -pedantic

$(MAIN): CXXFLAGS += -D NDEBUG
$(MAIN): $(MAIN_OBJ)
	$(CXX) -o $(EXE) $(MAIN_OBJ)

$(TEST): $(TEST_OBJ)
	$(CXX) -o $(TEST) $(TEST_OBJ)

main.o: search.h
test.o: search.h
search.o: search.h

.PHONY = clean
clean:
	-rm $(EXE) $(TEST) $(MAIN_OBJ) $(TEST_OBJ)
