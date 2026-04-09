# c_rai_lab

A safety-critical C development lab for the vehicle subsystem, following the Software Development Process and coding standard.

---

## Prerequisites

| Tool     | Version  | Purpose                          |
|----------|----------|----------------------------------|
| GCC      | 13.3.0   | C compiler                       |
| GCC-14   | 14.x     | C compiler for MC/DC coverage    |
| G++      | 13.3.0   | C++ compiler (for CppUTest)      |
| G++-14   | 14.x     | C++ compiler for MC/DC coverage  |
| CppUTest | 4.0      | Unit test framework              |
| LCOV     | 2.0-1    | Code coverage reporting          |
| genhtml  | 2.0-1    | HTML coverage report generator   |

### Install dependencies

```bash
sudo apt-get install -y gcc g++ lcov gcc-14 g++-14
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
│   └── hello.h          # Function declarations (say_hello, add, divide, subtract)
├── src/
│   ├── hello.c          # Implementation (add, divide, subtract)
│   └── main.c           # Application entry point
├── test/
│   ├── AllTests.cpp     # CppUTest runner main
│   └── HelloTest.cpp    # Unit tests for hello.c
├── requirements/
│   └── Requirements.csv # Software requirements
├── build/               # All build artefacts (generated)
│   ├── main             # Application binary
│   ├── test_runner      # Test binary
│   ├── coverage_runner  # Coverage-instrumented test binary
│   ├── mcdc_runner      # MC/DC-instrumented test binary
│   ├── cpputest_HelloGroup.xml   # JUnit XML test report
│   ├── coverage_report/ # LCOV HTML coverage report
│   └── mcdc_report/     # LCOV MC/DC HTML coverage report
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
...........
OK (11 tests, 11 ran, 17 checks, 0 ignored, 0 filtered out, 0 ms)
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
lines......: 100.0% (22 of 22 lines)
functions..: 100.0% (3 of 3 functions)
branches...: 100.0% (12 of 12 branches)
```

---

### `make mcdc`

Compiles the source and tests with `-fcondition-coverage` (GCC 14 required) for MC/DC coverage, runs the tests, and generates an LCOV HTML MC/DC report.

Produces:
- `build/mcdc.info` — raw MC/DC coverage data
- `build/mcdc_filtered.info` — filtered coverage data
- `build/mcdc_report/index.html` — interactive HTML MC/DC report

```bash
make mcdc
# Then open the report:
xdg-open build/mcdc_report/index.html
```

Example summary:

```
lines......: 100.0% (22 of 22 lines)
functions..: 100.0% (3 of 3 functions)
branches...: 100.0% (12 of 12 branches)
```

> **Note:** Requires GCC 14 (`gcc-14`, `g++-14`). The `-fcondition-coverage` flag is not available in earlier GCC versions.

---

### `make clean`

Removes all build artefacts including binaries, object files, coverage data, gprof output, and `.gcov` files.

```bash
make clean
```

---

## Unit Tests

Tests are written in C++ using CppUTest and located in `test/HelloTest.cpp`.

| Test Name                              | Function      | Description                                        |
|----------------------------------------|---------------|----------------------------------------------------|
| `AddPositiveNumbers`                   | `add()`       | Verifies 2 + 3 = 5                                 |
| `AddNegativeNumbers`                   | `add()`       | Verifies -3 + 2 = -1                               |
| `DivideSuccess`                        | `divide()`    | Verifies 10 / 2 = 5, returns 0                    |
| `DivideByZeroReturnsError`             | `divide()`    | Verifies b=0 returns -1                            |
| `DivideNullPtrReturnsError`            | `divide()`    | Verifies NULL result pointer returns -1            |
| `SubtractSuccess`                      | `subtract()`  | Verifies 10 - 3 = 7, returns 0                    |
| `SubtractNegativeResult`               | `subtract()`  | Verifies 3 - 10 = -7, returns 0                   |
| `SubtractNullPtrReturnsError`          | `subtract()`  | Verifies NULL result pointer returns -1            |
| `SubtractUnderflowReturnsError`        | `subtract()`  | Verifies INT64_MIN - 1 returns -1 (underflow)      |
| `SubtractOverflowReturnsError`         | `subtract()`  | Verifies INT64_MAX - (-1) returns -1 (overflow)    |
| `SubtractNegativeSubtrahendNoOverflow` | `subtract()`  | Verifies 5 - (-3) = 8, no overflow, returns 0     |

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

| Version | Date       | Author                | Description                                        |
|---------|------------|-----------------------|----------------------------------------------------|
| 1.0.0   | 2026-04-09 | tjuphao               | Initial build with gcc, gprof profiling            |
| 1.1.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Add CppUTest unit test target                      |
| 1.2.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Add JUnit XML report output to build/              |
| 1.3.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Add lcov coverage target                           |
| 1.4.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Add MC/DC coverage target (make mcdc, GCC 14)      |
| 1.5.0   | 2026-04-09 | tjuphao [AI-ASSISTED] | Add subtract() with overflow/underflow detection   |
