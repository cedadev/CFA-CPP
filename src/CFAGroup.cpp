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

CFAGroup CFAGroup::getGroup(int id) 
{  
    throw std::runtime_error("Not implemented");
    auto it = std::find_if(groups.begin(), groups.end(), [id](CFAGroup& group) { return group.getId() == id; });
    if(it != groups.end())
        return *it;
    else
        throw std::runtime_error("Found no group with id!");
}

CFAGroup CFAGroup::getGroup(std::string name) 
{  
    throw std::runtime_error("Not implemented");
    auto it = std::find_if(groups.begin(), groups.end(), [name](CFAGroup& group) { return group.getName() == name; });
    if(it != groups.end())
        return *it;
    else
        throw std::runtime_error("Found no group with name!");
}

CFAGroup CFAGroup::addGroup(std::string name)
{
    int cfaErr = cfa_def_cont(parentId, name.c_str(), &id);
    if (cfaErr)
        throw (cfaErr);
    return CFAGroup(parentId, id);
}

CFAVar CFAGroup::getVar(int id) 
{ 
    throw std::runtime_error("Not implemented");
    auto it = std::find_if(vars.begin(), vars.end(), [id](CFAVar& var) { return var.getId() == id; });
    if(it != vars.end())
        return *it;
    else
        throw std::runtime_error("Found no var with id!");
}

CFAVar CFAGroup::getVar(std::string name) 
{  
    throw std::runtime_error("Not implemented");
    auto it = std::find_if(vars.begin(), vars.end(), [name](CFAVar& var) { return var.getName() == name; });
    if(it != vars.end())
        return *it;
    else
        throw std::runtime_error("Found no var with name!");
}

CFAVar CFAGroup::addVar(std::string name, cfa_type type)
{
    return vars.emplace_back(id, name, type);
}

CFAVar CFAGroup::addVar(std::string name, cfa_type type, int dimId)
{
    vars.emplace_back(id, name, type);
    int cfaErr = vars.back().updateDims(dimId);
    if(cfaErr)
        throw (cfaErr);
    return vars.back();
}

CFAVar CFAGroup::addVar(std::string name, cfa_type type, std::string dimName)
{
    vars.emplace_back(id, name, type);
    int cfaErr = vars.back().updateDims(dimName);
    if(cfaErr)
        throw (cfaErr);
    return vars.back();
}

CFAVar CFAGroup::addVar(std::string name, cfa_type type, std::vector<int> dimIds)
{
    vars.emplace_back(id, name, type);    
    int cfaErr = vars.back().updateDims(dimIds);
    if(cfaErr)
        throw (cfaErr);
    return vars.back();
}

CFAVar CFAGroup::addVar(std::string name, cfa_type type, std::vector<std::string> dimNames)
{
    vars.emplace_back(id, name, type);    
    int cfaErr = vars.back().updateDims(dimNames);
    if(cfaErr)
        throw (cfaErr);
    return vars.back();
}

CFADim CFAGroup::getDim(int id)
{
    throw std::runtime_error("Not implemented");
    auto it = std::find_if(dims.begin(), dims.end(), [id](CFADim& dim) { return dim.getId() == id; });
    if(it != dims.end())
        return *it;
    else
        throw std::runtime_error("Found no dim with id!");
}

CFADim CFAGroup::getDim(std::string name)
{
    throw std::runtime_error("Not implemented");
    auto it = std::find_if(dims.begin(), dims.end(), [name](CFADim& dim) { return dim.getName() == name; });
    if(it != dims.end())
        return *it;
    else
        throw std::runtime_error("Found no dim with name!");
}

CFADim CFAGroup::addDim(std::string name, cfa_type type)
{
    return dims.emplace_back(id, name, type);
}

CFADim CFAGroup::addDim(std::string name, cfa_type type, int dimLen)
{
    return dims.emplace_back(id, name, type, dimLen);
}

AggregationContainer* CFAGroup::getAggCont()
{
    AggregationContainer *aggCont;
    int cfaErr = cfa_get_cont(parentId, id, &aggCont);
    if (cfaErr)
        throw (cfaErr);
    return aggCont;
}