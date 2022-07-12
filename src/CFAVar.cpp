#include "CFAVar.hpp"
#include "CFAException.hpp"

#include <algorithm>

CFA::Var::Var(int parentId, int varId)
{
    this->id = varId;
    this->parentId = parentId;
}

CFA::Var::Var(int parentId, std::string name, cfa_type type) : Var(parentId)
{
    int cfaErr = cfa_def_var(parentId, name.c_str(), type, &id);
    if (cfaErr)
        throw Exception(cfaErr);
}
        
int CFA::Var::getId() 
{ 
    return id; 
}

int CFA::Var::getDimCount() 
{
    return getAggVar()->cfa_ndim; 
}

std::string CFA::Var::getName() 
{
    return getAggVar()->name; 
}

cfa_type CFA::Var::getType() 
{ 
    return getAggVar()->cfa_dtype.type; 
}

CFA::Dim CFA::Var::getDim(int i) 
{
    return Dim(parentId, getAggVar()->cfa_dim_idp[i]);
}

int CFA::Var::updateDims(int dimId)
{
    std::vector<int> dimIds = {dimId};
    return updateDims(dimIds);
}

int CFA::Var::updateDims(std::vector<int> dimIds)
{
    int cfaErr = cfa_var_def_dims(parentId, id, getDimCount(), dimIds.data());
    if (cfaErr)
        return (cfaErr);
    return 0;
}

int CFA::Var::updateDims(std::string dimName)
{
    std::vector<std::string> dimNames = {dimName};
    return updateDims(dimNames);
}

int CFA::Var::updateDims(std::vector<std::string> dimNames)
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

std::vector<CFA::Dim> CFA::Var::getDims() 
{
    std::vector<Dim> dims;
    int dimCount = getAggVar()->cfa_ndim;
    int *dimIds = getAggVar()->cfa_dim_idp;
    for(int i = 0; i < dimCount; i++)
        dims.emplace_back(parentId, dimIds[i]);
    return dims;
}

std::vector<std::string> CFA::Var::getDimNames()
{   
    std::vector<std::string> dimNames;
    std::vector<Dim> dims = getDims();
    std::transform(dims.begin(), dims.end(), dimNames.begin(), [](Dim dim) { return dim.getName(); });
    return dimNames;
}

AggregationVariable* CFA::Var::getAggVar()
{
    AggregationVariable *aggVar;
    int cfaErr = cfa_get_var(parentId, id, &aggVar);
    if (cfaErr)
        throw Exception(cfaErr);
    return aggVar;
}