#pragma once

#include <string>
#include <vector>

#include "CFADim.hpp"

// declare CFA-C library as external C library
extern "C" {
    #include "cfa.h"
}

class CFAGroup;

namespace CFA
{
    class Var
    {
        private:
            int id;
            int parentId;
            
            AggregationVariable* getAggVar();
        public:
            Var(int parentId, int varId = -1);
            Var(int parentId, std::string name, cfa_type type);
            
            int getId();
            int getDimCount();
            std::string getName();
            cfa_type getType();
            Dim getDim(int i);

            int updateDims(int dimId);
            int updateDims(std::vector<int> dimIds);
            int updateDims(std::string dimName);
            int updateDims(std::vector<std::string> dimNames);
            
            std::vector<Dim> getDims();
            std::vector<std::string> getDimNames();

            /* Add Aggregation Instruction */
            void addAggInstr(std::string name, std::string value, bool scalar);

            /* Add Fragment */
            void defFragments(int frags[]);
            Fragment getFragmentByFragLocation(size_t location[]);
            Fragment getFragmentByDataLocation(size_t location[]);
            void addFragment(size_t fragLocation[], size_t dataLocation[], const char *file, const char *format, const char *address, const char *units);

            int getNcVarId(int ncId);
            /* Set the value of the `Name` NC Attribute */
            void setNCAttText(int ncId, std::string name, std::string value);
    };
}