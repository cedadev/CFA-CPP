#include "CFADim.hpp"
#include "CFAFile.hpp"
#include "CFAGroup.hpp"

#include <string>
#include <assert.h>

const std::string dimWithDefaultLengthName = "Default Length Dim";
const std::string dimWithLengthName = "Dim With Length";
const std::string dimWithLengthAndTypeName = "Dim With Length and Type";

void test_cfa_dim_creation() 
{
    CFA::File file("./test.nc", CFA::CFANetCDF, CFA::Write);
    CFA::Group group(file.getId(), "Test Group");

    CFA::Dim dimWithDefaultLength(group.getId(), dimWithDefaultLengthName, 0);
    assert(dimWithDefaultLength.getId() != -1);

    CFA::Dim dimWithLength(group.getId(), dimWithLengthName, 0, 5);
    assert(dimWithLength.getId() != -1);

    CFA::Dim dimWithLengthAndType(group.getId(), dimWithLengthAndTypeName, 1, 3);
    assert(dimWithLengthAndType.getId() != -1);
}

void test_cfa_dim_get_length() 
{
    CFA::File file("./test.nc", CFA::CFANetCDF, CFA::Write);
    CFA::Group group(file.getId(), "Test Group");

    CFA::Dim dimWithDefaultLength(group.getId(), dimWithDefaultLengthName, 0);
    assert(dimWithDefaultLength.getLen() == 1);

    CFA::Dim dimWithLength(group.getId(), dimWithLengthName, 0, 5);
    assert(dimWithLength.getLen() == 5);

    CFA::Dim dimWithLengthAndType(group.getId(), dimWithLengthAndTypeName, 1, 3);
    assert(dimWithLengthAndType.getLen() == 3);
}

void test_cfa_dim_get_name() 
{
    CFA::File file("./test.nc", CFA::CFANetCDF, CFA::Write);
    CFA::Group group(file.getId(), "Test Group");

    CFA::Dim dimWithDefaultLength(group.getId(), dimWithDefaultLengthName, 0);
    assert(dimWithDefaultLength.getName() == dimWithDefaultLengthName);

    CFA::Dim dimWithLength(group.getId(), dimWithLengthName, 0, 5);
    assert(dimWithLength.getName() == dimWithLengthName);

    CFA::Dim dimWithLengthAndType(group.getId(), dimWithLengthAndTypeName, 1, 3);
    assert(dimWithLengthAndType.getName() == dimWithLengthAndTypeName);
}

void test_cfa_dim_get_type() 
{
    CFA::File file("./test.nc", CFA::CFANetCDF, CFA::Write);
    CFA::Group group(file.getId(), "Test Group");

    CFA::Dim dimWithDefaultLength(group.getId(), dimWithDefaultLengthName, 0);
    assert(dimWithDefaultLength.getType() == 0);

    CFA::Dim dimWithLength(group.getId(), dimWithLengthName, 0, 5);
    assert(dimWithLength.getType() == 0);

    CFA::Dim dimWithLengthAndType(group.getId(), dimWithLengthAndTypeName, 1, 3);
    assert(dimWithLengthAndType.getType() == 1);
}

int main(void)
{
    test_cfa_dim_creation();
    test_cfa_dim_get_length();
    test_cfa_dim_get_name();
    test_cfa_dim_get_type();
}