
cmake_minimum_required(VERSION 3.10)

project(project11)

include_directories(mergeSort.hpp selectionSort.hpp)

add_executable(testingSortingAlgorithms testingSortingAlgorithms.cpp)
add_executable(sortingTest sortingTest.cpp)

