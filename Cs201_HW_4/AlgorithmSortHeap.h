#include "SelectionAlgorithm.h"
#include "BinaryHeap.h"

class AlgorithmSortHeap: public SelectionAlgorithm{
    public:
    AlgorithmSortHeap(int k);
    int select();
    ~AlgorithmSortHeap();
    
private:
    BinaryHeap* heap;
};

