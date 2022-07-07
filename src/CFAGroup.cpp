#include "CFAGroup.hpp"
#include <stdexcept>

CFAGroup::CFAGroup(std::string name) 
{ 
    this->id = -1;
    this->name = name;
    this->parent = nullptr;
}

CFAGroup::CFAGroup(int parentId, int grpId)
{
    this->id = grpId;
    this->parentId = parentId;
}

std::string CFAGroup::getName() 
{ 
    return name; 
}

int CFAGroup::getId() 
{ 
    return id; 
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
        throw (cfaErr);
    return CFAGroup(id, grpId);
}

CFAGroup CFAGroup::addGroup(std::string name)
{
    int cfaErr = cfa_def_cont(parentId, name.c_str(), &id);
    if (cfaErr)
        throw (cfaErr);
    return CFAGroup(parentId, id);
}

CFAVar CFAGroup::getVar(std::string name) 
{    
    int varId;
    int cfaErr = cfa_inq_var_id(id, name.c_str(), &varId);
    if (cfaErr)
        throw (cfaErr);
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
        throw (cfaErr);
    return cfaVar;
}

CFAVar CFAGroup::addVar(std::string name, cfa_type type, std::string dimName)
{
    CFAVar cfaVar(id, name, type);
    int cfaErr = cfaVar.updateDims(dimName);
    if(cfaErr)
        throw (cfaErr);
    return cfaVar;
}

CFAVar CFAGroup::addVar(std::string name, cfa_type type, std::vector<int> dimIds)
{
    CFAVar cfaVar(id, name, type);    
    int cfaErr = cfaVar.updateDims(dimIds);
    if(cfaErr)
        throw (cfaErr);
    return cfaVar;
}

CFAVar CFAGroup::addVar(std::string name, cfa_type type, std::vector<std::string> dimNames)
{
    CFAVar cfaVar(id, name, type);    
    int cfaErr = cfaVar.updateDims(dimNames);
    if(cfaErr)
        throw (cfaErr);
    return cfaVar;
}

CFADim CFAGroup::getDim(std::string name)
{
    int dimId;
    int cfaErr = cfa_inq_dim_id(id, name.c_str(), &dimId);
    if (cfaErr)
        throw (cfaErr);
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
        throw (cfaErr);
    return aggCont;
}