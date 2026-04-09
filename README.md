# c_rai_lab

A safety-critical C development lab for the vehicle subsystem, following the Software Development Process and coding standard.

---

## Prerequisites

| Tool     | Version  | Purpose                          |
|----------|----------|----------------------------------|
| GCC      | 13.3.0   | C compiler                       |
| G++      | 13.3.0   | C++ compiler (for CppUTest)      |
| CppUTest | 4.0      | Unit test framework              |
| LCOV     | 2.0-1    | Code coverage reporting          |
| genhtml  | 2.0-1    | HTML coverage report generator   |

### Install dependencies

```bash
sudo apt-get install -y gcc g++ lcov
```

CppUTest is installed to `/usr/local`. To build from source:

```bash
git clone https://github.com/cpputest/cpputest.git
cd cpputest && mkdir build && cd build
cmake .. && make && sudo make install
```

---

## Project Structure

```
c_rai_lab/
├── include/
│   └── hello.h          # Function declarations
├── src/
│   ├── hello.c          # Implementation (say_hello, add, divide)
│   └── main.c           # Application entry point
├── test/
│   ├── AllTests.cpp     # CppUTest runner main
│   └── HelloTest.cpp    # Unit tests for hello.c
├── build/               # All build artefacts (generated)
│   ├── main             # Application binary
│   ├── test_runner      # Test binary
│   ├── coverage_runner  # Coverage-instrumented test binary
│   ├── cpputest_HelloGroup.xml   # JUnit XML test report
│   └── coverage_report/ # LCOV HTML coverage report
├── Makefile
├── CLAUDE.md            # AI code governance instructions
└── README.md
```

---

## Makefile Commands

### `make` / `make all`

Compiles all source files in `src/` into the application binary at `build/main`.

- Compiler flags: `-g -O0 -Wall -pg` (debug symbols, no optimisation, all warnings, gprof profiling)

```bash
make
```

---

### `make run`

Builds the application (if not already built) and runs it.

```bash
make run
```

---

### `make test`

Compiles the unit tests using CppUTest and runs them. Produces:

- Console output showing pass/fail per test
- JUnit XML report at `build/cpputest_HelloGroup.xml`

```bash
make test
```

Example output:

```
.....
OK (5 tests, 5 ran, 6 checks, 0 ignored, 0 filtered out, 0 ms)
Report saved to build/cpputest_HelloGroup.xml
```

---

### `make coverage`

Compiles the source and tests with `--coverage` instrumentation, runs the tests, and generates an LCOV HTML coverage report.

Produces:
- `build/coverage.info` — raw coverage data
- `build/coverage_filtered.info` — filtered (test files and system headers excluded)
- `build/coverage_report/index.html` — interactive HTML report

```bash
make coverage
# Then open the report:
xdg-open build/coverage_report/index.html
```

Example summary:

```
lines......: 72.7% (8 of 11 lines)
functions..: 66.7% (2 of 3 functions)
branches...: 100.0% (4 of 4 branches)
```

---

### `make clean`

Removes all build artefacts including binaries, object files, coverage data, and gprof output.

```bash
make clean
```

---

## Unit Tests

Tests are written in C++ using CppUTest and located in `test/HelloTest.cpp`.

| Test Name                   | Function  | Description                              |
|-----------------------------|-----------|------------------------------------------|
| `AddPositiveNumbers`        | `add()`   | Verifies 2 + 3 = 5                       |
| `AddNegativeNumbers`        | `add()`   | Verifies -3 + 2 = -1                     |
| `DivideSuccess`             | `divide()`| Verifies 10 / 2 = 5, returns 0          |
| `DivideByZeroReturnsError`  | `divide()`| Verifies b=0 returns -1                  |
| `DivideNullPtrReturnsError` | `divide()`| Verifies NULL result pointer returns -1  |

---

## Coding Standard

All code follows **Software Development Process — Guideline** with the **vehicle** naming conventions:

| Entity             | Convention                            |
|--------------------|---------------------------------------|
| File Names         | Snake Case (`hello_world.c`)          |
| Function Names     | Pascal Case with Underscores or Camel Case |
| Variable Names     | Pascal Case with Underscores or Camel Case |
| Constants/Macros   | All Caps (`MAX_TRAINS`)               |
| Structures/Enums   | Snake Case (`train_status`)           |
| Enum Elements      | All Caps (`TRAIN_FORWARD`)            |
| Structure Elements | Pascal Case with Underscores or Camel Case |

AI-generated code is marked with `/* AI-GENERATED: Review required before integration */` and labelled `[AI-ASSISTED]` in revision history.

---

## Revision History

| Version | Date       | Author                | Description                              |
|---------|------------|-----------------------|------------------------------------------|
| 1.0.0   | 2026-04-09 | tjuphao               | Initial build with gcc, gprof profiling  |
| 1.1.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Add CppUTest unit test target            |
| 1.2.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Add JUnit XML report output to build/    |
| 1.3.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Add lcov coverage target                 |
