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

void test_cfa_grp_creation() 
{
    try
    {
        CFA::File file(filePath, CFA::CFANetCDF, CFA::Write);
        CFA::Group grp = file.addGrp(grpName);

        assert(grp.getId() != -1);
    }
    catch(const CFA::Exception& ex)
    {
        std::cerr << ex.what() << '\n';
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
    catch(const CFA::Exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }
}

void test_cfa_grp_get_var_count() 
{

}

void test_cfa_grp_get_dim_count() 
{

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
    catch(const CFA::Exception& ex)
    {
        std::cerr << ex.what() << '\n';
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
    catch(const CFA::Exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }
}

void test_cfa_grp_add_grp() 
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
    catch(const CFA::Exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }
}

void test_cfa_grp_get_var() {}
void test_cfa_grp_add_var() {}
void test_cfa_grp_get_dim() {}
void test_cfa_grp_add_dim() {}

int main()
{
    test_cfa_grp_creation();
    test_cfa_grp_get_name();
    test_cfa_grp_get_var_count();
    test_cfa_grp_get_dim_count();
    test_cfa_grp_get_grp_count();
    test_cfa_grp_get_grp();
    test_cfa_grp_add_grp();
    test_cfa_grp_get_var();
    test_cfa_grp_add_var();
    test_cfa_grp_get_dim();
    test_cfa_grp_add_dim();
}