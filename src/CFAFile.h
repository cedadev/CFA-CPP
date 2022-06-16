#ifndef CFADATASET_H
#define CFADATASET_H

#include <string>

// declare CFA-C library as external C library
extern "C" {
    #include "cfa.h"
}

class CFAFile
{
    public:
        CFAFile(std::string path);
};

#endif