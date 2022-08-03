#pragma once

#include <string>

#include "CFAGroup.hpp"
#include "CFAFileMode.hpp"
#include "CFAFileFormat.hpp"

namespace CFA
{
    class File : public Group
    {
        private:
            std::string path;
            FileMode mode;
            FileFormat format;
        public:
            File(std::string path, FileFormat format = FileFormat::CFANetCDF, FileMode mode = FileMode::Read);
            
            int getNcId();
            void enddef();
            void close();
    };
}