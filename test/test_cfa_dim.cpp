#include "CFADim.hpp"
#include "CFAFile.hpp"
#include "CFAGroup.hpp"
#include "CFAException.hpp"

#include <string>
#include <assert.h>
#include <iostream>

const std::string filePath = "./test.nc";
const std::string dimWithDefaultLengthName = "Default Length Dim";
const std::string dimWithLengthName = "Dim With Length";
const std::string dimWithLengthAndTypeName = "Dim With Length and Type";

void test_cfa_dim_creation() 
{
    try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);

        CFA::Dim dimWithDefaultLength(file.getId(), dimWithDefaultLengthName, 0);
        assert(dimWithDefaultLength.getId() != -1);

        CFA::Dim dimWithLength(file.getId(), dimWithLengthName, 0, 5);
        assert(dimWithLength.getId() != -1);

        CFA::Dim dimWithLengthAndType(file.getId(), dimWithLengthAndTypeName, 1, 3);
        assert(dimWithLengthAndType.getId() != -1);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void test_cfa_dim_get_length() 
{
    try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);

        CFA::Dim dimWithDefaultLength(file.getId(), dimWithDefaultLengthName, 0);
        assert(dimWithDefaultLength.getLen() == 1);

        CFA::Dim dimWithLength(file.getId(), dimWithLengthName, 0, 5);
        assert(dimWithLength.getLen() == 5);

        CFA::Dim dimWithLengthAndType(file.getId(), dimWithLengthAndTypeName, 1, 3);
        assert(dimWithLengthAndType.getLen() == 3);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void test_cfa_dim_get_name() 
{
    try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);

        CFA::Dim dimWithDefaultLength(file.getId(), dimWithDefaultLengthName, 0);
        assert(dimWithDefaultLength.getName() == dimWithDefaultLengthName);

        CFA::Dim dimWithLength(file.getId(), dimWithLengthName, 0, 5);
        assert(dimWithLength.getName() == dimWithLengthName);

        CFA::Dim dimWithLengthAndType(file.getId(), dimWithLengthAndTypeName, 1, 3);
        assert(dimWithLengthAndType.getName() == dimWithLengthAndTypeName);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void test_cfa_dim_get_type() 
{
    try
    {
        CFA::File file("./test.nc", CFA::CFANetCDF, CFA::Write);

        CFA::Dim dimWithDefaultLength(file.getId(), dimWithDefaultLengthName, 0);
        assert(dimWithDefaultLength.getType() == 0);

        CFA::Dim dimWithLength(file.getId(), dimWithLengthName, 0, 5);
        assert(dimWithLength.getType() == 0);

        CFA::Dim dimWithLengthAndType(file.getId(), dimWithLengthAndTypeName, 1, 3);
        assert(dimWithLengthAndType.getType() == 1);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main(void)
{
    test_cfa_dim_creation();
    test_cfa_dim_get_length();
    test_cfa_dim_get_name();
    test_cfa_dim_get_type();
}