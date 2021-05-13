# cmake-template
Boilerplate for establishing a new C++ project using CMake.

## Instructions

1. Add a `your-project-name` directory to the [include](include) and [src](src) directories, this is where you will put your `.hpp` and `.cpp` files respectively.

2. Add at least one source file to be compiled.

4. Add the source files to the `${LIB_NAME}` target in the `add_library` call of the root [CMakeLists.txt](CMakeLists.txt).

5. Add additional tests as `.cpp` files under the `test` directory. Update the `${ALL_TESTS}` variable to include the name/path of the new test, without the `.cpp` extension.

6. Build with `cmake .` or `cmake . -GNinja` to use [ninja](https://github.com/ninja-build/ninja) instead.

## Testing

Tests use the [gtest framework](https://github.com/google/googletest). If gtest is not installed on your system, tests will not be enabled.

- If built with `make`, tests can be ran with `make test`. Verbose tests can be ran with `ctest --verbose`.
- If built with `ninja`, tests can be ran with `ninja test`.
