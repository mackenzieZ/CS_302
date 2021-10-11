//Purpose: to test the different sorting algorithms that I selected for this project: selection and merge.
//Author: Mackenzie Zappe
//Date:10/6/2020

#include <iostream> 
#include "mergeSort.hpp"
#include "selectionSort.hpp"
#include <time.h>
#include <chrono>
using namespace std::chrono;

#define TEN 10
#define HUNDRED 100

void printArray(int arr[]){
    for(int i =0; i < 10; i++){
    std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(){

srand(time(NULL));

int arrayMS[TEN], arraySS[TEN];
selectionSortMethod ss;
mergeSortMethod ms;

for(int i =0; i < 10; i++){
    arrayMS[i]=arraySS[i] = (rand()% HUNDRED+1);
}

std::cout << "Testing Selection Sort " << std::endl << "Before: ";
printArray(arraySS);
auto s1 = high_resolution_clock::now();
ss.selectionSort(arraySS, TEN);
auto s2 = high_resolution_clock::now();
auto durationSS = duration_cast<microseconds>(s2 - s1).count();
std::cout  << "After : ";
printArray(arraySS);

std::cout << "Testing MergeSort " << std::endl << "Before: ";
printArray(arrayMS);
auto s3 = high_resolution_clock::now();
ms.mergeSort(arrayMS,0, TEN-1);
auto s4 = high_resolution_clock::now();
auto durationMS = duration_cast<microseconds>(s3 - s4).count();
std::cout  << "After : ";
printArray(arrayMS);

std::cout << "Testing Duration, Swaps, Comparisions" << std::endl;
std::cout << "Duration SS: " << durationSS << " Duration MS:" << durationMS << std::endl;
std::cout << "Swaps SS " << ss.getNumSwaps() << " Swaps MS: " << ms.getNumSwaps() << std::endl;
std::cout << "Comparisions SS " << ms.getNumComparisions() << " Comparisions MS: " << ms.getNumComparisions() << std::endl; 

return 0;
}