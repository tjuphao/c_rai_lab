# =============================================================================
# Revision History
# =============================================================================
# Version | Date       | Author  | Description
# --------|------------|---------|---------------------------------------------
# 1.0.0   | 2026-04-09 | tjuphao | Initial build with gcc, gprof profiling
# 1.1.0   | 2026-04-09 | tjuphao | Add CppUTest unit test target (make test)
# 1.2.0   | 2026-04-09 | tjuphao | Add JUnit XML report output to build/
# 1.3.0   | 2026-04-09 | tjuphao | Add lcov coverage target (make coverage)
# =============================================================================

CC = gcc
CXX = g++
# Build configuration
# -g     : enable debugging
# -O0    : no optimization
# -Wall  : show warnings
# -Iinclude : include header directory
# -pg    : enable profiling with gprof
CFLAGS = -g -O0 -Wall -Iinclude -pg
# Build all c files in src directory
SRC = $(wildcard src/*.c)
#output to build/main
OUT = build/main

# Test configuration
CPPUTEST_HOME = /usr/local
TEST_CFLAGS = -g -O0 -Wall -Iinclude -I$(CPPUTEST_HOME)/include
TEST_LDFLAGS = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt
TEST_SRC = $(filter-out src/main.c, $(wildcard src/*.c))
TEST_CPP = $(wildcard test/*.cpp)
TEST_OUT = build/test_runner

# Coverage configuration
COV_CFLAGS = -g -O0 -Wall -Iinclude -I$(CPPUTEST_HOME)/include --coverage
COV_LDFLAGS = -L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt --coverage
COV_OUT = build/coverage_runner

.PHONY: all run test coverage clean

all:
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

test:
	mkdir -p build
	$(CC) $(TEST_CFLAGS) -c $(TEST_SRC) -o build/hello_test.o
	$(CXX) $(TEST_CFLAGS) build/hello_test.o $(TEST_CPP) $(TEST_LDFLAGS) -o $(TEST_OUT)
	./$(TEST_OUT) -ojunit
	@mv cpputest_*.xml build/
	@echo "Report saved to build/cpputest_HelloGroup.xml"

coverage:
	mkdir -p build
	$(CC) $(COV_CFLAGS) -c $(TEST_SRC) -o build/hello_cov.o
	$(CXX) $(COV_CFLAGS) build/hello_cov.o $(TEST_CPP) $(COV_LDFLAGS) -o $(COV_OUT)
	./$(COV_OUT)
	lcov --capture --directory . --output-file build/coverage.info --rc branch_coverage=1 --ignore-errors mismatch,mismatch
	lcov --remove build/coverage.info '/usr/*' '*/test/*' --output-file build/coverage_filtered.info --rc branch_coverage=1 --ignore-errors mismatch,mismatch,unused
	genhtml build/coverage_filtered.info --branch-coverage --output-directory build/coverage_report
	@echo "Coverage report: build/coverage_report/index.html"

clean:
	rm -rf build gmon.out
