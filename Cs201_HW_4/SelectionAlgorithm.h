#ifndef _SELECTION_ALGORITHM_
#define _SELECTION_ALGORITHM_

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class SelectionAlgorithm{
public:
    SelectionAlgorithm(int k);
    virtual ~SelectionAlgorithm() = default;
    virtual int select();
protected:
    int k;
    
};
#endif
