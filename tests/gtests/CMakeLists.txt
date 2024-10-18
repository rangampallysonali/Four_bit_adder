cmake_minimum_required (VERSION 2.6)

# Include GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Find the Threads package
find_package(Threads REQUIRED)

# Specify the source files for the tests
set(SRC_LOGIC 
    ./GTestLogicGates.cpp
    ./GTestHalfAdder.cpp
    ./GTestFullAdder.cpp
    ./GTestFourBitAdder.cpp
)

# Create the executable for LogicGates tests
add_executable(runTests ${SRC_LOGIC})

# Link the libraries: your project, GoogleTest, and Threads
target_link_libraries(runTests proj1_FourBitAdder ${GTEST_LIBRARIES} Threads::Threads)

# Enable testing
enable_testing()
add_test(NAME runTests COMMAND runTests)
