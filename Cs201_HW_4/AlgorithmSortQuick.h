#include "SelectionAlgorithm.h"
class AlgorithmSortQuick : public SelectionAlgorithm {
public:
    AlgorithmSortQuick(int k);
    int quickselect(int a[],int left,int right, int k);
    int select();
    int median(int a[],int left, int right);
    void swap(int a[],int i, int j);
    
};
