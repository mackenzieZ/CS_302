//Purpose: quick sort class implentaions 
//Name: quickSort.cpp
//Author: Mackenzie Zappe
//Date: 9/24/2020

#include <iostream> 

template<class DataType>
void insertionSort (DataType theArray[], int n)
{

    for (int unsorted=1; unsorted < n; unsorted++)
    {
        DataType nextItem = theArray[unsorted];
        int loc = unsorted;
        while ((loc>0) && (theArray[loc-1] > nextItem))
        {
            theArray[loc] = theArray[loc-1];
            loc--;
        } 
        theArray[loc] = nextItem; 
    } 
} 


template<class DataType>
void quickSort(DataType theArray[], int first, int last){
    DataType i = first;
    int j = last, mid, piv, temp;
    mid = first + (last - first)/2;
    piv = theArray[mid];

    while(i < last || j>first){
        while(theArray[i] < piv){
            i++;
        }
        while(theArray[j] > piv){
            j--;
        }
        if(i <=j){
            temp = theArray[i];
            theArray[i] = theArray[j];
            theArray[j] = temp;
            i++;
            j--;
        }else{
            if(i < last){
                quickSort(theArray, i, last);
            }
            if(j > first){
                quickSort(theArray, first, j);
            }
            return;
        }
    }
}
