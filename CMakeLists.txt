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
enable_testing()
foreach(SOURCE_PATH ${SRC_TESTS})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_PATH} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_PATH})
    target_link_libraries(${EXECUTABLE_NAME} catch mylib)
    add_test(${EXECUTABLE_NAME} ${EXECUTABLE_NAME})
endforeach(SOURCE_PATH ${SRC_TESTS})

