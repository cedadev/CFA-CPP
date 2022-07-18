#include "CFAFile.hpp"
#include "CFAException.hpp"

#include <string>
#include <assert.h>
#include <iostream>

const std::string filePath = "./examples/test/cfa_file_test.nc";

void test_cfa_file_creation() 
{
    try
    {
        CFA::File writeFile(filePath, CFA::CFANetCDF, CFA::Write);
        writeFile.enddef();
        writeFile.close();
    }
    catch(const CFA::Exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }

    try
    {
        CFA::File defaultFile(filePath, CFA::CFANetCDF);
    }
    catch(const CFA::Exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }
    
    try
    {
        CFA::File readFile(filePath, CFA::CFANetCDF, CFA::Read);
    }
    catch(const CFA::Exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }
}

void test_cfa_file_enddef() {}
void test_cfa_file_close() {}

int main(void)
{
    test_cfa_file_creation();
    test_cfa_file_enddef();
    test_cfa_file_close();
}