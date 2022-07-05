#pragma once

#include <string>
#include <vector>
#include <algorithm>

#include "CFAVar.h"
#include "CFADim.h"

// declare CFA-C library as external C library
extern "C" {
    #include "cfa.h"
}

class CFAGroup
{    
    protected:
        int id;
        std::string name;

        CFAGroup* parent;
        std::vector<CFAVar> vars;
        std::vector<CFADim> dims;
        std::vector<CFAGroup> groups;
    public:
        CFAGroup();
        CFAGroup(std::string name);
        
        int getId();
        std::string getName();

        int getVarCount();
        int getDimCount();
        int getGroupCount();

        CFAGroup getParentGroup();
        CFAGroup getGroup(int id);
        CFAGroup getGroup(std::string name);
        CFAGroup addGroup(std::string name);

        CFAVar getVar(int id);
        CFAVar getVar(std::string name);
        CFAVar addVar(std::string name, cfa_type type);
        CFAVar addVar(std::string name, cfa_type type, int dimId);
        CFAVar addVar(std::string name, cfa_type type, std::string dimName);
        CFAVar addVar(std::string name, cfa_type type, std::vector<int> dimIds);
        CFAVar addVar(std::string name, cfa_type type, std::vector<std::string> dimNames);

        CFADim getDim(int id);
        CFADim getDim(std::string name);
        CFADim addDim(std::string name, cfa_type type);
        CFADim addDim(std::string name, cfa_type type, int dimLen);
};