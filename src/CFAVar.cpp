#include "CFAVar.h"

CFAVar::CFAVar(std::string name, cfa_type type)
{
    id = -1;
    this->name = name;
    this->type = type;
}
CFAVar::CFAVar(std::string name, cfa_type type, CFAGroup parent, std::vector<CFADim> dims) : CFAVar(name, type)
{
    this->parent = parent;
    this->dims = dims;
}
        
int CFAVar::getId() { return id; }
int CFAVar::getDimCount() { return dims.size(); }
std::string CFAVar::getName() { return name; }
cfa_type CFAVar::getType() { return type; }
CFADim CFAVar::getDim(int i) { return dims[i]; }
CFAGroup CFAVar::getParentGroup() { return parent; }

std::vector<CFADim> CFAVar::getDims() { return dims; }
std::vector<std::string> CFAVar::getDimNames()
{
    std::vector<std::string> dimNames;
    for(auto dim : dims)
        dimNames.push_back(dim.getName());
    return dimNames;
}