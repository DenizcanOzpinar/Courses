#include "AlgorithmSortK.h"






int AlgorithmSortK::select(){
    int size;
    cin>>size;
    int n=0;
    int p = 0;
     int *d2Ptr = new int[k];
    
    for(int i = 0;i<k;i++){
        cin>>n;
        d2Ptr[i]=n;
    }
    int i, key, j;
    for (i = 0; i < k; i++)
    {
        
        j = i+1;
        key = d2Ptr[j];
        
        while (j > 0 && key > d2Ptr[j-1])
        {
            d2Ptr[j] = d2Ptr[j-1];
            j--;
        }
        d2Ptr[j] = key;
        
    }
    for (int t=k;t<size;t++ ) {
        cin>>p;
        if(d2Ptr[k]<p){
        d2Ptr[k]=p;
            int i, key, j;
            for (i = 0; i < k; i++)
            {
                
                j = i+1;
                key = d2Ptr[j];
                
                while (j > 0 && key > d2Ptr[j-1])
                {
                    d2Ptr[j] = d2Ptr[j-1];
                    j--;
                }
                d2Ptr[j] = key;
                
            }
        }
    }
    int temp2 = 0;
    temp2 = d2Ptr[k-1];
    delete[] d2Ptr;
    return temp2;
   
}
    
    

AlgorithmSortK :: AlgorithmSortK(int k) : SelectionAlgorithm(k){
    
    
}

