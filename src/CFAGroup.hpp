#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include "CFAVar.hpp"
#include "CFADim.hpp"

// declare CFA-C library as external C library
extern "C" {
    #include "cfa.h"
}

class CFAGroup
{    
    protected:
        int id;
        int parentId;

        AggregationContainer* getAggCont();
    public:
        CFAGroup(std::string name, int parentId = -1);
        CFAGroup(int parentId = -1, int grpId = -1);
        
        int getId();
        std::string getName();

        int getVarCount();
        int getDimCount();
        int getGroupCount();

        CFAGroup getGroup(std::string name);
        CFAGroup addGroup(std::string name);

        CFAVar getVar(std::string name);
        CFAVar addVar(std::string name, cfa_type type);
        CFAVar addVar(std::string name, cfa_type type, int dimId);
        CFAVar addVar(std::string name, cfa_type type, std::string dimName);
        CFAVar addVar(std::string name, cfa_type type, std::vector<int> dimIds);
        CFAVar addVar(std::string name, cfa_type type, std::vector<std::string> dimNames);

        CFADim getDim(std::string name);
        CFADim addDim(std::string name, cfa_type type);
        CFADim addDim(std::string name, cfa_type type, int dimLen);
};