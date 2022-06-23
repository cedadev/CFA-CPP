#include "CFAGroup.h"

CFAGroup::CFAGroup()
{
}

CFAGroup::CFAGroup(std::string name) 
{
    this->name = name; 
}

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
    int new_grp_id = -1;
    int cfa_err = cfa_def_cont(this->id, name.c_str(), &new_grp_id);
    if (cfa_err)
        throw (cfa_err);

    groups.push_back(name);
    groups.back().id = new_grp_id;
    groups.back().parent = this;
    return groups.back();
}
CFAGroup CFAGroup::addGroup(std::string name)
{
    return groups.emplace_back(name, 0, this);
}