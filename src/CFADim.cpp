#include "CFADim.hpp"

CFADim::CFADim(int parentId, int dimId)
{
    this->parentId = parentId;
    this->id = dimId;
}

CFADim::CFADim(int parentId, std::string name, cfa_type type, int dimLen) : CFADim(parentId)
{
    int cfaErr = cfa_def_dim(parentId, name.c_str(), dimLen, type, &id);
    if (cfaErr)
        throw (cfaErr);
}

int CFADim::getId() 
{
    return id; 
}

int CFADim::getLen() 
{ 
    AggregatedDimension *aggDim;
    int cfaErr = cfa_get_dim(parentId, id, &aggDim);
    if (cfaErr)
        throw (cfaErr);
    return aggDim->length; 
}

std::string CFADim::getName() 
{
    AggregatedDimension *aggDim;
    int cfaErr = cfa_get_dim(parentId, id, &aggDim);
    if (cfaErr)
        throw (cfaErr);
    return aggDim->name; 
}

cfa_type CFADim::getType()
{ 
    AggregatedDimension *aggDim;
    int cfaErr = cfa_get_dim(parentId, id, &aggDim);
    if (cfaErr)
        throw (cfaErr);
    return aggDim->cfa_dtype.type; 
}