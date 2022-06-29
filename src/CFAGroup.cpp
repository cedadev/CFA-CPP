#include "CFAGroup.h"

CFAGroup::CFAGroup() {}
CFAGroup::CFAGroup(std::string name) { this->name = name; }

std::string CFAGroup::getName() { return name; }
int CFAGroup::getId() { return id; }

CFAGroup CFAGroup::getParentGroup() { return *parent; }

CFAGroup CFAGroup::getGroup(int groupId) 
{  
    for(CFAGroup group : groups)
        if(group.getId() == groupId)
            return group;
}
CFAGroup CFAGroup::getGroup(std::string name) 
{  
    for(CFAGroup group : groups)
        if(group.getName() == name)
            return group;
}

CFAGroup CFAGroup::addGroup(std::string name)
{
    int cfaErr = cfa_def_cont(this->id, name.c_str(), &id);
    if (cfaErr)
        throw (cfaErr);
    return groups.emplace_back(name, id, this);
}