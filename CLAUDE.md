# Claude Code Governance Instructions for Safety-Critical Railway Software
## VATC (VATP, VATO) Subsystem
### Coding Style Guide Rev 1/A | C Coding Standards Rev 2/A

---

## Purpose

This file instructs Claude Code on the coding standards, naming conventions, and safety governance rules that must be followed when generating or suggesting code for the VATC (VATP, VATO) subsystem. All suggestions must comply with the Software Development Process, MISRA C:2012, and EN 50128 requirements.

---

## 1. AI Governance — Hallucination Prevention

- **Do not generate logic that cannot be traced to an explicit requirement.** Every function, conditional branch, and return value must correspond to a documented system or software requirement.
- **Flag unverifiable assumptions.** If context is insufficient to determine safe behavior, insert a `/* TODO - ClaudeReview: Verify logic against requirement <REQ-ID> */` comment rather than guessing.
- **Do not auto-complete failure handling.** Safety-critical error paths must be explicitly specified; do not infer default error behavior.
- **Do not suppress compiler warnings.** Never suggest pragmas or casts that silence warnings without an accompanying justification comment.
- **Mark all AI-generated code blocks** with a comment: `/* AI-GENERATED: Review required before integration */`

---

## 2. Naming Conventions — VATC (VATP, VATO) Subsystem

The following conventions apply to all VATC (VATP, VATO) code. New code must adhere to these; legacy code may retain its existing conventions for consistency.

| Entity              | Convention              | Abbreviation |
|---------------------|-------------------------|--------------|
| File Names          | Snake Case              | S            |
| Function Names      | Pascal Case with Underscores **or** Camel Case | PU or C |
| Variable Names      | Pascal Case with Underscores **or** Camel Case | PU or C |
| Constants/Literals  | All Caps                | A            |
| Structures/Enums    | Snake Case              | S            |
| Enum Elements       | All Caps                | A            |
| Structure Elements  | Pascal Case with Underscores **or** Camel Case | PU or C |
| Macros              | All Caps                | A            |

### Convention Definitions

- **All Caps (A):** All uppercase, words separated by `_`. Example: `DEFAULT_VALUE`, `MAX_NUM_TRAINS`
- **Snake Case (S):** All lowercase, words separated by `_`. Example: `default_value`, `train_status`
- **Pascal Case (P):** Each word capitalized, no separators. Abbreviations follow same rule. Example: `MainForm`, `EbiScreen`
- **Pascal Case with Underscores (PU):** Each word capitalized, words separated by `_`. Example: `Main_Form`, `Train_Speed`
- **Camel Case (C):** First word lowercase, subsequent words capitalized. Example: `mainForm`, `trainSpeed`

### Naming Rules

- Do not add type indicators to non-pointer variable names (e.g., use `debugLevels`, not `debugLevelsEnum`). Pointer suffix is acceptable: `trainPtr`.
- Names must be self-descriptive but not excessively long.
- Function names must start with a verb. Product/component prefixes are allowed before the verb (e.g., `vatpMbxSendMailbox()` — `vatp` = product, `Mbx` = component, `SendMailbox` = action).
- Reserved language keywords shall not be used as names for any entity.

### Constant Naming Prefixes/Suffixes

| Pattern      | Usage                              | Example                    |
|--------------|------------------------------------|----------------------------|
| `_LEN`       | Array length                       | `MESSAGE_BUFFER_LEN`       |
| `_IDX`       | Array index                        | `DESTINATION_ADDRESS_IDX`  |
| `MAX_`       | Maximum number of items            | `MAX_VEHICLES_IN_TRAIN`    |
| `MIN_`       | Minimum number of items            | `MIN_VEHICLES_IN_TRAIN`    |

---

## 3. General Coding Rules

