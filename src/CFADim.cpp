#include <netcdf.h>

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

int CFA::Dim::getNcVarId()
{
    int cfaErr = CFA_NOERR;

    int ncVarId = -1;
    cfaErr = nc_inq_varid(getNcFileId(), getAggDim()->name, &ncVarId);
    if(cfaErr != CFA_NOERR)
        throw CFA::Exception(cfaErr);
}

int CFA::Dim::getNcFileId()
{
    int cfaErr = CFA_NOERR;

    int ncId = -1;
    cfaErr = cfa_get_ext_file_id(parentId, &ncId);
    if(cfaErr != CFA_NOERR)
        throw CFA::Exception(cfaErr);
    
    return ncId;
}
void CFA::Dim::setNCAttText(std::string attName, std::string value)
{
    int cfaErr = CFA_NOERR;

    cfaErr = nc_put_att_text(getNcFileId(), getNcVarId(), attName.c_str(), value.size(), value.c_str());
    if(cfaErr != CFA_NOERR)
        throw CFA::Exception(cfaErr);
}

AggregatedDimension* CFA::Dim::getAggDim()
{
    AggregatedDimension *aggDim;
    int cfaErr = cfa_get_dim(parentId, id, &aggDim);
    if (cfaErr)
        throw Exception(cfaErr);
    return aggDim;
}