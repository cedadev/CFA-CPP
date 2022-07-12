#include "CFAException.hpp"

CFA::Exception::Exception(int errorCode) 
{
    message = "Generic CFA Exception: ";
    message.append(std::to_string(errorCode));
}

const char *CFA::Exception::what() 
{
    return message.c_str();
}