#include "CFADim.hpp"

CFADim::CFADim(int parentId, int dimId)
{
    this->id = dimId;
    this->parentId = parentId;
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
    return getAggDim()->length; 
}

std::string CFADim::getName() 
{
    return getAggDim()->name; 
}

cfa_type CFADim::getType()
{
    return getAggDim()->cfa_dtype.type;
}

AggregatedDimension* CFADim::getAggDim()
{
    AggregatedDimension *aggDim;
    int cfaErr = cfa_get_dim(parentId, id, &aggDim);
    if (cfaErr)
        throw (cfaErr);
    return aggDim;
}