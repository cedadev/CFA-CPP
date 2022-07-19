#include "CFAFile.hpp"
#include "CFAException.hpp"

CFA::File::File(std::string path, FileFormat format, FileMode mode) : CFA::Group::Group(CFA::Group::rootGroupParentId)
{
    this->mode = mode;
    int cfaErr = 0;
    if(this->mode == FileMode::Read)
        cfaErr = cfa_load(path.c_str(), (CFAFileFormat)format, &id);
    
    if(this->mode == FileMode::Write)
        cfaErr = cfa_create(path.c_str(), (CFAFileFormat)format, &id);

    if(cfaErr)
        throw Exception(cfaErr);
}

void CFA::File::enddef()
{
    int cfaErr = 0;
    if(mode == FileMode::Write)
        cfaErr = cfa_serialise(id);
        
    if(cfaErr)
        throw Exception(cfaErr);
}
void CFA::File::close()
{
    int cfaErr = cfa_close(id);
    if(cfaErr)
        throw Exception(cfaErr);
}