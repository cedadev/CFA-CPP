#include "CFAFile.h"
#include <stdexcept>

CFAFile::CFAFile(std::string path)
{
    /* Have an enum for file format */
    int cfa_id = -1;
    int cfa_err = cfa_create(path.c_str(), CFA_NETCDF, &cfa_id);
    if (cfa_err)
        throw std::runtime_error("Stop!");
}