- **Reserved keywords** shall not be used as names for structs, enums, variables, or functions.
- **Curly brackets `{ }`** are always required for `for`, `do`, `while`, `if`, `else`, and `switch` — even when optional.
- **No magic numbers.** Unnamed numeric constants that lack context or appear repeatedly must be declared as `#define` constants. Simple obvious values (0, 1, 2) and documented equations are acceptable.
- **Boolean evaluations** shall use `TRUE` or `FALSE` only (e.g., `if (Ball_Is_Red == TRUE)`).
- **TODO comments** shall use the `TODO` keyword, with initials or a label indicating origin (e.g., `/* TODO - CEE: Verify bounds check here */`).
- **Dynamic memory** shall only be allocated during initialization time, never at runtime.
- **Function length** should be maintainable; avoid extremely long functions. Splitting must be based on logical cohesion, not arbitrary line counts.
- **Nesting depth** shall not exceed 5 levels unless reduced nesting would harm readability.
- **Data interfaces and file I/O** shall use network byte order (big-endian).
- **`continue` statement** shall not be used.
- **`break` statement** shall only be used to terminate `switch` case blocks.
- **Loop condition variables** shall be initialized immediately before the loop.
- **`for` statement** shall contain only loop-control expressions. Use `while` if additional conditions are needed.
- **Ternary operator** shall only be used for decoding TRUE/FALSE into a BOOL variable. Example: `Var1 = ((Status & BIT_2) != 0) ? TRUE : FALSE;`

---

## 4. Layout and Formatting

- **Indentation:** 4 spaces per level. No tabs (except in Makefiles or where tabs are required by the file type).
- **Line length:** Lines should not exceed 120 characters.
- **Curly brackets** shall always appear on a new line.
- **One statement per line** of source code.
- **Nesting levels** shall be indicated by 4-space indentation per level.
- **Control structure bodies** shall be indented from their control statement.
- **`case` statements** shall be indented from `switch`. Every `switch` must include a `default:` with `break`.
- **Complex arithmetic** shall include a comment explaining the equation. Parentheses shall be used for clarity.
- **Commas and semicolons** shall be followed by one space or a newline.
- **`()` and `[]` operators** shall not have spaces between themselves and their expressions.
- **Unary operators** shall not have a space between the operator and its operand.
- **Structure member selectors** (`->`, `.`) shall not have surrounding spaces.
- **Binary and assignment operators** shall have spaces around them.
- **Keywords** `if`, `else if`, `return`, `for`, `while`, `switch` shall be followed by a space; expressions shall be parenthesized.
- **`sizeof`** shall be followed by a parenthesized expression.
- **`return`** shall be parenthesized for non-void functions; for void functions use `return;`.
- **`else` and `do`** shall be followed by a newline.
- **Multi-line comments:** Comment start/end on same line as the comment text; subsequent lines begin with ` * `.
- **Inline comments** spanning multiple lines shall align vertically.
- **Grammar in comments:** All sentences begin with an uppercase letter and end with a period.

---

## 5. File Standards

- C source files shall use the `.c` extension; header files shall use the `.h` extension.
- Files shall only contain functionally related C functions or utility/library collections.
- **File names** follow Snake Case (S) for VATC subsystem.
- **Header files** shall not contain initializations except for `const` variables.
- **Include guards:** Each header file shall begin with an include guard using an ALL_CAPS identifier matching the filename with `.` replaced by `_`.
- **Every file** shall contain a header block including: copyright notice, product name (e.g., VATP GP), filename, and revision history (date, author, changes).
- **Source file order:**
  1. File header
  2. Included files
  3. Macro definitions (`#define`)
  4. Constants (`#define`)
  5. Global declarations
  6. Local declarations
  7. Function prototypes (including external functions)
  8. Support functions
  9. Main function (if applicable)
- **Header file order:**
  1. File header
  2. Macro definitions, constants, structure declarations, enum declarations
  3. Global variable externs
  4. Function externs

---

## 6. Function Standards

- Functions declared as `void` shall have a single `return;` statement with no return value.
- Unary operators (`-`, `+`, `!`, `~`) shall not be attached to parameters passed into a function.
- Functions shall not be invoked from within the argument list of another function (e.g., `executeMyFunc(Arg1, callFunc())` is not permitted). Note: `sizeof()` is exempt as it is an operator.
- Function pointers passed as parameters shall use `typedef`. Function pointer casts are not permitted (MISRA).
- **Every function** shall include a Doxygen header with:

