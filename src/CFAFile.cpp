#include "CFAFile.h"
#include <stdexcept>

CFAFile::CFAFile(std::string path)
{
    /* Have an enum for file format */
    int cfa_err = cfa_create(path.c_str(), CFA_NETCDF, &id);
    if (cfa_err)
        throw std::runtime_error("Stop!");
}
CFAFile::CFAFile(std::string path, CFAFileFormat format, CFAFileMode mode)
{
    this->mode = mode;
    int cfa_err = cfa_create(path.c_str(), format, &id);
    if(cfa_err)
        throw std::runtime_error("Stop!");
}

void CFAFile::open(std::string path, CFAFileFormat format)
{
    int cfa_err = cfa_load(path.c_str(), format, &id);
    if(cfa_err)
        throw std::runtime_error("Stop!");
}
void CFAFile::create(std::string path, CFAFileFormat format)
{
    int cfa_err = cfa_create(path.c_str(), format, &id);
    if(cfa_err)
        throw std::runtime_error("Stop!");
}
void CFAFile::enddef()
{
    int cfa_err = cfa_serialise(id);
    if(cfa_err)
        throw std::runtime_error("Stop!");
}
void CFAFile::close()
{
    int cfa_err = cfa_close(id);
    if(cfa_err)
        throw std::runtime_error("Stop!");
}