# Lesson 1
Learn C++11 from basics

### Flag for g++ compiler
`g++ --std=c++11 foo.cpp -o foo`

### Initialization
Use the following 2 ways to initialize a variable. The old () initialization is still available and should be used in some cases.

* `int ii{2.3};`
{} is the preferred way of initializing variables. {} does not allow _narrowing initializations_, e.g. the above example would cause compilation error.

* `int ii = 2.3;`
This does NOT cause a compilation error. the value in `ii` is simply converted into an integer.

### Flag for adding DEFINE parameters during compilation
`g++ -DMY_MACRO=macro`
This is equivalent to `#define` in the cpp code. This goes together with the macro usages in code implementation.

### Keyword 'auto'
`auto a{45};`
This keyword can be used for unambiguous cases to make the code simple to read. `auto` can also be used on functions.

### Keyword 'decltype'
`decltype(ii) jj{6};`
This keyword means that variable `jj` would have the same type as variable `ii`.

### namespace
`namespace UnitedKingdom {...}`
This defines a namespace in which variables and functions can be defined. Line `using namespace foo` imports all names in `foo` to current scope. Use `::` when specifying single variable/function in namespace.
* `namespace` is used to avoid name clash, not for taxonomy.
* Unnamed namespace can be used to define independent scope in different files.
* Inline namespace can be used for versioning purpose. (Default namespace)