| Doxygen Tag | Requirement |
|---|---|
| `@brief` | Abstract description. **Required.** |
| `@details` | Detailed logic description. Required for all but trivial functions. |
| `@param[in/out/in,out] <name> - <desc>` | One per parameter. **Required.** |
| `@return` | Return value description. Omit for void functions. |
| `@exception` | Any exceptions/shutdowns inside the function. Omit if none. |

- All local variables shall be declared at the top of the function, immediately after the function name.
- A space shall be placed between the function name and the opening parenthesis, or between the parenthesis and the parameters.

---

## 7. Data and Variable Standards

- **All global and static variables** shall be explicitly initialized in a function (not at the point of declaration, except for arrays).
- **Global variable use** shall be limited. Use only when function scope is insufficient or static memory is required.
- **File-scope global variables** used only within that file shall be declared `static`.
- **Bit fields** shall not be used.
- **Scalar type declarations** shall use standard acronyms (from `r4libSys_api.h` or the table below):

| Acronym   | POSIX Type   |
|-----------|--------------|
| `BOOL`    | `uint8_t`    |
| `UINT_8`  | `uint8_t`    |
| `INT_8`   | `int8_t`     |
| `CHAR`    | `char`       |
| `UINT_16` | `uint16_t`   |
| `INT_16`  | `int16_t`    |
| `UINT_32` | `uint32_t`   |
| `INT_32`  | `int32_t`    |
| `UINT_64` | `uint64_t`   |
| `INT_64`  | `int64_t`    |
| `FLOAT`   | `float`      |
| `DOUBLE`  | `double`     |

- **Pointer size** shall not be assumed.
- **Pointers** shall be properly initialized before use.
- **Pointers to multiple types** shall be declared as `void` type.
- **Array bounds** shall be explicitly checked before indexing, except when: a defined constant is used directly as index, the index is bounded in a `for` loop matching the array size, the element is read-only in a loop conditional with prior check, the calling function performed bounds checks, or the function handles out-of-bounds errors.
- **`float` and `double`** use shall be limited to calculations requiring precision beyond integers.
- **Global variables** shall be documented using `@brief` Doxygen tag.

---

## 8. Constant and Literal Standards

- Constants declared with `#define` that include operators shall have the definition enclosed in parentheses to enforce correct operator precedence.
- Bit patterns shall be declared in hexadecimal in sizes of 1, 2, 4, or 8 bytes (e.g., `0x00CCAFBD` — compliant; `0xCCAFBD` — not compliant).
- Constants shall be documented using `@brief` Doxygen tag.

---

## 9. Structure and Enumeration Standards

- Variables that interface with external subsystems shall not be declared as enumerated types (data size may differ between systems).
- Code shall always reference enumerated identifiers by name, never by assumed numeric equivalent.
- Enumerated types shall not be used as array indexes.
- All structures, structure fields, and enumerations shall be documented with Doxygen (`@brief` for the type; `/** */` or `/**< */` per field/element).
- **`PACKED` attribute** shall be restricted to structures used for network communication.
- Structure typedef declaration shall be separate from tag definition, using `typedef` to enable type reuse.
- Each structure member shall be on its own line.
- The typedef name shall appear on the same line as the closing brace.
- An empty line shall be included after the last element, before the closing brace.

---

## 10. Defensive Programming

- **Integer overflow/underflow** — Before performing arithmetic on fixed-width integer types, check that the result will not exceed the type's range using `<stdint.h>` limits (e.g., `INT64_MIN`, `INT64_MAX`). `[UF_C14_004 / MISRA Rule 12.4]`
- **NULL pointer validation** — All pointer parameters shall be checked against `NULL` before dereferencing. Return an error code (`-1`) if `NULL` is detected. `[UF_C3_003 / MISRA Rule 1.3]`
- **Error-code pattern** — Functions that can produce invalid results shall return `int` (0 = success, -1 = error) and write the result through an output pointer parameter (`*resultPtr`).
- **Return value checking** — Every call to a function returning an error code shall check the return value. Silent discard is not permitted. `[UF_C2_005 / MISRA Dir 4.7]`
- **No silent failures** — Do not use an arithmetic result that could not be validated. Return an error and leave the output pointer unchanged.
- **Variables must be initialized before use** — The value of an object with automatic storage shall not be read before it has been set. `[UF_C11_001 / MISRA Rule 9.1]`

