#include "CFAGroup.hpp"
#include "CFAException.hpp"

CFA::Group::Group(int parentId, int grpId)
{
    this->id = grpId;
    this->parentId = parentId;
}

CFA::Group::Group(int parentId, std::string name) : Group(parentId)
{ 
    int cfaErr = cfa_def_cont(parentId, name.c_str(), &id);
    if (cfaErr)
        throw Exception(cfaErr);
}

int CFA::Group::getId() 
{ 
    return id; 
}

std::string CFA::Group::getName() 
{ 
    return getAggCont()->name; 
}

int CFA::Group::getVarCount() 
{ 
    return getAggCont()->n_vars;
}

int CFA::Group::getDimCount() 
{ 
    return getAggCont()->n_dims; 
}

int CFA::Group::getGrpCount() 
{ 
    return getAggCont()->n_conts; 
}

CFA::Group CFA::Group::getGrp(std::string name) 
{
    int grpId;
    int cfaErr = cfa_inq_cont_id(id, name.c_str(), &grpId);
    if (cfaErr)
        throw Exception(cfaErr);
    return Group(id, grpId);
}

CFA::Group CFA::Group::addGrp(std::string name)
{
    return Group(id, name);
}

CFA::Var CFA::Group::getVar(std::string name) 
{    
    int varId;
    int cfaErr = cfa_inq_var_id(id, name.c_str(), &varId);
    if (cfaErr)
        throw Exception(cfaErr);
    return CFA::Var(id, varId);
}

CFA::Var CFA::Group::addVar(std::string name, cfa_type type)
{
    return CFA::Var(id, name, type);
}

CFA::Var CFA::Group::addVar(std::string name, cfa_type type, int dimId)
{
    CFA::Var Var(id, name, type);
    int cfaErr = Var.updateDims(dimId);
    if(cfaErr)
        throw Exception(cfaErr);
    return Var;
}

CFA::Var CFA::Group::addVar(std::string name, cfa_type type, std::string dimName)
{
    CFA::Var Var(id, name, type);
    int cfaErr = Var.updateDims(dimName);
    if(cfaErr)
        throw Exception(cfaErr);
    return Var;
}

CFA::Var CFA::Group::addVar(std::string name, cfa_type type, std::vector<int> dimIds)
{
    CFA::Var Var(id, name, type);    
    int cfaErr = Var.updateDims(dimIds);
    if(cfaErr)
        throw Exception(cfaErr);
    return Var;
}

CFA::Var CFA::Group::addVar(std::string name, cfa_type type, std::vector<std::string> dimNames)
{
    CFA::Var Var(id, name, type);    
    int cfaErr = Var.updateDims(dimNames);
    if(cfaErr)
        throw Exception(cfaErr);
    return Var;
}

CFA::Dim CFA::Group::getDim(std::string name)
{
    int dimId;
    int cfaErr = cfa_inq_dim_id(id, name.c_str(), &dimId);
    if (cfaErr)
        throw Exception(cfaErr);
    return CFA::Dim(id, dimId);
}

CFA::Dim CFA::Group::addDim(std::string name, cfa_type type)
{
    return CFA::Dim(id, name, type);
}

CFA::Dim CFA::Group::addDim(std::string name, cfa_type type, int dimLen)
{
    return CFA::Dim(id, name, type, dimLen);
}

AggregationContainer* CFA::Group::getAggCont()
{
    AggregationContainer *aggCont;
    int cfaErr = cfa_get_cont(parentId, id, &aggCont);
    if (cfaErr)
        throw Exception(cfaErr);
    return aggCont;
}