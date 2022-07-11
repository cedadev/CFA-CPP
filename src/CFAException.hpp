#pragma once
#include <stdexcept>

class CFAException : std::exception
{
    private:
        char *message;
    public:
        CFAException(char *message);
        char *what();
};