---

## 11. C Coding Rules — Rev 2/A

### 11.1 Compilation and Build

| Rule ID    | Description                                             | MISRA Ref |
|------------|---------------------------------------------------------|-----------|
| UF_C1_001  | All source files shall compile without any errors       | Dir 2.1   |

### 11.2 Code Design

| Rule ID    | Description                                                                  | MISRA Ref |
|------------|------------------------------------------------------------------------------|-----------|
| UF_C2_002  | Sections of code shall not be commented out                                  | Dir 4.4   |
| UF_C2_004  | `typedef`s indicating size and signedness shall be used instead of basic numerical types | Dir 4.6 |
| UF_C2_005  | If a function returns error information, that error information shall be tested | Dir 4.7 |
| UF_C2_007  | A function shall be used in preference to a function-like macro where interchangeable | Dir 4.9 |
| UF_C2_008  | Header file contents shall be protected against multiple inclusion           | Dir 4.10  |

### 11.3 Unused Code

| Rule ID    | Description                                              | MISRA Ref |
|------------|----------------------------------------------------------|-----------|
| UF_C4_001  | A project shall not contain unreachable code             | Rule 2.1  |
| UF_C4_002  | There shall be no dead code                              | Rule 2.2  |
| UF_C4_007  | There should be no unused parameters in functions        | Rule 2.7  |

### 11.4 Types

| Rule ID    | Description                                                                  | MISRA Ref |
|------------|------------------------------------------------------------------------------|-----------|
| UF_C8_001  | Bit-fields shall only be declared with an appropriate type                   | Rule 6.1  |
| UF_C10_001 | Types shall be explicitly specified                                          | Rule 8.1  |
| UF_C10_002 | Function types shall be in prototype form with named parameters              | Rule 8.2  |
| UF_C10_013 | A pointer should point to a `const`-qualified type whenever possible         | Rule 8.13 |
| UF_C12_001 | Operands shall not be of an inappropriate essential type                     | Rule 10.1 |
| UF_C12_003 | An expression value shall not be assigned to an object of a narrower or different essential type | Rule 10.3 |

### 11.5 Literals and Constants

| Rule ID    | Description                                             | MISRA Ref |
|------------|---------------------------------------------------------|-----------|
| UF_C9_001  | Octal constants shall not be used                       | Rule 7.1  |
| UF_C9_002  | A `U`/`u` suffix shall be applied to all unsigned integer constants | Rule 7.2 |
| UF_C9_003  | The lowercase `l` shall not be used in a literal suffix | Rule 7.3  |

### 11.6 Initialization

| Rule ID    | Description                                                          | MISRA Ref |
|------------|----------------------------------------------------------------------|-----------|
| UF_C11_001 | The value of an object shall not be read before it has been set      | Rule 9.1  |
| UF_C11_002 | Initializers for aggregates or unions shall be enclosed in braces    | Rule 9.2  |
| UF_C11_003 | Arrays shall not be partially initialized                            | Rule 9.3  |

### 11.7 Expressions

| Rule ID    | Description                                                                 | MISRA Ref |
|------------|-----------------------------------------------------------------------------|-----------|
| UF_C14_001 | Operator precedence within expressions shall be made explicit with parentheses | Rule 12.1 |
| UF_C14_002 | Right-hand operand of a shift operator shall lie in range `[0, width-1]`   | Rule 12.2 |
| UF_C14_003 | The comma operator shall not be used                                        | Rule 12.3 |
| UF_C14_004 | Evaluation of constant expressions shall not lead to unsigned integer wrap-around | Rule 12.4 |

### 11.8 Control Flow

| Rule ID    | Description                                                          | MISRA Ref |
|------------|----------------------------------------------------------------------|-----------|
| UF_C16_004 | Controlling expressions of `if` and iteration statements shall have essentially Boolean type | Rule 14.4 |
| UF_C17_001 | The `goto` statement shall not be used                               | Rule 15.1 |
| UF_C17_005 | A function shall have a single point of exit at the end              | Rule 15.5 |
| UF_C17_006 | The body of an iteration or selection statement shall be a compound statement | Rule 15.6 |
| UF_C17_007 | All `if … else if` constructs shall be terminated with an `else` statement | Rule 15.7 |

