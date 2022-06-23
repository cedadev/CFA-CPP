#pragma once

#include <string>
#include <vector>

// declare CFA-C library as external C library
extern "C" {
    #include "cfa.h"
}

class CFAGroup;
class CFADim;

class CFAVar
{
    public:
        CFAVar(std::string name, cfa_type d_type);
        
        int getId();
        int getDimCount();
        std::string getName();
        cfa_type getType();
        CFADim getDim(int i);
        CFAGroup getParentGroup();
    private:
        std::vector<CFADim> getDims();
        std::vector<std::string> getDimNames();
};