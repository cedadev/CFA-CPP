#include "CFAFile.hpp"
#include "CFAException.hpp"

CFA::File::File(std::string path, FileFormat format, FileMode mode)
{
    // open if read and create if write
    this->mode = mode;
    int cfaErr = cfa_create(path.c_str(), (CFAFileFormat)format, &id);
    if(cfaErr)
        throw Exception(cfaErr);
}

void CFA::File::open(std::string path, CFAFileFormat format)
{
    int cfaErr = cfa_load(path.c_str(), format, &id);
    if(cfaErr)
        throw Exception(cfaErr);
}
void CFA::File::create(std::string path, CFAFileFormat format)
{
    int cfaErr = cfa_create(path.c_str(), format, &id);
    if(cfaErr)
        throw Exception(cfaErr);
}
void CFA::File::enddef()
{
    // serialise if write nothing if anything else
    int cfaErr = cfa_serialise(id);
    if(cfaErr)
        throw Exception(cfaErr);
}
void CFA::File::close()
{
    int cfaErr = cfa_close(id);
    if(cfaErr)
        throw Exception(cfaErr);
}