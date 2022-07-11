#include "CFAException.hpp"

CFAException::CFAException(int errorCode) 
{
    message = "Generic CFA Exception with code: ";
    message.append(std::to_string(errorCode));
}

const char *CFAException::what() 
{
    return message.c_str();
}