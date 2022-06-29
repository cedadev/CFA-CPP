#include "CFADim.h"

CFADim::CFADim(std::string name, cfa_type type)
{
    id = -1;
    dimLen = -1;
    this->name = name;
    this->type = type;
}
CFADim::CFADim(std::string name, cfa_type type, int dimLen, CFAGroup parent) : CFADim(name, type)
{
    this->dimLen = dimLen;
    this->parent = parent;
}

int CFADim::getId() { return id; }
int CFADim::getLen() { return dimLen; }
std::string CFADim::getName() { return name; }
cfa_type CFADim::getType() { return type; }
CFAGroup CFADim::getParentGroup() { return parent; }