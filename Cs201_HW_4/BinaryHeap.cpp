//============================================================================
// Name        : BinaryHeap.cpp
// Author      : Hasan Sozer
// Version     : 1.2
// Copyright   : (c) 2013 Ozyegin University
// Description : Includes the (incomplete) implementation file of the
//               BinaryHeap class that will be used as part of the program
//               to be submitted as Homework 3, which is assigned in the
//               context of the course CS201, Data Structures and Algorithms.
//
//               THE IMPLEMENTATION MUST BE COMPLETED TO MAKE ALL THE TESTS
//               IN THE MAIN METHOD PASS.
//
//               After completing the heap implementation, "BinaryHeap.h" and
//               "BinaryHeap.cpp" files will be used for extending homework 1,
//               and the extended program will be submitted as Homework 3.
//============================================================================

#include "BinaryHeap.h"

BinaryHeap::BinaryHeap(int capacity) {
    this->capacity = capacity;
    
    // The element at index 0 is not used!
    // The root element will be placed at index 1
    heap = new int[capacity+1];
    size = 0;
}

BinaryHeap::~BinaryHeap() {
    delete [] heap;
}

void BinaryHeap::insert(int element) {
    if(size<capacity){
        int hole =++size;
        for(; hole > 1 && element<heap[hole/2]; hole /=2)
            heap[hole] = heap[hole/2] ;
        
        heap[hole] = element ;
        // TO BE COMPLETED
        
        
        // The capacity of the heap is assumed to be fixed.
        // Insert the element if size < capacity
        // Do nothing otherwise.
        
        
        // After the new element is inserted, perform a percolate up operation here.
        // You can add a percolateUp method to the class,
        // or just implement the operations within this insert method.
    }
    
}


void BinaryHeap::deleteMin() {
    
    // TO BE COMPLETED
    if(size < 1){
        // If the size is less than 1, do nothing and stop
        // Otherwise, replace the root of the heap with the last element on the last level
        // Then, call the percolateDown function by providing the index of the root node, i.e., 1
    } else {
        heap[1]=heap[size];
        heap[size]=0;
        size--;
        percolateDown(1);
        
    }
}


int BinaryHeap::getMin() {
    if(size<1){
        return -1 ;
    }
    else{
        return heap[1] ;
    }
    // TO BE COMPLETED
    
    // If the size is less than 1, return -1
    // Otherwise, return the value of the root node
}

void BinaryHeap::percolateDown(int hole) {
    if(hole*2+1 <= size && heap[hole*2] < heap[hole*2+1]){
        if(heap[hole]>heap[hole*2]){
            swap(hole,hole*2) ;
            percolateDown(hole*2) ;
        }
        
    }
    else{
        if(hole*2+1<=size && heap[hole]>heap[hole*2+1]){
            swap(hole, hole*2+1) ;
            percolateDown(hole*2+1) ;
            
        } else if(hole*2 == size && heap[hole]>heap[hole*2]) {
            swap(hole,hole*2) ;
            percolateDown(hole*2) ;
        }
        
    }
    
    
}
void BinaryHeap::swap(int i, int j) {
    int t = heap[i];
    heap[i] = heap[j];
    heap[j] = t;
}

