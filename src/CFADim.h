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
        CFADim(int parentId, int dimId);
        CFADim(int parentId, std::string name, cfa_type type, int dimLen);
        
        int getId();
        int getLen();
        std::string getName();
        cfa_type getType();
};