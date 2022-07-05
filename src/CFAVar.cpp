#include "CFAVar.h"

CFAVar::CFAVar(int parentId, int varId)
{
    this->parentId = parentId;
    this->id = varId;
}

CFAVar::CFAVar(int parentId, std::string name, cfa_type type)
{
    this->parentId = parentId;
    int cfaErr = cfa_def_var(parentId, name.c_str(), type, &id);
    if (cfaErr)
        throw (cfaErr);
}
        
int CFAVar::getId() 
{ 
    return id; 
}

int CFAVar::getDimCount() 
{
    return dims.size(); 
}

std::string CFAVar::getName() 
{
    AggregationVariable *aggVar;
    int cfaErr = cfa_get_var(parentId, id, &aggVar);
    if (cfaErr)
        throw (cfaErr);
    return aggVar->name; 
}

cfa_type CFAVar::getType() 
{ 
    AggregationVariable *aggVar;
    int cfaErr = cfa_get_var(parentId, id, &aggVar);
    if (cfaErr)
        throw (cfaErr);
    return aggVar->cfa_dtype.type; 
}

CFADim CFAVar::getDim(int i) 
{    
    return dims[i];
}

std::vector<CFADim> CFAVar::getDims() 
{ 
    return dims; 
}

std::vector<std::string> CFAVar::getDimNames()
{
    std::vector<std::string> dimNames;
    for(auto dim : dims)
        dimNames.push_back(dim.getName());
    return dimNames;
}