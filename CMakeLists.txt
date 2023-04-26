cmake_minimum_required(VERSION 3.25)
project(Lab6 C)

set(CMAKE_C_STANDARD 23)

add_library(list source/list.c)
target_include_directories(list PUBLIC include)

add_library(input source/input.c)
target_include_directories(input PUBLIC include)

add_library(numbers source/numbers.c)
target_include_directories(numbers PUBLIC include)

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} list)
target_link_libraries(${PROJECT_NAME} input)
target_link_libraries(${PROJECT_NAME} numbers)