#include "CFAGroup.h"

CFAGroup::CFAGroup() { id = -1; }
CFAGroup::CFAGroup(std::string name) : CFAGroup() { this->name = name; }
CFAGroup::CFAGroup(std::string name, int id, CFAGroup* parent) : CFAGroup(name) 
{
    this->id = id;
    this->parent = parent;
}

std::string CFAGroup::getName() { return name; }
int CFAGroup::getId() { return id; }

CFAGroup CFAGroup::getParentGroup() { return *parent; }

CFAGroup CFAGroup::getGroup(int groupId) 
{  
    for(CFAGroup group : groups)
        if(group.getId() == groupId)
            return group;
    return CFAGroup();
}
CFAGroup CFAGroup::getGroup(std::string name) 
{  
    for(CFAGroup group : groups)
        if(group.getName() == name)
            return group;
    return CFAGroup();
}

CFAGroup CFAGroup::addGroup(std::string name)
{
    int cfaErr = cfa_def_cont(this->id, name.c_str(), &id);
    if (cfaErr)
        throw (cfaErr);
    return groups.emplace_back(name, id, this);
}