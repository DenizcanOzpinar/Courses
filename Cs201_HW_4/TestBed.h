
#include <ctime>

#include "AlgorithmSortAll.h"
#include "SelectionAlgorithm.h"
#include "AlgorithmSortK.h"
#include "AlgorithmSortHeap.h"
#include "AlgorithmSortQuick.h"
using namespace std;

class TestBed{
public:
    TestBed();
    void setAlgorithm(int type ,int k);
    void execute();
    ~TestBed();
    int k;
    
private:
    SelectionAlgorithm *algorithm;
    
    
  

};
