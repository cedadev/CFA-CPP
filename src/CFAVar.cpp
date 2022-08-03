#include "CFAVar.hpp"
#include "CFAException.hpp"

#include <netcdf.h>
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
    int cfaErr = cfa_var_def_dims(parentId, id, dimIds.size(), dimIds.data());
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
    std::vector<Dim> dims = getDims();
    std::vector<std::string> dimNames;
    dimNames.reserve(dims.size());
    
    std::transform(dims.begin(), dims.end(), std::back_inserter(dimNames), [](Dim& dim) -> std::string { return dim.getName(); });
    return dimNames;
}

int CFA::Var::getNcVarId()
{
    int cfaErr = CFA_NOERR;

    int ncVarId = -1;
    cfaErr = nc_inq_varid(getNcFileId(), getAggVar()->name, &ncVarId);
    if(cfaErr != CFA_NOERR)
        throw CFA::Exception(cfaErr);
}

int CFA::Var::getNcFileId()
{
    int cfaErr = CFA_NOERR;

    int ncId = -1;
    cfaErr = cfa_get_ext_file_id(parentId, &ncId);
    if(cfaErr != CFA_NOERR)
        throw CFA::Exception(cfaErr);
    
    return ncId;
}

void CFA::Var::setNCAttText(std::string attName, std::string value)
{
    int cfaErr = CFA_NOERR;

    cfaErr = nc_put_att_text(getNcFileId(), getNcVarId(), attName.c_str(), value.size(), value.c_str());
    if(cfaErr != CFA_NOERR)
        throw CFA::Exception(cfaErr);
}

AggregationVariable* CFA::Var::getAggVar()
{
    AggregationVariable *aggVar;
    int cfaErr = cfa_get_var(parentId, id, &aggVar);
    if (cfaErr)
        throw Exception(cfaErr);
    return aggVar;
}