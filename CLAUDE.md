# Project: c_rai_lab

## Build System
- Compiler: `gcc` with flags `-g -O0 -Wall -Iinclude -pg`
- Source files: `src/*.c`
- Headers: `include/`
- Output: `build/main`
- Build: `make`, Run: `make run`, Clean: `make clean`

## Coding Standards

### General
- Write standard C (C99 or later)
- Keep functions small and focused on a single responsibility

### Naming
- Functions and variables: `snake_case`
- Constants and macros: `UPPER_SNAKE_CASE`
- Header guards: `FILENAME_H`

### Files
- Place source files in `src/`, headers in `include/`
- Each module gets a `.c` file in `src/` and a corresponding `.h` in `include/`

### Headers
- Always use header guards
- Include only what is needed

### Error Handling
- Check return values of `malloc`, file I/O, and other fallible calls
- Free all allocated memory before returning

### Style
- 4-space indentation
- Opening brace on the same line as the statement
- Declare variables at the top of their scope