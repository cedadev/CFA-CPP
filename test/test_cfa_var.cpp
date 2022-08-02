#include "CFADim.hpp"
#include "CFAVar.hpp"
#include "CFAFile.hpp"
#include "CFAGroup.hpp"
#include "CFAException.hpp"

#include <string>
#include <assert.h>
#include <iostream>

const std::string filePath = "./test.nc";
const std::string varName = "CFA Var";
const std::string dim1Name = "CFA Dim 1";
const std::string dim2Name = "CFA Dim 2";
const std::string dim3Name = "CFA Dim 3";

void test_cfa_var_creation() 
{
    try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
        CFA::Var var = file.addVar(varName, 0);

        assert(var.getId() != -1);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << "test_cfa_var_creation: " << e.what() << '\n';
    }
}

void test_cfa_var_get_name()
{
    try
    {        
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
        CFA::Var var = file.addVar(varName, 0);

        assert(var.getName() == varName);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << "test_cfa_var_get_name: " << e.what() << '\n';
    }
}

void test_cfa_var_get_type()
{
    try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
        CFA::Var var = file.addVar(varName, 0);

        assert(var.getType() == 0);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << "test_cfa_var_get_type: " << e.what() << '\n';
    }
}

void test_cfa_var_get_dim()
{
    try
    {        
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);

        CFA::Dim dim1 = file.addDim(dim1Name, 0);
        CFA::Dim dim2 = file.addDim(dim2Name, 0);
        CFA::Dim dim3 = file.addDim(dim3Name, 0);

        std::vector<int> dimIds = {dim1.getId(), dim2.getId(), dim3.getId()};
        CFA::Var var = file.addVar(varName, 0, dimIds);

        assert(var.getDim(0).getId() == dim1.getId());
        assert(var.getDim(1).getId() == dim2.getId());
        assert(var.getDim(2).getId() == dim3.getId());
    }
    catch(const CFA::Exception& e)
    {        
        std::cerr << "test_cfa_var_get_dim: " << e.what() << '\n';
    }
}

void test_cfa_var_get_dims()
{
    try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);

        CFA::Dim dim1 = file.addDim(dim1Name, 0);
        CFA::Dim dim2 = file.addDim(dim2Name, 0);
        CFA::Dim dim3 = file.addDim(dim3Name, 0);

        std::vector<int> dimIds = {dim1.getId(), dim2.getId(), dim3.getId()};
        CFA::Var var = file.addVar(varName, 0, dimIds);

        std::vector<CFA::Dim> dims = var.getDims();
        for(int i = 0; i < dims.size(); i++)
        {
            assert(dims[i].getId() == dimIds[i]);
        }
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << "test_cfa_var_get_dims: " << e.what() << '\n';
    }
}

void test_cfa_var_get_dim_names()
{
    try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);

        CFA::Dim dim1 = file.addDim(dim1Name, 0);
        CFA::Dim dim2 = file.addDim(dim2Name, 0);
        CFA::Dim dim3 = file.addDim(dim3Name, 0);

        std::vector<int> dimIds = {dim1.getId(), dim2.getId(), dim3.getId()};
        CFA::Var var = file.addVar(varName, 0, dimIds);

        std::vector<std::string> dimNames = var.getDimNames();
        assert(dimNames[0] == dim1.getName());
        assert(dimNames[1] == dim2.getName());
        assert(dimNames[2] == dim3.getName());
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << "test_cfa_var_get_dim_names: " << e.what() << '\n';
    }    
}

void test_cfa_var_get_dim_count() 
{
    try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);

        CFA::Dim dim1 = file.addDim(dim1Name, 0);
        CFA::Dim dim2 = file.addDim(dim2Name, 0);
        CFA::Dim dim3 = file.addDim(dim3Name, 0);

        std::vector<int> dimIds {dim1.getId(), dim2.getId(), dim3.getId()};
        CFA::Var var = file.addVar(varName, 0, dimIds);
        
        assert(var.getDimCount() == 3);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << "test_cfa_var_get_dim_count: " << e.what() << '\n';
    }
}

int main(void)
{
    test_cfa_var_creation();
    test_cfa_var_get_name();
    test_cfa_var_get_type();
    test_cfa_var_get_dim();
    test_cfa_var_get_dims();
    test_cfa_var_get_dim_names();
    test_cfa_var_get_dim_count();
    std::cout << "CFA Var Tests Passed Successfully\n";
}