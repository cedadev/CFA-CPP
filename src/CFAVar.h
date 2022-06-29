#pragma once

#include <string>
#include <vector>

#include "CFADim.h"
#include "CFAGroup.h"

// declare CFA-C library as external C library
extern "C" {
    #include "cfa.h"
}

class CFAVar
{
    private:
        int id;
        cfa_type type;
        std::string name;

        CFAGroup parent;
        std::vector<CFADim> dims;
    public:
        CFAVar(std::string name, cfa_type type);
        CFAVar(std::string name, cfa_type type, CFAGroup parent, std::vector<CFADim> dims);
        
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