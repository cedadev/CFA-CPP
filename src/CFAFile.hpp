#pragma once

#include <string>

#include "CFAGroup.hpp"
#include "CFAFileMode.hpp"
#include "CFAFileFormat.hpp"

class CFAFile : CFAGroup
{
    private:
        std::string path;
        CFAFileMode mode;
        CFAFileFormat format;
    public:
        CFAFile(std::string path, CFACpp::CFAFileFormat format = CFACpp::CFAFileFormat::CFANetCDF, CFAFileMode mode = CFAFileMode::Read);

        void open(std::string path, CFAFileFormat format);
        void create(std::string path, CFAFileFormat format);
        void enddef();
        void close();
};