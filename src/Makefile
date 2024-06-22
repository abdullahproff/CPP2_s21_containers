CC=g++
FLAGS=-Wall -Werror -Wextra -std=c++17
TEST_FLAGS = -lgtest -pthread -lgtest_main

all: test

test: 
	@echo --------------------- START ---------------------
	$(CC) -c $(FLAGS) ./tests/test_containers.cc -o ./tests/test_containers.o -pedantic 
	$(CC) ./tests/test_containers.o -o ./tests/test_containers -L/path/to/gtest/lib -lgtest -lstdc++ -std=c++17 -lm -pedantic 
	./tests/test_containers
	@echo -------------------- SUCCESS --------------------

leaks: test
	leaks -atExit -- ./test_containers

clang:
	cp ../materials/linters/.clang-format ../src
	clang-format --style=google -i s21_containersplus.h
	clang-format --style=google -n s21_containersplus.h
	clang-format --style=google -i s21_containers/*
	clang-format --style=google -n s21_containers/*
	clang-format --style=google -i tests/*
	clang-format --style=google -n tests/*
	rm -rf .clang-format

clean:
	rm -rf a.out containers/*.gch tests/*.o tests/test_containers .clang-format *.gcno *.html *.css
