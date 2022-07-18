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
    CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
    CFA::Group group(file.getId(), groupName);
    CFA::Var var(group.getId(), varName, 0);

    CFA::Dim dim1(group.getId(), "CFA Dim 1", 0);
    CFA::Dim dim2(group.getId(), "CFA Dim 2", 0);
    CFA::Dim dim3(group.getId(), "CFA Dim 3", 0);

    std::vector<int> dimIds = {dim1.getId(), dim2.getId(), dim3.getId()};
    var.updateDims(dimIds);
    assert(var.getDimCount() == 3);
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
    CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
    CFA::Group group(file.getId(), groupName);
    CFA::Var var(group.getId(), varName, 0);

    CFA::Dim dim1(group.getId(), "CFA Dim 1", 0);
    CFA::Dim dim2(group.getId(), "CFA Dim 2", 0);
    CFA::Dim dim3(group.getId(), "CFA Dim 3", 0);

    std::vector<int> dimIds = {dim1.getId(), dim2.getId(), dim3.getId()};
    var.updateDims(dimIds);
    assert(var.getDim(0).getId() == dim1.getId());
    assert(var.getDim(1).getId() == dim2.getId());
    assert(var.getDim(2).getId() == dim3.getId());
}

void test_cfa_var_get_dims()
{
    CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
    CFA::Group group(file.getId(), groupName);
    CFA::Var var(group.getId(), varName, 0);

    CFA::Dim dim1(group.getId(), "CFA Dim 1", 0);
    CFA::Dim dim2(group.getId(), "CFA Dim 2", 0);
    CFA::Dim dim3(group.getId(), "CFA Dim 3", 0);

    std::vector<int> dimIds = {dim1.getId(), dim2.getId(), dim3.getId()};
    var.updateDims(dimIds);

    std::vector<CFA::Dim> dims = var.getDims();
    for(int i = 0; i < dims.size(); i++)
    {
        assert(dims[i].getId() == dimIds[i]);
    }
}

void test_cfa_var_get_dim_names()
{
    CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
    CFA::Group group(file.getId(), groupName);
    CFA::Var var(group.getId(), varName, 0);

    CFA::Dim dim1(group.getId(), "CFA Dim 1", 0);
    CFA::Dim dim2(group.getId(), "CFA Dim 2", 0);
    CFA::Dim dim3(group.getId(), "CFA Dim 3", 0);

    std::vector<int> dimIds = {dim1.getId(), dim2.getId(), dim3.getId()};
    var.updateDims(dimIds);

    std::vector<std::string> dimNames = var.getDimNames();
    assert(dimNames[0] == dim1.getName());
    assert(dimNames[1] == dim2.getName());
    assert(dimNames[2] == dim3.getName());
}

void test_cfa_var_update_dim()
{
    CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
    CFA::Group group(file.getId(), groupName);
    CFA::Var var(group.getId(), varName, 0);

    CFA::Dim dim1(group.getId(), "CFA Dim 1", 0);
    CFA::Dim dim2(group.getId(), "CFA Dim 2", 0);
    CFA::Dim dim3(group.getId(), "CFA Dim 3", 0);

    std::vector<int> dimIds = {dim1.getId(), dim2.getId(), dim3.getId()};
    var.updateDims(dimIds);

    assert(var.getDimCount() == 3);
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