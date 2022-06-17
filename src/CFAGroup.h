#pragma once

#include <string>
#include <vector>

// declare CFA-C library as external C library
extern "C" {
    #include "cfa.h"
}

class CFAVar;
class CFADim;

class CFAGroup
{
    public:
        CFAGroup(std::string name);
        
        int getId();
        std::string getName();

        int getVarCount();
        int getDimCount();
        int getGroupCount();

        CFAGroup getParentGroup();
        CFAGroup getGroup(int group_id);
        CFAGroup getGroup(std::string name);
        CFAGroup addGroup(std::string name);

        CFAVar getVar(int var_id);
        CFAVar getVar(std::string var_name);
        CFAVar addVar(std::string var_name, cfa_type d_type);
        CFAVar addVar(std::string var_name, cfa_type d_type, std::string dim_name);
        CFAVar addVar(std::string var_name, cfa_type d_type, std::vector<std::string> dim_names);
        CFAVar addVar(std::string var_name, std::vector<int> dim_ids);

        CFADim getDim(int dim_id);
        CFADim getDim(std::string dim_name);
        CFADim addDim(std::string dim_name, cfa_type d_type);
        CFADim addDim(std::string dim_name, cfa_type d_type, int dim_len);
};