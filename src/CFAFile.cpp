#include "CFAFile.h"
#include <stdexcept>

CFAFile::CFAFile(std::string path)
{
    /* Have an enum for file format */
    int cfa_idp;
    int err = cfa_create(path.c_str(), CFA_NETCDF, &cfa_idp);
    if (err)
        throw std::runtime_error("Stop!");
}