#pragma once

#include <string>

// declare CFA-C library as external C library
extern "C" {
    #include "cfa.h"
}

class CFADim
{
    private:
        int id;
        int parentId;
    public:
        CFADim(int parentId, std::string name, int dimLen, cfa_type type);
        
        int getId();
        int getLen();
        std::string getName();
        cfa_type getType();
};