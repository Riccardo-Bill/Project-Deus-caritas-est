cmake_minimum_required(VERSION 3.16)
project(ProjectDeuscaritasest
        LANGUAGES CXX)

#enable_testing()
#add_subdirectory(test)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Fetch the SFML library
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Add all .c, - files under src/ directory
file(GLOB SOURCES_C CONFIGURE_DEPENDS "src/*.c" "src/*/*.c")
# Add all .cpp, - files under src/ directory
file(GLOB SOURCES_CPP CONFIGURE_DEPENDS "src/*.cpp" "src/*/*.cpp")
# Add all .hpp, - files under src/ directory
file(GLOB SOURCES_HPP CONFIGURE_DEPENDS "src/*.hpp" "src/*/*.hpp")
# Add all .h, - files under src/ directory
file(GLOB SOURCES_H CONFIGURE_DEPENDS "src/*.h" "src/*/*.h")
set(SOURCES ${SOURCES_CPP} ${SOURCES_HPP} ${SOURCES_C} ${SOURCES_H})
# set(SOURCES ${SOURCES_CPP})
message(STATUS "SRC directory source code files: \n\t-- HEADERS: ${SOURCES_H}${SOURCES_HPP}\n\t-- C SOURCES: ${SOURCES_C}\n\t-- CPP SOURCE:${SOURCES_CPP}\n\t-- ALL:${SOURCES}")

add_executable(ProjectDeuscaritasest ${SOURCES})

target_link_libraries(ProjectDeuscaritasest PRIVATE sfml-graphics sfml-graphics sfml-window sfml-audio sfml-network sfml-system)
target_compile_features(ProjectDeuscaritasest PRIVATE cxx_std_17)

add_custom_command(TARGET ProjectDeuscaritasest PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/src/fonts $<TARGET_FILE_DIR:ProjectDeuscaritasest>/fonts)

add_custom_command(TARGET ProjectDeuscaritasest PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/src/data $<TARGET_FILE_DIR:ProjectDeuscaritasest>/data)

install(TARGETS ProjectDeuscaritasest)