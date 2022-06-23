#ifndef CFADATASET_H
#define CFADATASET_H

#include <string>

#include "CFAGroup.h"

// declare CFA-C library as external C library
extern "C" {
    #include "cfa.h"
}

class CFAFileMode;

class CFAFile
{
    public:
        CFAFile(std::string path);
        CFAFile(std::string path, CFAFileFormat format, CFAFileMode mode);

        void open(std::string path, CFAFileFormat format);
        void create(std::string path, CFAFileFormat format);
        void enddef();
        void close();
};

#endif