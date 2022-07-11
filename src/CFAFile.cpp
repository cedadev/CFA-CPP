#include "CFAFile.hpp"
#include <stdexcept>

CFAFile::CFAFile(std::string path, CFACpp::CFAFileFormat format, CFAFileMode mode)
{
    this->mode = mode;
    int cfa_err = cfa_create(path.c_str(), (CFAFileFormat)format, &id);
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