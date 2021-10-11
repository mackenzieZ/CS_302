//Purpose: testing quick sort

#include <iostream>

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

template<class DataType>
void selectionSort (DataType theArray[], int n){

    for (int last=n-1; last>=1; last--)
    {

    int largest = findIndexOfLargest(theArray, last+1);

    std::swap(theArray[largest], theArray[last]);
    } 
} 

int main(){

int array[3];
array[0] = 3;
array[1] = 2;
array[2] = 1;

std::cout << "before " << array[0] << array[1] << array[2] << std::endl;

selectionSort(array, 3);

std::cout << "after " << array[0] << array[1] << array[2] << std::endl;


}