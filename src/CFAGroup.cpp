#include "CFAGroup.h"

CFAGroup::CFAGroup(std::string name) { this->name = name; }

std::string CFAGroup::getName() { return name; }
int CFAGroup::getId() { return id; }

CFAGroup CFAGroup::getParentGroup() { return *parentGroup; }