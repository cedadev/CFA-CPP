#pragma once

#include <string>
#include <vector>

#include "CFADim.h"

// declare CFA-C library as external C library
extern "C" {
    #include "cfa.h"
}

class CFAGroup;

class CFAVar
{
    private:
        int id;
        int parentId;

        std::vector<CFADim> dims;
    public:
        CFAVar(int parentId, int varId = -1);
        CFAVar(int parentId, std::string name, cfa_type type);
        
        int getId();
        int getDimCount();
        std::string getName();
        cfa_type getType();
        CFADim getDim(int i);
    private:
        std::vector<CFADim> getDims();
        std::vector<std::string> getDimNames();
};