### 11.9 Switch Statements

| Rule ID    | Description                                                          | MISRA Ref |
|------------|----------------------------------------------------------------------|-----------|
| UF_C18_001 | All switch statements shall be well-formed                           | Rule 16.1 |
| UF_C18_003 | An unconditional `break` statement shall terminate every switch-clause | Rule 16.3 |
| UF_C18_004 | Every switch statement shall have a `default` label                  | Rule 16.4 |
| UF_C18_005 | The `default` label shall appear as the first or last switch label   | Rule 16.5 |
| UF_C18_006 | Every switch statement shall have at least two switch-clauses        | Rule 16.6 |

### 11.10 Functions

| Rule ID    | Description                                                                   | MISRA Ref |
|------------|-------------------------------------------------------------------------------|-----------|
| UF_C19_001 | The features of `<stdarg.h>` shall not be used                                | Rule 17.1 |
| UF_C19_002 | Functions shall not call themselves, either directly or indirectly (no recursion) | Rule 17.2 |
| UF_C19_004 | All exit paths from a non-void function shall have an explicit `return` with an expression | Rule 17.4 |
| UF_C19_006 | The value returned by a non-void function shall be used                       | Rule 17.7 |
| UF_C19_007 | A function parameter shall not be modified                                    | Rule 17.8 |

### 11.11 Pointers and Arrays

| Rule ID    | Description                                                          | MISRA Ref |
|------------|----------------------------------------------------------------------|-----------|
| UF_C20_005 | Declarations shall contain no more than two levels of pointer nesting | Rule 18.5 |
| UF_C20_007 | Flexible array members shall not be declared                         | Rule 18.7 |
| UF_C20_008 | Variable-length array types shall not be used                        | Rule 18.8 |

### 11.12 Overlapping Storage

| Rule ID    | Description                          | MISRA Ref |
|------------|--------------------------------------|-----------|
| UF_C21_001 | The `union` keyword shall not be used | Rule 19.2 |

### 11.13 Standard Libraries

| Rule ID    | Description                                                          | MISRA Ref |
|------------|----------------------------------------------------------------------|-----------|
| UF_C23_003 | Memory allocation/deallocation functions of `<stdlib.h>` shall not be used | Rule 21.3 |
| UF_C23_004 | `<setjmp.h>` shall not be used                                       | Rule 21.4 |
| UF_C23_005 | `<signal.h>` shall not be used                                       | Rule 21.5 |
| UF_C23_006 | Standard Library input/output functions shall not be used            | Rule 21.6 |
| UF_C23_007 | `atof`, `atoi`, `atol`, `atoll` of `<stdlib.h>` shall not be used   | Rule 21.7 |
| UF_C23_008 | `abort`, `exit`, `getenv`, `system` of `<stdlib.h>` shall not be used | Rule 21.8 |

### 11.14 Resources

| Rule ID    | Description                                                             | MISRA Ref |
|------------|-------------------------------------------------------------------------|-----------|
| UF_C24_001 | All resources obtained dynamically shall be explicitly released         | Rule 22.1 |

---

## 12. Safety and Traceability Requirements

- Every function generating safety-relevant logic must reference its requirement ID in the header comment (e.g., `/* Implements: SWR-VATP-0042 */`).
- AI-generated failure handling code must be flagged for human review before integration into the safety baseline.
- Static code analysis (e.g., MISRA C:2012 checker) must be run on all AI-assisted code before code review submission.
- Unit test coverage (line, function, and branch) is required for all AI-generated modules.
- AI-generated code shall be marked in the revision history of the file with the label `[AI-ASSISTED]` and the reviewer's name.
- The software development checklist item **"AI-generated code: YES/NO"** must be completed for every module submitted for review.

---

*This file is based on:*
- *C Coding Style Guide — Version 1/A (2023-07-13)*
- *C Coding Standards — Version 2/A (2025-12-04)*
- *AI-Assisted Development Railway Safety Governance Framework*
