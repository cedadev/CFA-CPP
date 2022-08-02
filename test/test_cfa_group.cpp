#include "CFADim.hpp"
#include "CFAVar.hpp"
#include "CFAFile.hpp"
#include "CFAGroup.hpp"
#include "CFAException.hpp"

#include <string>
#include <assert.h>
#include <iostream>

const std::string filePath = "./test.nc";
const std::string grpName = "CFA Group";

const std::string fileGrp1Name = "CFA Group - File 1";
const std::string fileGrp2Name = "CFA Group - File 2";

const std::string grpGrp1Name = "CFA Group - Group 1";
const std::string grpGrp2Name = "CFA Group - Group 2";
const std::string grpGrp3Name = "CFA Group - Group 3";
const std::string grpGrp4Name = "CFA Group - Group 4";

const std::string var1Name = "CFA Var 1";
const std::string var2Name = "CFA Var 2";
const std::string var3Name = "CFA Var 3";
const std::string var4Name = "CFA Var 4";

const std::string dim1Name = "CFA Dim 1";
const std::string dim2Name = "CFA Dim 2";
const std::string dim3Name = "CFA Dim 3";
const std::string dim4Name = "CFA Dim 4";

void test_cfa_grp_creation() 
{
    try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
        CFA::Group grp = file.addGrp(grpName);

        assert(grp.getId() != -1);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void test_cfa_grp_get_name() 
{
    try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
        CFA::Group grp = file.addGrp(grpName);

        assert(grp.getName() == grpName);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void test_cfa_grp_get_grp_count() 
{
    try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
        CFA::Group grp = file.addGrp(grpName);

        assert(file.getGrpCount() == 1);
        assert(grp.getGrpCount() == 0);

        file.addGrp(fileGrp1Name);
        file.addGrp(fileGrp2Name);

        assert(file.getGrpCount() == 3);
        assert(grp.getGrpCount() == 0);

        grp.addGrp(grpGrp1Name);
        grp.addGrp(grpGrp2Name);
        grp.addGrp(grpGrp3Name);
        grp.addGrp(grpGrp4Name);

        assert(file.getGrpCount() == 3);
        assert(grp.getGrpCount() == 4);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void test_cfa_grp_get_grp() 
{
    try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
        CFA::Group grp = file.addGrp(grpName);

        assert(file.getGrp(grpName).getId() == grp.getId());

        CFA::Group fileGrp1 = file.addGrp(fileGrp1Name);
        CFA::Group fileGrp2 = file.addGrp(fileGrp2Name);

        assert(file.getGrp(fileGrp1Name).getId() == fileGrp1.getId());
        assert(file.getGrp(fileGrp2Name).getId() == fileGrp2.getId());

        CFA::Group grpGrp1 = grp.addGrp(grpGrp1Name);
        CFA::Group grpGrp2 = grp.addGrp(grpGrp2Name);
        CFA::Group grpGrp3 = grp.addGrp(grpGrp3Name);
        CFA::Group grpGrp4 = grp.addGrp(grpGrp4Name);

        assert(grp.getGrp(grpGrp1Name).getId() == grpGrp1.getId());
        assert(grp.getGrp(grpGrp2Name).getId() == grpGrp2.getId());
        assert(grp.getGrp(grpGrp3Name).getId() == grpGrp3.getId());
        assert(grp.getGrp(grpGrp4Name).getId() == grpGrp4.getId());
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


void test_cfa_grp_get_var_count() 
{
    try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
        assert(file.getVarCount() == 0);

        file.addVar(var1Name, 0);
        assert(file.getVarCount() == 1);

        file.addVar(var2Name, 0);
        file.addVar(var3Name, 0);
        file.addVar(var4Name, 0);
        assert(file.getVarCount() == 4);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void test_cfa_grp_get_var() 
{
      try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
        CFA::Var var1 = file.addVar(var1Name, 0);
        assert(file.getVar(var1Name).getId() == var1.getId());

        CFA::Var var2 = file.addVar(var2Name, 0);
        CFA::Var var3 = file.addVar(var3Name, 0);
        CFA::Var var4 = file.addVar(var4Name, 0);
        assert(file.getVar(var2Name).getId() == var2.getId());
        assert(file.getVar(var3Name).getId() == var3.getId());
        assert(file.getVar(var4Name).getId() == var4.getId());
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }  
}

void test_cfa_grp_get_dim_count() 
{
    try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
        assert(file.getDimCount() == 0);

        file.addDim(dim1Name, 0);
        assert(file.getDimCount() == 1);

        file.addDim(dim2Name, 0);
        file.addDim(dim3Name, 0);
        file.addDim(dim4Name, 0);
        assert(file.getDimCount() == 4);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void test_cfa_grp_get_dim() 
{
      try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
        CFA::Dim dim1 = file.addDim(dim1Name, 0);
        assert(file.getDim(dim1Name).getId() == dim1.getId());

        CFA::Dim dim2 = file.addDim(dim2Name, 0);
        CFA::Dim dim3 = file.addDim(dim3Name, 0);
        CFA::Dim dim4 = file.addDim(dim4Name, 0);
        assert(file.getDim(dim2Name).getId() == dim2.getId());
        assert(file.getDim(dim3Name).getId() == dim3.getId());
        assert(file.getDim(dim4Name).getId() == dim4.getId());
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    test_cfa_grp_creation();
    test_cfa_grp_get_name();
    test_cfa_grp_get_var_count();
    test_cfa_grp_get_dim_count();
    test_cfa_grp_get_grp_count();
    test_cfa_grp_get_grp();
    test_cfa_grp_get_var();
    test_cfa_grp_get_dim();
}