CC = gcc
CFLAGS =-Werror -Wextra -Wall -std=c11 -pedantic
EXTRA_FLAGS=

GCOV_FLAGS=-fprofile-arcs -ftest-coverage
SAN_FLAGS=-g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer
LEAK_FLAGS=-g -O0 -fsanitize=leak
VALGRIND_FLAGS=--tool=memcheck --leak-check=yes

SOURCE=$(wildcard ./functions/*.c)
OBJECTS=$(SOURCE:.c=.o)
TEST_FLAGS=-lcheck -lsubunit -lrt -lm -lpthread
COV_OBJECTS=$(SOURCE:.c=_cov.o)

TEST_SOURCE=$(wildcard ./test_cases/*.c) $(wildcard ./test_cases/tests/*.c)
TEST_OBJECTS=$(TEST_SOURCE:.c=.o)

.PHONY: all test test_bin clean test_bin_cov gcov_report

all:
	$(MAKE) clean
	$(MAKE) s21_matrix.a


s21_matrix.a: $(OBJECTS)
	ar rcs $@ $^
	ranlib $@
	@echo "Library built: $@"

c: 
	clang-format -n */*.c */*.h */*/*.c

cppcheck:
	cppcheck --enable=all */*.c */*/*.c

sanitizer:
	$(MAKE) clean
	$(MAKE) test EXTRA_FLAGS="$(SAN_FLAGS)"

leak:
	$(MAKE) clean
	$(MAKE) test EXTRA_FLAGS="$(LEAK_FLAGS)"

valgrind:
	$(MAKE) clean
	$(MAKE) test_bin EXTRA_FLAGS="-g -O0"
	valgrind $(VALGRIND_FLAGS) ./test_matrix


s21_matrix_cov.a: $(COV_OBJECTS)
	ar rcs $@ $^
	ranlib $@
	@echo "Library built: $@"


test_bin: $(TEST_OBJECTS) s21_matrix.a
	@echo "Building tests..."
	$(CC) $(CFLAGS) $(TEST_OBJECTS) -L. -l:s21_matrix.a $(TEST_FLAGS) -o test_matrix

test: test_bin
	@echo "Running test..."
	./test_matrix


test_bin_cov: $(TEST_OBJECTS) s21_matrix_cov.a
	@echo "Building coverage binary..."
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(TEST_OBJECTS) -L. -l:s21_matrix_cov.a $(TEST_FLAGS) $(GCOV_FLAGS) -o test_matrix

gcov_report:
	$(MAKE) clean
	$(MAKE) test_bin_cov
	@echo "Running coverage tests..."
	./test_matrix
	lcov -t "s21_matrix" -o coverage.info -c -d .
	genhtml -o report coverage.info
	@echo "Coverage report generated in ./report/index.html"


%_cov.o: %.c s21_matrix.h
	$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $< -o $@

%.o: %.c s21_matrix.h
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -rf *.out test_cases/*.out *.a test_matrix functions/*.o functions/*.gcno functions/*.gcda test_cases/*.o test_cases/tests/*.o report *.info