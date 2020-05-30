# Lesson 2
C++ pointers and standard library strings

### Basics of pointers
Review variables, pointers and references. Pointers and references apply to the same
initialization way in C++11.

### Character strings
Well-defined functions (e.g. size) and takes cares of memory. Also supports simple
syntax (e.g. `=`, `+`, `<, ==, >`).

### Raw string literals
`string msg{R"(...)"};`
Can contain line breaks, escape characters without escaping (`\`). Starts with `R"(`
and ends with `)"`.

### Conversion to and from strings
STL `string` class provides inter-conversion with type `int` and `double`. Some
functions include `atoi`, `strtod`, `sprintf`, `to_string`, ...
