
    #include "AlgorithmSortQuick.h"
    AlgorithmSortQuick :: AlgorithmSortQuick(int k) : SelectionAlgorithm(k){
        
    }
    int AlgorithmSortQuick::select(){
        int size;
        int n;
        cin>>size;
        int *dPtr = new int[size];
        
        for(int i=0;i<size;i++){
            cin>>n;
            dPtr[i] = n;
        }
        
        int result = quickselect(dPtr,0,size-1,k);
        delete [] dPtr;
        return result;
    }

    void AlgorithmSortQuick::swap(int a[],int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    int AlgorithmSortQuick::median(int a[], int left, int right){
        int center =( left + right ) /2;
        if (a[center]<a[left])
            swap(a,left,center);
        if(a[right]<a[left])
            swap(a,right,left);
        if(a[right]<a[center])
            swap(a,center,right);
        
        swap(a,center,right-1);
        return a[right-1];
        
    }

     int AlgorithmSortQuick::quickselect(int dPtr[], int left, int right, int k){
         if(left +10<=right){
            int pivot =  median(dPtr, left, right);
             
             int i = left, j = right-1;
             for( ; ; ){
                 while (dPtr[++i] < pivot) {}
                 while (pivot < dPtr[--j]) {}
                 if (i<j)
                     swap(dPtr,i, j);
                 
                   else
                     break;
             
                }
             
             swap(dPtr,i,right-1);
             if(k <= i-1)
                 return quickselect(dPtr,left,i-1,k);
             else if (k==i)
                 return pivot;
             else
               return  quickselect(dPtr,i+1,right ,k);
            
            }
         
         
         else{
             int i, key, j;
             for (i = left+1; i < right+1; i++){
                 j = i-1;
                 key = dPtr[i];
                    while (j >= left && key < dPtr[j]){
                        dPtr[j+1] = dPtr[j];
                        j--;
                     }
                   dPtr[j+1] = key;
                 
             }
            int temp=0;
            temp=dPtr[k];
            return temp;
             
             }
         
     }


