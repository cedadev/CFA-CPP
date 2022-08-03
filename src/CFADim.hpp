#pragma once

#include <string>

// declare CFA-C library as external C library
extern "C" {
    #include "cfa.h"
}

namespace CFA
{
    class Dim
    {
        private:
            int id;
            int parentId;

            AggregatedDimension* getAggDim();
        public:
            Dim(int parentId, int dimId = -1);
            Dim(int parentId, std::string name, cfa_type type, int dimLen = 1);
            
            int getId();
            int getLen();
            std::string getName();
            cfa_type getType();

            int getNcVarId(int ncId);
            /* Set the value of the `Name` NC Attribute */
            void setNCAttText(int ncId, std::string name, std::string value);
    };
}