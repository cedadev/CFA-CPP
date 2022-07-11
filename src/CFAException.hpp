#pragma once
#include <stdexcept>

class CFAException : std::exception
{
    private:
        std::string message;
    public:
        CFAException(int errorCode);
        const char *what();
};