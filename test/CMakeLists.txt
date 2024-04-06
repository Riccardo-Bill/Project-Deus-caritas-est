cmake_minimum_required(VERSION 3.16)
project(tests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Add all .c, - files under src/ directory
file(GLOB SOURCES_C CONFIGURE_DEPENDS "../src/*.c")
# Add all .cpp, - files under src/ directory
file(GLOB SOURCES_CPP CONFIGURE_DEPENDS "../src/*.cpp")
# Remove main.cpp since googletest already has this defined, all of these are added to make sure it stays away
list(REMOVE_ITEM SOURCES_CPP ${CMAKE_SOURCE_DIR}/../src/main.cpp)
list(REMOVE_ITEM SOURCES_CPP ${CMAKE_CURRENT_SOURCE_DIR}/../src/main.cpp)
list(REMOVE_ITEM SOURCES_CPP ../src/main.cpp)
list(REMOVE_ITEM SOURCES_CPP "../src/main.cpp")

# Add all .hpp, - files under src/ directory
file(GLOB SOURCES_HPP CONFIGURE_DEPENDS "../src/*.hpp")
# Add all .h, - files under src/ directory
file(GLOB SOURCES_H CONFIGURE_DEPENDS "../src/*.h")
file(GLOB SOURCES_TEST CONFIGURE_DEPENDS "*.cpp")
set(SOURCES ${SOURCES_CPP} ${SOURCES_HPP} ${SOURCES_C} ${SOURCES_H} ${SOURCES_TEST})
message(STATUS "SRC directory source code files: \n\t-- HEADERS: ${SOURCES_H}${SOURCES_HPP}\n\t-- C SOURCES: ${SOURCES_C}\n\t-- CPP SOURCE:${SOURCES_CPP}\n\t-- ALL:${SOURCES}")

add_executable(
  hello_test
  ${SOURCES}
)
target_link_libraries(
  hello_test
  GTest::gtest_main
  sfml-graphics sfml-graphics sfml-window sfml-audio sfml-network sfml-system
)

install(TARGETS hello_test)

include(GoogleTest)
gtest_discover_tests(hello_test)
