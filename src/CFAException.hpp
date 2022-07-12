#pragma once
#include <stdexcept>

namespace CFA
{
    class Exception : std::exception
    {
        private:
            std::string message;
        public:
            Exception(int errorCode);
            const char *what();
    };
}