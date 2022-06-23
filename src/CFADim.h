#pragma once

#include <string>

// declare CFA-C library as external C library
extern "C" {
    #include "cfa.h"
}

class CFAGroup;

class CFADim
{
    public:
        CFADim(std::string name, cfa_type d_type);
        CFADim(std::string name, cfa_type d_type, int dim_len);
        
        int getId();
        int getLen();
        std::string getName();
        cfa_type getType();
        CFAGroup getParentGroup();
};