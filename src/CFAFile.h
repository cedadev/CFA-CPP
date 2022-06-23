#ifndef CFADATASET_H
#define CFADATASET_H

#include <string>

#include "CFAGroup.h"

// declare CFA-C library as external C library
extern "C" {
    #include "cfa.h"
}

class CFAFile : public CFAGroup
{
    public:
        CFAFile(std::string path);

};

#endif