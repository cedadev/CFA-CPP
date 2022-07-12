#pragma once

#include <string>

#include "CFAGroup.hpp"
#include "CFAFileMode.hpp"
#include "CFAFileFormat.hpp"

namespace CFA
{
    class File : Group
    {
        private:
            std::string path;
            FileMode mode;
            FileFormat format;
        public:
            File(std::string path, FileFormat format = FileFormat::CFANetCDF, FileMode mode = FileMode::Read);
            
            void enddef();
            void close();
    };
}