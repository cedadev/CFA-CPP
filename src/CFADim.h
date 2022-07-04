#pragma once

#include <string>

// declare CFA-C library as external C library
extern "C" {
    #include "cfa.h"
}

class CFAGroup;

class CFADim
{
    private:
        int id;
        int dimLen;
        cfa_type type;
        std::string name;

        CFAGroup* parent;
    public:
        CFADim(std::string name, cfa_type type);
        CFADim(std::string name, cfa_type type, int dimLen, CFAGroup *parent);
        
        int getId();
        int getLen();
        std::string getName();
        cfa_type getType();
        CFAGroup* getParentGroup();
};