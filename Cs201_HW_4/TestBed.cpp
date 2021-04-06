#include "TestBed.h"


 TestBed ::TestBed()
{
    algorithm = 0;
}
void TestBed::execute(){
    clock_t start = clock();
    int b =algorithm->select();
    clock_t end = clock();
    double cpu_time = static_cast<double>( end - start ) /CLOCKS_PER_SEC;
    cout<<"Result: "<<b<<endl;
    cout<<"Duration(sec):"<<cpu_time<<endl;
}
void TestBed ::setAlgorithm(int type, int k){
    
    
  
    
    if(type==1){
        algorithm = new AlgorithmSortAll(k);
        
    }
    else if (type==2){
        
        algorithm = new AlgorithmSortK(k);
        
    }
    else if(type==3)
        algorithm = new AlgorithmSortHeap(k);
    else if(type==4)
        algorithm = new AlgorithmSortQuick(k);
    else
        cout<<"you entered non existing method number";
    
}
TestBed::~TestBed(){
    delete algorithm;
}

