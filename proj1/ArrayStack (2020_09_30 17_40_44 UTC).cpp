//Name: ArrayStack.cpp
//purpose: implementation of ArrayStack.h
//Author: Mackenzie Zappe
//Date: 9/14/2020

#include "StackArray.h"
#include <iostream>
using namespace std;

template<class DataType>
StackArray<DataType>::StackArray(int maxNumber):top(0), maxSize(maxNumber){}

template<class DataType>
StackArray<DataType>::StackArray(const StackArray& other){
        top = other.top;
        for(size_t i = 0; i <= top; i++){
            dataItems[i] = other.dataItems[i];
        }
}

template<class DataType>
StackArray<DataType>& StackArray<DataType>::operator=(const StackArray& other){
            if(this != &other){
                top = other.top;
                for(size_t i = 0; i < top; i++){
                    dataItems[i] = other.dataItems[i];
                }
                return *this;
            }
            
            return *this;   
}

template<class DataType>
StackArray<DataType>::~StackArray(){
    clear();
}

template<class DataType>
void StackArray<DataType>::push(const DataType& newDataItem) throw (logic_error){
            if(isFull()){
                throw logic_error("Array Full");
            }
            if(top < maxSize){
                top++;
                dataItems[top] = newDataItem;
            } 
}

template<class DataType>
DataType StackArray<DataType>::pop() throw (logic_error){
    if(!isEmpty()){
                top -= 1;
            }
}

template<class DataType>
void StackArray<DataType>:: clear(){
    if(!isEmpty()){
                do{
                    pop();
                }while(!isEmpty());
            }else{
                std::cout << "This stack is empty" << std::endl;
            }
}

template<class DataType>
bool StackArray<DataType>:: isEmpty() const{
            if(top == 0){
                return true;
            }else{
                return false;
            }    
}

template<class DataType>
bool StackArray<DataType>:: isFull() const{
            if(top == (maxSize-1)){
                return true;
            }else{
                return false;
            }   
}

template<class DataType>
void StackArray<DataType>:: showStructure() const{
    if(!isEmpty()){
                for(size_t i = 0; i < top; i++){
                    std::cout << dataItems[i] << " ";
                }
            }else{
                std::cout << "Empty" << std::endl;
            }
            std::cout << std::endl;
}