cmake_minimum_required(VERSION 3.20.0)
project(hello_prj)

file(GLOB SRC "src/*.cpp") # arquivos da nossa biblioteca
file(GLOB SRC_TESTS "tests/*_test.cpp") # testes automatizados com catch2
file(GLOB SRC_EXAMPLES "examples/*.cpp") # testes manuais c/ main
# file(GLOB SRC_MOCKS "tests/mocks/*.cpp") # mocks/fixtures

# adicionar bibliotecas
add_library(catch lib/catch.cpp)
add_library(mylib ${SRC})
# add_library(test_mocks ${SRC_MOCKS})


# criar executavel dos testes automatizados. Linka com:
# - nossa biblioteca
# - lib de testes (catch2)
enable_testing()
foreach(SOURCE_PATH ${SRC_TESTS})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_PATH} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_PATH})
    target_link_libraries(${EXECUTABLE_NAME} catch mylib)
    add_test(${EXECUTABLE_NAME} ${EXECUTABLE_NAME})
endforeach(SOURCE_PATH ${SRC_TESTS})

# criar executavel dos testes manuais. Linka com:
# - nossa biblioteca
foreach(SOURCE_PATH ${SRC_EXAMPLES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_PATH} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE_PATH})
    target_link_libraries(${EXECUTABLE_NAME} mylib)
endforeach(SOURCE_PATH ${SRC_TESTS})

