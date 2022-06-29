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
    protected:
        int id;
        std::string name;

        CFAGroup* parent;
        std::vector<CFAGroup> groups;
    public:
        CFAGroup();
        CFAGroup(std::string name);
        // Need to discuss this more with Neil
        CFAGroup(std::string name, int id, CFAGroup* parent);
        
        int getId();
        std::string getName();

        int getVarCount();
        int getDimCount();
        int getGroupCount();

        CFAGroup getParentGroup();
        CFAGroup getGroup(int groupId);
        CFAGroup getGroup(std::string name);
        CFAGroup addGroup(std::string name);

        CFAVar getVar(int varId);
        CFAVar getVar(std::string varName);
        CFAVar addVar(std::string varName, cfa_type dType);
        CFAVar addVar(std::string varName, cfa_type dType, std::string dimName);
        CFAVar addVar(std::string varName, cfa_type dType, std::vector<std::string> dimNames);
        CFAVar addVar(std::string varName, std::vector<int> dimIds);

        CFADim getDim(int dimId);
        CFADim getDim(std::string dimName);
        CFADim addDim(std::string dimName, cfa_type dType);
        CFADim addDim(std::string dimName, cfa_type dType, int dimLen);
};