#include "CFADim.hpp"
#include "CFAException.hpp"

CFA::Dim::Dim(int parentId, int dimId)
{
    this->id = dimId;
    this->parentId = parentId;
}

CFA::Dim::Dim(int parentId, std::string name, cfa_type type, int dimLen) : Dim(parentId)
{
    int cfaErr = cfa_def_dim(parentId, name.c_str(), dimLen, type, &id);
    if (cfaErr)        
        throw Exception(cfaErr);
}

int CFA::Dim::getId() 
{
    return id; 
}

int CFA::Dim::getLen() 
{
    return getAggDim()->length; 
}

std::string CFA::Dim::getName() 
{
    return getAggDim()->name; 
}

cfa_type CFA::Dim::getType()
{
    return getAggDim()->cfa_dtype.type;
}

AggregatedDimension* CFA::Dim::getAggDim()
{
    AggregatedDimension *aggDim;
    int cfaErr = cfa_get_dim(parentId, id, &aggDim);
    if (cfaErr)
        throw Exception(cfaErr);
    return aggDim;
}