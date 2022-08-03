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

void CFA::Var::addAggInstr(std::string name, std::string value, bool scalar)
{
    int cfaErr = CFA_NOERR;
    cfaErr = cfa_var_def_agg_instr(parentId, id, name.c_str(), value.c_str(), scalar);
    if(cfaErr)
        throw CFA::Exception(cfaErr);
}

void CFA::Var::defFragments(int frags[])
{
    int cfaErr = CFA_NOERR;
    cfaErr = cfa_var_def_frag_num(parentId, id, frags);
    if(cfaErr)
        throw CFA::Exception(cfaErr);
}

Fragment CFA::Var::getFragmentByFragLocation(size_t location[])
{
    int cfaErr = CFA_NOERR;
    const Fragment *frag = NULL;
    cfaErr = cfa_var_get1_frag(parentId, id, location, NULL, &frag);
    if(cfaErr)
        throw CFA::Exception(cfaErr);
    return *frag;
}

Fragment CFA::Var::getFragmentByDataLocation(size_t location[])
{
    int cfaErr = CFA_NOERR;
    const Fragment *frag = NULL;
    cfaErr = cfa_var_get1_frag(parentId, id, NULL, location, &frag);
    if(cfaErr)
        throw CFA::Exception(cfaErr);
    return *frag;
}

void CFA::Var::addFragment(size_t fragLocation[], size_t dataLocation[], const char *file, const char *format, const char *address, const char *units)
{
    int cfaErr = CFA_NOERR;
    cfaErr = cfa_var_put1_frag(parentId, id, fragLocation, dataLocation, file, format, address, units);
    if(cfaErr)
        throw CFA::Exception(cfaErr);
}

int CFA::Var::getNcVarId(int ncId)
{
    int cfaErr = CFA_NOERR;

    int ncVarId = -1;
    cfaErr = nc_inq_varid(ncId, getAggVar()->name, &ncVarId);
    if(cfaErr)
        throw CFA::Exception(cfaErr);

    return ncVarId;
}

void CFA::Var::setNCAttText(int ncId, std::string name, std::string value)
{
    int cfaErr = CFA_NOERR;

    cfaErr = nc_put_att_text(ncId, getNcVarId(ncId), name.c_str(), value.size(), value.c_str());
    if(cfaErr)
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