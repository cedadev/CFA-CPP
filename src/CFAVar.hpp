#pragma once

#include <string>
#include <vector>

#include "CFADim.hpp"

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
        
        AggregationVariable* getAggVar();
    public:
        CFAVar(int parentId, int varId = -1);
        CFAVar(int parentId, std::string name, cfa_type type);
        
        int getId();
        int getDimCount();
        std::string getName();
        cfa_type getType();
        CFADim getDim(int i);

        int updateDims(int dimId);
        int updateDims(std::vector<int> dimIds);
        int updateDims(std::string dimName);
        int updateDims(std::vector<std::string> dimNames);

        
        std::vector<CFADim> getDims();
        std::vector<std::string> getDimNames();
};