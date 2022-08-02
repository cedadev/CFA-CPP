#include <string>
#include <iostream>

#include "cfa_types.h"

#include "CFAFile.hpp"
#include "CFAFileMode.hpp"
#include "CFAFileFormat.hpp"
#include "CFAException.hpp"

const std::string path = "./examples/test/example1.nc";

void save()
{
    std::cout << "Example 1 Test Save\n";
    try
    {
        CFA::File file(path, CFA::FileFormat::CFANetCDF, CFA::FileMode::Read);
        file.addDim("time", CFA_DOUBLE, 12);
        file.addDim("level", CFA_DOUBLE, 1);
        file.addDim("latitude", CFA_DOUBLE, 73);
        file.addDim("longitude", CFA_DOUBLE, 144);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}

void load()
{

}

int main(void)
{
    save();
}