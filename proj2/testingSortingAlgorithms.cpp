//Purpose: Testing selection sort and merge sort on randomly generated values
//Name:testingSortingAlgorithms.cpp
//Author:Mackenzie Zappe
//Date:10/4/2020


#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <chrono>

#include "mergeSort.hpp"
#include "selectionSort.hpp"

#define THOUSAND 1000
#define TEN_THOUSAND 10000
#define HUNDRED_THOUSAND 100000
#define MILLION 1000000

using namespace std::chrono;

template<class DataType>
void printArray(DataType array[], int size){
    for(int i = 0; i < size; i++){
        std::cout << array[i] << ' ' ;
    }
    std::cout << std::endl;
}


int main(){

//seed the random generator
srand(time(NULL));

//create/open output files
std::ofstream resultsofRuns;
std::ofstream averagesofRuns;
resultsofRuns.open("Results.txt");
averagesofRuns.open("Averages.txt");
resultsofRuns << "=====Results======" << std::endl;
averagesofRuns << "=====Averages======" << std::endl;

int array1ms[THOUSAND], array1ss[THOUSAND];
int array2ms[TEN_THOUSAND], array2ss[TEN_THOUSAND];
int array3ms[HUNDRED_THOUSAND], array3ss[HUNDRED_THOUSAND];

int totalDuration1ms = 0 , totalDuration1ss = 0, totalDuration2ms = 0, totalDuration2ss = 0, totalDuration3ms = 0, totalDuration3ss = 0;
int totalSwaps1ms = 0 , totalSwaps1ss = 0, totalSwaps2ms = 0, totalSwaps2ss = 0, totalSwaps3ms = 0, totalSwaps3ss = 0;
int totalComparisions1ms = 0 , totalComparisions1ss = 0, totalComparisions2ms = 0, totalComparisions2ss = 0, totalComparisions3ms = 0, totalComparisions3ss = 0;

float averageDuration1ms = 0 , averageDuration1ss = 0, averageDuration2ms = 0, averageDuration2ss = 0, averageDuration3ms = 0, averageDuration3ss = 0;
float averageSwaps1ms = 0 , averageSwaps1ss = 0, averageSwaps2ms = 0, averageSwaps2ss = 0, averageSwaps3ms = 0, averageSwaps3ss = 0;
float averageComparisions1ms = 0 , averageComparisions1ss = 0, averageComparisions2ms = 0, averageComparisions2ss = 0, averageComparisions3ms = 0, averageComparisions3ss = 0;

mergeSortMethod ms;
selectionSortMethod ss;

for(int k = 0; k < 10; k++){
    resultsofRuns << "+ Run "  << k+1;
    for(int j = 0; j < 50; j++){
        resultsofRuns << " +";
    }
    resultsofRuns << "\n";
    //Assigning values for THOUSAND runs
    for (int i = 0; i < THOUSAND; i++){
        array1ms[i] = array1ss[i] = (rand() % MILLION+1);
    }
    //Assigning values for TEN_THOUSAND runs
    for (int i = 0; i < TEN_THOUSAND; i++){
        array2ms[i] = array2ss[i] = (rand() % MILLION+1);
    }
    //Assigning values for HUNDRED_THOUSAND runs
    for (int i = 0; i < HUNDRED_THOUSAND; i++){
        array3ms[i] = array3ss[i] = (rand() % MILLION+1);
    }

    //Sorting THOUSAND values 
    resultsofRuns << std::setw(32) << "Sorting THOUSAND values " << std::setw(10) << "\tMerge Sort " << std::setw(15) << "\tSelection Sort" << std::endl;
    //Merge Sort
    
    auto startms1 = high_resolution_clock::now();
    ms.startMergeSort(array1ms, 0, THOUSAND-1 );
    auto stopms1 = high_resolution_clock::now();
    auto durationms1 = duration_cast<microseconds>(stopms1 - startms1).count();
    totalDuration1ms += durationms1;
    totalSwaps1ms += ms.getNumSwaps();
    totalComparisions1ms += ms.getNumComparisions();
    
    //Selection Sort

    auto startss1 = high_resolution_clock::now();
    ss.selectionSort(array1ss, THOUSAND);
    auto stopss1 = high_resolution_clock::now();
    auto durationss1 = duration_cast<microseconds>(stopss1 - startss1).count();
    totalDuration1ss += durationss1;
    totalSwaps1ss += ss.getNumSwaps();
    totalComparisions1ss += ss.getNumComparisions();
    
    //exporting data to file
    resultsofRuns << std::setw(32) << "Duration (microsec) " << "\t" << std::setw(10) << durationms1 << "\t" <<  std::setw(14) << durationss1 << std::endl;
    resultsofRuns << std::setw(32) << "Swaps " << "\t" << std::setw(10) << ms.getNumSwaps() << "\t" <<  std::setw(14) <<ss.getNumSwaps() << std::endl;
    resultsofRuns << std::setw(32) << "Comparisions " << "\t" << std::setw(10) << ms.getNumComparisions() << "\t" <<  std::setw(14) <<ss.getNumComparisions() << std::endl;

    //Sorting TEN THOUSAND Values
    resultsofRuns << std::setw(32) << "Sorting TEN_THOUSAND values " << std::setw(10) << "\tMerge Sort " << std::setw(15) << "\tSelection Sort" << std::endl;
    //Merge Sort
    auto startms2 = high_resolution_clock::now();
    ms.mergeSort(array2ms, 0, TEN_THOUSAND-1 );
    auto stopms2 = high_resolution_clock::now();
    auto durationms2 = duration_cast<microseconds>(stopms2 - startms2).count();
    totalDuration2ms += durationms2;
    totalSwaps2ms += ms.getNumSwaps();
    totalComparisions2ms += ms.getNumComparisions();

    //Selection Sort
    auto startss2 = high_resolution_clock::now();
    ss.selectionSort(array2ss, THOUSAND);
    auto stopss2 = high_resolution_clock::now();
    auto durationss2 = duration_cast<microseconds>(stopss2 - startss2).count();
    totalDuration2ss += durationss2;
    totalSwaps2ss += ss.getNumSwaps();
    totalComparisions2ss += ss.getNumComparisions();

    //exporting data to file
    resultsofRuns << std::setw(32) << "Duration (microsec) " << "\t" << std::setw(10) << durationms1 << "\t" <<  std::setw(14) << durationss1 << std::endl;
    resultsofRuns << std::setw(32) << "Swaps " << "\t" << std::setw(10) << ms.getNumSwaps() << "\t" <<  std::setw(14) <<ss.getNumSwaps() << std::endl;
    resultsofRuns << std::setw(32) << "Comparisions " << "\t" << std::setw(10) << ms.getNumComparisions() << "\t" <<  std::setw(14) <<ss.getNumComparisions() << std::endl;



    //Sorting HUNDRED THOUSAND values
    resultsofRuns << std::setw(32) << "Sorting HUNDRED_THOUSAND values " << std::setw(10) << "\tMerge Sort " << std::setw(15) << "\tSelection Sort" << std::endl;
    //Merge Sort
    auto startms3 = high_resolution_clock::now();
    ms.mergeSort(array3ms, 0, HUNDRED_THOUSAND-1 );
    auto stopms3 = high_resolution_clock::now();
    auto durationms3 = duration_cast<microseconds>(stopms3 - startms3).count();
    totalDuration3ms += durationms3;
    totalSwaps3ms += ms.getNumSwaps();
    totalComparisions3ms += ms.getNumComparisions();

    //Selection Sort
    auto startss3 = high_resolution_clock::now();
    ss.selectionSort(array3ss, THOUSAND);
    auto stopss3 = high_resolution_clock::now();
    auto durationss3 = duration_cast<microseconds>(stopss3 - startss3).count();
    totalDuration3ss += durationss3;
    totalSwaps3ss += ss.getNumSwaps();
    totalComparisions3ss += ss.getNumComparisions();

    //exporting data to file
    resultsofRuns << std::setw(32) << "Duration (microsec) " << "\t" << std::setw(10) << durationms1 << "\t" <<  std::setw(14) << durationss1 << std::endl;
    resultsofRuns << std::setw(32) << "Swaps " << "\t" << std::setw(10) << ms.getNumSwaps() << "\t" <<  std::setw(14) <<ss.getNumSwaps() << std::endl;
    resultsofRuns << std::setw(32) << "Comparisions " << "\t" << std::setw(10) << ms.getNumComparisions() << "\t" <<  std::setw(14) <<ss.getNumComparisions() << std::endl;

}

averageDuration1ms = totalDuration1ms/10;
averageDuration1ss = totalDuration1ss/10;
averageDuration2ms = totalDuration2ms/10;
averageDuration2ss = totalDuration2ss/10;
averageDuration3ms = totalDuration3ms/10;
averageDuration3ss = totalDuration3ss/10;

averageSwaps1ms = totalSwaps1ms/10;
averageSwaps1ss = totalSwaps1ss/10;
averageSwaps2ms = totalSwaps2ms/10;
averageSwaps2ss = totalSwaps2ss/10;
averageSwaps3ms = totalSwaps3ms/10;

std::cout << totalSwaps3ms << " " << averageSwaps3ms << std:: endl;

averageComparisions1ms = totalComparisions1ms/10;
averageComparisions1ss = totalComparisions1ss/10;
averageComparisions2ms = totalComparisions2ms/10;
averageComparisions2ss = totalComparisions2ss/10;
averageComparisions3ms = totalComparisions3ms/10;
averageComparisions3ss = totalComparisions3ss/10;

averagesofRuns << std::setw(32) << "Sorting THOUSAND values " << std::setw(10) << "\tMerge Sort " << std::setw(15) << "\t\tSelection Sort" << std::endl;
averagesofRuns << std::setw(32) << "Average Duration " << "\t" << std::setw(10) << averageDuration1ms << "\t" << std::setw(15) << averageDuration1ss << std::endl;
averagesofRuns << std::setw(32) << "Average Swaps "<< std::setw(10) << "\t" << averageSwaps1ms << std::setw(15) << averageSwaps1ss << std::endl;
averagesofRuns << std::setw(32) << "Average Comparisions "<< std::setw(10) << "\t" << averageComparisions1ms << std::setw(15) << averageComparisions1ss << std::endl;

averagesofRuns << std::setw(32) << "Sorting TEN_THOUSAND values " << std::setw(10) << "\tMerge Sort " << std::setw(15) << "\t\tSelection Sort" << std::endl;
averagesofRuns << std::setw(32) << "Average Duration (microsec) " << "\t" << std::setw(10) << averageDuration2ms << "\t" <<  std::setw(14) << averageDuration2ss<< std::endl;
averagesofRuns << std::setw(32) << "Average Swaps " << "\t" << std::setw(10) << averageSwaps2ms << "\t" <<  std::setw(14) <<averageSwaps2ss<< std::endl;
averagesofRuns << std::setw(32) << "Average Comparisions " << "\t" << std::setw(10) << averageComparisions2ms<< "\t" <<  std::setw(14) <<averageComparisions2ss << std::endl;

averagesofRuns << std::setw(32) << "Sorting HUNDRED_THOUSAND values " << std::setw(10) << "\tMerge Sort " << std::setw(15) << "\t\tSelection Sort" << std::endl;
averagesofRuns << std::setw(32) << "Average Duration (microsec) " << "\t" << std::setw(10) << averageDuration3ms << "\t" <<  std::setw(14) << averageDuration3ss<< std::endl;
averagesofRuns << std::setw(32) << "Average Swaps " << "\t" << std::setw(10) << averageSwaps3ms << "\t" <<  std::setw(14) <<averageSwaps3ss<< std::endl;
averagesofRuns << std::setw(32) << "Average Comparisions " << "\t" << std::setw(10) << averageComparisions3ms<< "\t" <<  std::setw(14) <<averageComparisions3ss << std::endl;

resultsofRuns.close();
averagesofRuns.close();
return 0;
}
