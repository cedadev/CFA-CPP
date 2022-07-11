#include "CFAVar.hpp"
#include "CFAException.hpp"

#include <algorithm>

CFAVar::CFAVar(int parentId, int varId)
{
    this->id = varId;
    this->parentId = parentId;
}

CFAVar::CFAVar(int parentId, std::string name, cfa_type type) : CFAVar(parentId)
{
    int cfaErr = cfa_def_var(parentId, name.c_str(), type, &id);
    if (cfaErr)
        throw CFAException(cfaErr);
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

std::vector<CFADim> CFAVar::getDims() 
{
    std::vector<CFADim> dims;
    int dimCount = getAggVar()->cfa_ndim;
    int *dimIds = getAggVar()->cfa_dim_idp;
    for(int i = 0; i < dimCount; i++)
        dims.emplace_back(parentId, dimIds[i]);
    return dims;
}

std::vector<std::string> CFAVar::getDimNames()
{   
    std::vector<std::string> dimNames;
    std::vector<CFADim> dims = getDims();
    std::transform(dims.begin(), dims.end(), dimNames.begin(), [](CFADim dim) { return dim.getName(); });
    return dimNames;
}

AggregationVariable* CFAVar::getAggVar()
{
    AggregationVariable *aggVar;
    int cfaErr = cfa_get_var(parentId, id, &aggVar);
    if (cfaErr)
        throw CFAException(cfaErr);
    return aggVar;
}