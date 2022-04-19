cmake_minimum_required(VERSION 3.21)
project(Sem2)

set(CMAKE_CXX_STANDARD 11)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(Task1 PracticeSTL/Task1.cpp)
add_executable(Task2 PracticeSTL/Task2.cpp)
add_executable(Task3 PracticeSTL/Task3.cpp)
add_executable(Task4 PracticeSTL/Task4.cpp)
add_executable(Task5 PracticeSTL/Task5.cpp)
add_executable(Task6 PracticeSTL/Task6.cpp)

add_executable(Storage Exceptions/Storage.cpp)
add_executable(Connector Exceptions/Connector.cpp)
