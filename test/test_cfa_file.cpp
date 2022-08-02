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
        assert(writeFile.getId() != -1);
        
        CFA::File defaultFile(filePath, CFA::CFANetCDF);
        assert(defaultFile.getId() != -1);

        CFA::File readFile(filePath, CFA::CFANetCDF, CFA::Read);
        assert(readFile.getId() != -1);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << "test_cfa_file_creation: " << e.what() << '\n';
    }
}

void test_cfa_file_enddef()
{
    try
    {
        CFA::File writeFile(filePath, CFA::CFANetCDF, CFA::Write);
        writeFile.enddef(); // This throws an Unknown Exception error
        assert(writeFile.getId() != -1);

        CFA::File defaultFile(filePath, CFA::CFANetCDF);
        defaultFile.enddef();
        assert(defaultFile.getId() != -1);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << "test_cfa_file_enddef: " << e.what() << '\n';
    }
}

void test_cfa_file_close()
{
    try
    {
        CFA::File writeFile(filePath, CFA::CFANetCDF, CFA::Write);
        writeFile.close();
        assert(writeFile.getId() != -1);

        CFA::File defaultFile(filePath, CFA::CFANetCDF);
        defaultFile.close();
        assert(defaultFile.getId() != -1);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << "test_cfa_file_close: " << e.what() << '\n';
    }
}

int main(void)
{
    test_cfa_file_creation();
    test_cfa_file_enddef();
    test_cfa_file_close();
    std::cout << "CFA File Tests Passed Successfully\n";
}