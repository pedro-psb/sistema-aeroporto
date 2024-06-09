cmake_minimum_required(VERSION 3.20.0)
project(hello_prj)

file(GLOB SRC "src/*.cpp")
file(GLOB SRC_TESTS "tests/*_test.cpp")

# adicionar bibliotecas
add_library(catch lib/catch.cpp)
add_library(mylib ${SRC})

# criar executavel unit_test linkada com:
# - nossa biblioteca
# - lib de testes (catch2)
# add_executable(end_to_end_test tests/end_to_end_test.cpp)
# target_link_libraries(end_to_end_test catch mylib)

foreach(SOURCE_PATH ${SRC_TESTS})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_PATH} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_PATH})
    target_link_libraries(${EXECUTABLE_NAME} catch mylib)
endforeach(SOURCE_PATH ${SRC_TESTS})
