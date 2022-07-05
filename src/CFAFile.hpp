#pragma once

#include <string>

#include "CFAGroup.hpp"
#include "CFAFileMode.hpp"

// declare CFA-C library as external C library
extern "C" {
    #include "cfa.h"
}

class CFAFile : CFAGroup
{
    private:
        std::string path;
        CFAFileMode mode;
        CFAFileFormat format;
    public:
        CFAFile(std::string path);
        CFAFile(std::string path, CFAFileFormat format, CFAFileMode mode = CFAFileMode::READ);

        void open(std::string path, CFAFileFormat format);
        void create(std::string path, CFAFileFormat format);
        void enddef();
        void close();
};