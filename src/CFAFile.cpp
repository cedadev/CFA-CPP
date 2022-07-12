#include "CFAFile.hpp"
#include "CFAException.hpp"

CFAFile::CFAFile(std::string path, CFACpp::CFAFileFormat format, CFAFileMode mode)
{
    // open if read and create if write
    this->mode = mode;
    int cfaErr = cfa_create(path.c_str(), (CFAFileFormat)format, &id);
    if(cfaErr)
        throw CFAException(cfaErr);
}

void CFAFile::open(std::string path, CFAFileFormat format)
{
    int cfaErr = cfa_load(path.c_str(), format, &id);
    if(cfaErr)
        throw CFAException(cfaErr);
}
void CFAFile::create(std::string path, CFAFileFormat format)
{
    int cfaErr = cfa_create(path.c_str(), format, &id);
    if(cfaErr)
        throw CFAException(cfaErr);
}
void CFAFile::enddef()
{
    // serialise if write nothing if anything else
    int cfaErr = cfa_serialise(id);
    if(cfaErr)
        throw CFAException(cfaErr);
}
void CFAFile::close()
{
    int cfaErr = cfa_close(id);
    if(cfaErr)
        throw CFAException(cfaErr);
}