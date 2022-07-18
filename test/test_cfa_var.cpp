#include "CFADim.hpp"
#include "CFAVar.hpp"
#include "CFAFile.hpp"
#include "CFAGroup.hpp"

#include <string>
#include <assert.h>

const std::string filePath = "./test.nc";
const std::string groupName = "CFA Group Test";
const std::string varName = "CFA Var Test";

void test_cfa_var_creation() 
{
    CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
    CFA::Group group(file.getId(), groupName);

    CFA::Var var(group.getId(), varName, 0);
    assert(var.getId() != -1);
}

void test_cfa_var_get_dim_count() 
{

}

void test_cfa_var_get_name()
{
    CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
    CFA::Group group(file.getId(), groupName);

    CFA::Var var(group.getId(), varName, 0);
    assert(var.getName() == varName);
}

void test_cfa_var_get_type()
{
    CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
    CFA::Group group(file.getId(), groupName);

    CFA::Var var(group.getId(), varName, 3);
    assert(var.getType() == 3);
}

void test_cfa_var_get_dim()
{

}

void test_cfa_var_get_dims()
{

}

void test_cfa_var_get_dim_names()
{

}

void test_cfa_var_update_dim()
{

}

int main(void)
{
    test_cfa_var_creation();
    test_cfa_var_get_dim_count();
    test_cfa_var_get_name();
    test_cfa_var_get_type();
    test_cfa_var_get_dim();
    test_cfa_var_get_dims();
    test_cfa_var_get_dim_names();
    test_cfa_var_update_dim();
}