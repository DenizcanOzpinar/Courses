#include "AlgorithmSortAll.h"



int AlgorithmSortAll ::select(){
    int size;
    cin>>size;
    int n=0;
    int *dPtr = new int[size];
    for(int i= 0;i<size;i++){
        cin>>n;
        dPtr[i]=n;
        
    }
    int i, key, j;
    for (i = 0; i < size-1; i++)
    {
        
        j = i+1;
        key = dPtr[j];
        
        while (j > 0 && key > dPtr[j-1])
        {
            dPtr[j] = dPtr[j-1];
            j--;
        }
        dPtr[j] = key;
        
    }
    int temp=0;
    temp=dPtr[k-1];
    delete[] dPtr;
    return temp;
    
}

AlgorithmSortAll ::AlgorithmSortAll(int k ): SelectionAlgorithm(k){
    
}



