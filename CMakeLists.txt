cmake_minimum_required(VERSION 3.10)
project(mtg_turing)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable testing
enable_testing()

# Create library from your class implementations
add_library(mtg_lib
    src/main.cpp
    src/Game.cpp
    src/Game.h
    src/Creature.h
    src/Permanent.h
    src/Stack.h
    src/Trigger.h
    src/Event.h
    src/Action.h
    src/Event.cpp 
    src/Permanent.cpp
    src/Action.cpp
    src/Trigger.cpp
    src/Creature.cpp
    src/Stack.cpp
)

# Create main executable
add_executable(mtg_turing 
    src/main.cpp 
    src/Game.cpp 
    src/Event.cpp 
    src/Permanent.cpp
    src/Action.cpp
    src/Trigger.cpp
    src/Creature.cpp
    src/Stack.cpp
)
target_link_libraries(mtg_turing mtg_lib)

# Create test executable
add_executable(tests tests/test_main.cpp)
target_link_libraries(tests mtg_lib)

# Register tests with CTest
add_test(NAME RecipeTests COMMAND tests)

