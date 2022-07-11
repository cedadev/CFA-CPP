#include "CFAException.hpp"

CFAException::CFAException(char *message) : message(message) 
{

}

char *CFAException::what() 
{
    return message;
}