#include "AlgorithmSortHeap.h"
#include "BinaryHeap.h"
AlgorithmSortHeap :: AlgorithmSortHeap(int k ): SelectionAlgorithm(k){
    heap = new BinaryHeap(k);
}
AlgorithmSortHeap::~AlgorithmSortHeap(){
    delete heap;
}

int AlgorithmSortHeap::select(){
    int size;
    int temp;
    cin>>size;
    for (int i = 0; i < k; i++) {
        cin>>temp;
        heap->insert(temp);
    }
    for(int j = 0;j<size-k; j++){
        cin>>temp;
        if (temp > heap->getMin()) {
            heap->deleteMin();
            heap->insert(temp);
        }
    }
    return heap->getMin();
}
