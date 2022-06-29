#include "CFAGroup.h"
#include <stdexcept>

CFAGroup::CFAGroup() { id = -1; }
CFAGroup::CFAGroup(std::string name) : CFAGroup() { this->name = name; }
CFAGroup::CFAGroup(std::string name, int id, CFAGroup* parent) : CFAGroup(name) 
{
    this->id = id;
    this->parent = parent;
}

std::string CFAGroup::getName() { return name; }
int CFAGroup::getId() { return id; }
int CFAGroup::getVarCount() { return vars.size(); }
int CFAGroup::getDimCount() { return dims.size(); }
int CFAGroup::getGroupCount() { return groups.size(); }

CFAGroup CFAGroup::getParentGroup() { return *parent; }

CFAGroup CFAGroup::getGroup(int id) 
{  
    auto it = std::find_if(groups.begin(), groups.end(), [id](CFAGroup& group) { return group.getId() == id; });
    if(it != groups.end())
        return *it;
    else
        throw std::runtime_error("Found no group with id!");
}
CFAGroup CFAGroup::getGroup(std::string name) 
{  
    auto it = std::find_if(groups.begin(), groups.end(), [name](CFAGroup& group) { return group.getName() == name; });
    if(it != groups.end())
        return *it;
    else
        throw std::runtime_error("Found no group with name!");
}

CFAGroup CFAGroup::addGroup(std::string name)
{
    int cfaErr = cfa_def_cont(this->id, name.c_str(), &id);
    if (cfaErr)
        throw (cfaErr);
    return groups.emplace_back(name, id, this);
}

CFAVar CFAGroup::getVar(int id) 
{ 
    auto it = std::find_if(vars.begin(), vars.end(), [id](CFAVar& var) { return var.getId() == id; });
    if(it != vars.end())
        return *it;
    else
        throw std::runtime_error("Found no var with id!");
}
CFAVar CFAGroup::getVar(std::string name) 
{  
    auto it = std::find_if(vars.begin(), vars.end(), [name](CFAVar& var) { return var.getName() == name; });
    if(it != vars.end())
        return *it;
    else
        throw std::runtime_error("Found no var with name!");
}

CFAVar CFAGroup::addVar(std::string name, cfa_type type)
{
    throw std::runtime_error("Not Implemented");
}
CFAVar CFAGroup::addVar(std::string name, cfa_type type, std::string dimName)
{
    throw std::runtime_error("Not Implemented");
}
CFAVar CFAGroup::addVar(std::string name, cfa_type type, std::vector<std::string> dimNames)
{
    throw std::runtime_error("Not Implemented");
}
CFAVar CFAGroup::addVar(std::string name, std::vector<int> dimIds)
{
    throw std::runtime_error("Not Implemented");
}

CFADim CFAGroup::getDim(int id)
{
    auto it = std::find_if(dims.begin(), dims.end(), [id](CFADim& dim) { return dim.getId() == id; });
    if(it != dims.end())
        return *it;
    else
        throw std::runtime_error("Found no dim with id!");
}
CFADim CFAGroup::getDim(std::string name)
{
    auto it = std::find_if(dims.begin(), dims.end(), [name](CFADim& dim) { return dim.getName() == name; });
    if(it != dims.end())
        return *it;
    else
        throw std::runtime_error("Found no dim with name!");
}

CFADim CFAGroup::addDim(std::string name, cfa_type type)
{
    throw std::runtime_error("Not Implemented");
}
CFADim CFAGroup::addDim(std::string name, cfa_type type, int dimLen)
{
    throw std::runtime_error("Not Implemented");
}