//Purpose: selection sort class implementation file
//Name: selectionSort.h
//Author: Mackenzie Zappe
//Date: 9/24/2020
#include <iostream>

class selectionSortMethod{
    public:
    selectionSortMethod(): numSwaps(0), numComparisions(0){} 
    int getNumSwaps() const {return numSwaps;}
    int getNumComparisions() const {return numComparisions;}
    void selectionSort(int arr[], int n);

    private:
    int numSwaps;
    int numComparisions;
    void swap(int *xp, int *yp);


};

void selectionSortMethod::swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
    numSwaps++;
}  
  
void selectionSortMethod::selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);
        numComparisions++;
    } 

} 


/*
template<class DataType>
int findIndexOfLargest(const DataType theArray[], int size)
{
    int indexSoFar = 0; 
    for (int currentIndex = 1; currentIndex < size; currentIndex++)
    {

        if (theArray[currentIndex] > theArray[indexSoFar])
        indexSoFar = currentIndex;
    }
    return indexSoFar; 
} 

template <class T> bool swap ( T& a, T& b )
{

  T c(a); a=b; b=c;
return 1;
}

template<class DataType>
valuesStruct selectionSort (DataType theArray[], int n){

int numSwaps = 0, numComparisons = 0;
int last= n-1;

    for (last=n-1; last>=1; last--)
    {

    int largest = findIndexOfLargest(theArray, last+1);

    if(swap(theArray[largest], theArray[last])){numSwaps++;}
    numComparisons++;


    } 
valuesStruct result;

return  result = {numSwaps, numComparisons};
} 
*/