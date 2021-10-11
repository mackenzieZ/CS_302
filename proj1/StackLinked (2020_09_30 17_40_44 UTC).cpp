//Name: StackLinked.cpp
//Purpose: implementation of the linked stack as delaresd in StackLinked.h
//Author:Mackenzie Zappe
//Date:9/7/2020

#include "StackLinked.h"
#include <iostream>
using namespace std;

template<class DataType>
StackLinked<DataType>::StackLinked(int maxNumber)
: topPtr(nullptr) {}

template<class DataType>
StackLinked<DataType>::StackLinked(const StackLinked&other)
{
    StackNode* otherPtr = other.topPtr;
    if(otherPtr == nullptr){
        topPtr = nullptr;
    }else{
        StackNode* newPtr = topPtr;
        while(otherPtr != nullptr){
            newPtr = new StackNode(otherPtr->dataItem, otherPtr->next);
            newPtr = newPtr->next;
            otherPtr= otherPtr->next;
        }
    }
    
}

template<class DataType>
StackLinked<DataType>& StackLinked<DataType>::operator=(const StackLinked& other){
        if(this != other){
            StackNode* otherPtr = other.topPtr;
            if(otherPtr == nullptr){
                topPtr = nullptr;
            }else{
            StackNode* newPtr = topPtr;
            while(otherPtr != nullptr){
                newPtr = new StackNode(otherPtr->dataItem, otherPtr->next);
                newPtr = newPtr->next;
                otherPtr= otherPtr->next;
            }
            return *this;
        }
        return *this;
    }
       
        /*if(this != &other){
                topPtr = new StackNode(other.topPtr->data(), nullptr);
                StackNode * cpy = topPtr;
                StackNode * otherCpy = other.topPtr;
                while(otherCpy->next != nullptr){
                    cpy->next = new StackNode(otherCpy->data(), nullptr);
                    otherCpy = otherCpy->next;
                    cpy = cpy->next; 
                }
                return *this;
            }else{
                return *this;

            }*/
}

template<class DataType>
StackLinked<DataType>:: ~StackLinked(){
    clear();
}

template<class DataType>
void StackLinked<DataType>::push(const DataType& newDataItem) throw (logic_error){
    if(isFull()){
        throw logic_error ("Failed Push BC stack = full");
    }
    
    StackNode* newNodePtr = new StackNode(newDataItem,topPtr);
    topPtr = newNodePtr;
    newNodePtr = nullptr;
}

template<class DataType>
DataType StackLinked<DataType>:: pop() throw (logic_error){
    /*if(isEmpty()){
        throw logic_error("Stack empty cannot pop");
    }*/
    if(!isEmpty()){
        StackNode * nodeDelete = topPtr;
        DataType nodeDeleteData = nodeDelete->dataItem;
        topPtr = topPtr->next;
        nodeDelete->next = nullptr;
        delete nodeDelete;
        nodeDelete = nullptr;
        return nodeDeleteData;
    }
}

template<class DataType>
void StackLinked<DataType>:: clear(){
    if(!isEmpty()){
        do{
            StackNode * nodeDelete = topPtr;
            topPtr = topPtr->next;
            nodeDelete->next = nullptr;
            delete nodeDelete;
            nodeDelete = nullptr;
        }while(!isEmpty());
    }
}

template<class DataType>
bool StackLinked<DataType>::isEmpty()const{
            if(topPtr == nullptr){
                return true;
            }else{
                return false;
            }    
}

template<class DataType>
bool StackLinked<DataType>::isFull()const{
            return false;   
}

template<class DataType>
void StackLinked<DataType>::showStructure() const{
            if(!isEmpty()){
                StackNode * traverse = topPtr;
                while(traverse != nullptr){
                    cout << traverse->dataItem << " ";
                    traverse = traverse->next;
                }
            }else{
                cout << "Stack empty";
            }
            cout << std::endl;
}


