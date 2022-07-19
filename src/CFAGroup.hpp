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

namespace CFA
{
    class Group
    {    
        protected:
            int id;
            int parentId;

            static const int rootGroupParentId = -1;

            AggregationContainer* getAggCont();
        public:
            Group(int parentId, int grpId = -1);
            Group(int parentId, std::string name);
            
            int getId();
            std::string getName();

            int getVarCount();
            int getDimCount();
            int getGrpCount();

            Group getGrp(std::string name);
            Group addGrp(std::string name);

            Var getVar(std::string name);
            Var addVar(std::string name, cfa_type type);
            Var addVar(std::string name, cfa_type type, int dimId);
            Var addVar(std::string name, cfa_type type, std::string dimName);
            Var addVar(std::string name, cfa_type type, std::vector<int> dimIds);
            Var addVar(std::string name, cfa_type type, std::vector<std::string> dimNames);

            Dim getDim(std::string name);
            Dim addDim(std::string name, cfa_type type);
            Dim addDim(std::string name, cfa_type type, int dimLen);
    };
}