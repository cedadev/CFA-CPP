#include "CFAGroup.hpp"
#include "CFAException.hpp"

CFAGroup::CFAGroup(int parentId, int grpId)
{
    this->id = grpId;
    this->parentId = parentId;
}

CFAGroup::CFAGroup(int parentId, std::string name) : CFAGroup(parentId)
{ 
    int cfaErr = cfa_def_cont(parentId, name.c_str(), &id);
    if (cfaErr)
        throw CFAException(cfaErr);
}

int CFAGroup::getId() 
{ 
    return id; 
}

std::string CFAGroup::getName() 
{ 
    return getAggCont()->name; 
}

int CFAGroup::getVarCount() 
{ 
    return getAggCont()->n_vars;
}

int CFAGroup::getDimCount() 
{ 
    return getAggCont()->n_dims; 
}

int CFAGroup::getGroupCount() 
{ 
    return getAggCont()->n_conts; 
}

CFAGroup CFAGroup::getGroup(std::string name) 
{
    int grpId;
    int cfaErr = cfa_inq_cont_id(id, name.c_str(), &grpId);
    if (cfaErr)
        throw CFAException(cfaErr);
    return CFAGroup(id, grpId);
}

CFAGroup CFAGroup::addGroup(std::string name)
{
    return CFAGroup(parentId, name);
}

CFAVar CFAGroup::getVar(std::string name) 
{    
    int varId;
    int cfaErr = cfa_inq_var_id(id, name.c_str(), &varId);
    if (cfaErr)
        throw CFAException(cfaErr);
    return CFAVar(id, varId);
}

CFAVar CFAGroup::addVar(std::string name, cfa_type type)
{
    return CFAVar(id, name, type);
}

CFAVar CFAGroup::addVar(std::string name, cfa_type type, int dimId)
{
    CFAVar cfaVar(id, name, type);
    int cfaErr = cfaVar.updateDims(dimId);
    if(cfaErr)
        throw CFAException(cfaErr);
    return cfaVar;
}

CFAVar CFAGroup::addVar(std::string name, cfa_type type, std::string dimName)
{
    CFAVar cfaVar(id, name, type);
    int cfaErr = cfaVar.updateDims(dimName);
    if(cfaErr)
        throw CFAException(cfaErr);
    return cfaVar;
}

CFAVar CFAGroup::addVar(std::string name, cfa_type type, std::vector<int> dimIds)
{
    CFAVar cfaVar(id, name, type);    
    int cfaErr = cfaVar.updateDims(dimIds);
    if(cfaErr)
        throw CFAException(cfaErr);
    return cfaVar;
}

CFAVar CFAGroup::addVar(std::string name, cfa_type type, std::vector<std::string> dimNames)
{
    CFAVar cfaVar(id, name, type);    
    int cfaErr = cfaVar.updateDims(dimNames);
    if(cfaErr)
        throw CFAException(cfaErr);
    return cfaVar;
}

CFADim CFAGroup::getDim(std::string name)
{
    int dimId;
    int cfaErr = cfa_inq_dim_id(id, name.c_str(), &dimId);
    if (cfaErr)
        throw CFAException(cfaErr);
    return CFADim(id, dimId);
}

CFADim CFAGroup::addDim(std::string name, cfa_type type)
{
    return CFADim(id, name, type);
}

CFADim CFAGroup::addDim(std::string name, cfa_type type, int dimLen)
{
    return CFADim(id, name, type, dimLen);
}

AggregationContainer* CFAGroup::getAggCont()
{
    AggregationContainer *aggCont;
    int cfaErr = cfa_get_cont(parentId, id, &aggCont);
    if (cfaErr)
        throw CFAException(cfaErr);
    return aggCont;
}