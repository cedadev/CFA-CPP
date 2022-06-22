#include "CFAGroup.h"

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
    groups.push_back(name);
    groups.back().id = 0;
    groups.back().parent = this;
    return groups.back();
}
CFAGroup CFAGroup::addGroup(std::string name)
{
    return groups.emplace_back(name, 0, this);
}