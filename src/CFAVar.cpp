#include "CFAVar.hpp"
#include <stdexcept>

CFAVar::CFAVar(int parentId, int varId)
{
    this->parentId = parentId;
    this->id = varId;
}

CFAVar::CFAVar(int parentId, std::string name, cfa_type type) : CFAVar(parentId)
{
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
    return getAggVar()->cfa_ndim; 
}

std::string CFAVar::getName() 
{
    return getAggVar()->name; 
}

cfa_type CFAVar::getType() 
{ 
    return getAggVar()->cfa_dtype.type; 
}

CFADim CFAVar::getDim(int i) 
{
    return CFADim(parentId, getAggVar()->cfa_dim_idp[i]);
}

int CFAVar::updateDims(int dimId)
{
    std::vector<int> dimIds = {dimId};
    return updateDims(dimIds);
}

int CFAVar::updateDims(std::vector<int> dimIds)
{
    int cfaErr = cfa_var_def_dims(parentId, id, getDimCount(), dimIds.data());
    if (cfaErr)
        return (cfaErr);
    return 0;
}

int CFAVar::updateDims(std::string dimName)
{
    std::vector<std::string> dimNames = {dimName};
    return updateDims(dimNames);
}

int CFAVar::updateDims(std::vector<std::string> dimNames)
{
    std::vector<int> dimIds;
    for(std::string dimName : dimNames)
    {
        int dimId;
        int cfaErr = cfa_inq_dim_id(id, dimName.c_str(), &dimId);
        if (cfaErr)
            return (cfaErr);
        dimIds.emplace_back(dimId);
    }
    return updateDims(dimIds);
}

AggregationVariable* CFAVar::getAggVar()
{
    AggregationVariable *aggVar;
    int cfaErr = cfa_get_var(parentId, id, &aggVar);
    if (cfaErr)
        throw (cfaErr);
    return aggVar;
}

std::vector<CFADim> CFAVar::getDims() 
{
    throw std::runtime_error("Not implemented");
}

std::vector<std::string> CFAVar::getDimNames()
{
    throw std::runtime_error("Not implemented");
}