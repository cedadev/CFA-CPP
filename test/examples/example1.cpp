#include <string>
#include <string.h>
#include <netcdf.h>
#include <iostream>

#include "cfa_errs.h"
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
        int cfaErr = CFA_NOERR;

        /* Recreate Example 1 from the documentation */
        /* Create the CFA parent container */
        CFA::File file(path, CFA::FileFormat::CFANetCDF, CFA::FileMode::Write);

        /* Define the CFA Dimensions */
        /* Time */
        CFA::Dim time = file.addDim("time", CFA_DOUBLE, 12);
        /* Level */
        CFA::Dim level = file.addDim("level", CFA_DOUBLE, 1);
        /* Latitude */
        CFA::Dim latitude = file.addDim("latitude", CFA_DOUBLE, 73);
        /* Longitude */
        CFA::Dim longitude = file.addDim("longitude", CFA_DOUBLE, 144);

        /* Create a vector of dimension IDs so we can create the variable with dimensions */
        std::vector<int> tempDimIds = {time.getId(), level.getId(), latitude.getId(), longitude.getId()};
        /* Create Temp variable with dimensions */
        CFA::Var temperature = file.addVar("temp", CFA_DOUBLE, tempDimIds);

        /*Add Aggregation Instructions */
        temperature.addAggInstr("file", "aggregation_file", 0);
        temperature.addAggInstr("format", "aggregation_format", 1);
        temperature.addAggInstr("address", "aggregation_address", 0);
        temperature.addAggInstr("location", "aggregation_location", 0);

        /* Add Fragments */
        int frags[4] = {2, 1, 1, 1};
        temperature.defFragments(frags);
        /* First Fragment */
        size_t fragLocation[4] = {0, 0, 0, 0};
        temperature.addFragment(fragLocation, NULL, "January-June.nc", "nc", "temp", NULL);
        /* Second Fragment */
        fragLocation[0] = 1;
        temperature.addFragment(fragLocation, NULL, "July-December.nc", "nc", "temp", NULL);
            
        /* Output Info */
        cfaErr = cfa_info(file.getId(), 0);
        if(cfaErr)
            throw CFA::Exception(cfaErr);
        /* Write out initial structures, variables, etc. */
        file.enddef();

        /* Add metadata to the Temp variable */
        temperature.setNCAttText(file.getNcId(), "standard_name", "air_temperature");
        temperature.setNCAttText(file.getNcId(), "units", "K");
        temperature.setNCAttText(file.getNcId(), "cell_methods", "time: mean");

        /* Add metadata to the Time dimension variable */
        time.setNCAttText(file.getNcId(), "standard_name", "time");
        time.setNCAttText(file.getNcId(), "units", "days since 2001-01-01");

        /* Add metadata to the Level dimension variable */
        level.setNCAttText(file.getNcId(), "standard_name", "height_above_mean_sea_level");
        level.setNCAttText(file.getNcId(), "units", "m");

        /* Add metadata to the Latitude dimension variable */
        latitude.setNCAttText(file.getNcId(), "standard_name", "latitude");
        latitude.setNCAttText(file.getNcId(), "units", "degrees_north");

        /* Add metadata to the Longitude dimension variable */
        longitude.setNCAttText(file.getNcId(), "standard_name", "longitude");
        longitude.setNCAttText(file.getNcId(), "units", "degrees_east");

        /* Add the CF-1.9 Convention */
        char conventions[1024];
        cfaErr = nc_get_att_text(file.getNcId(), NC_GLOBAL, CONVENTIONS, conventions);
        if(cfaErr)
            throw CFA::Exception(cfaErr);
        strcat(conventions, " CF-1.9");
        cfaErr = nc_put_att_text(file.getNcId(), NC_GLOBAL, CONVENTIONS, strlen(conventions), conventions);
        if(cfaErr)
            throw CFA::Exception(cfaErr);

        /* Write the data for the time variable */
        const size_t timeStart = 0;
        const size_t timeSpan = 12;
        const int timeVals[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        cfaErr = nc_put_vara_int(file.getNcId(), time.getNcVarId(file.getNcId()), &timeStart, &timeSpan, timeVals);
        if(cfaErr)
            throw CFA::Exception(cfaErr);

        /* Output Info */
        cfaErr = cfa_info(file.getId(), 0);
        if(cfaErr)
            throw CFA::Exception(cfaErr);
        
        /* Close the CFA file (closes the netCDF file as well) */
        file.close();

        /* Check for memory leaks */
        cfaErr = cfa_memcheck();
        if(cfaErr)
            throw CFA::Exception(cfaErr);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void load()
{
    std::cout << "Example 1 Test Load\n";
    try
    {
        int cfaErr = CFA_NOERR;
        /* Load and parse the CFA parent container */
        CFA::File file(path, CFA::FileFormat::CFANetCDF, CFA::FileMode::Read);
        
        /* Get the "temp" variable */
        CFA::Var temperature = file.getVar("temp");

        /* Get the first fragment */
        size_t fragLocation[4] = {0, 0, 0, 0};
        Fragment frag1 = temperature.getFragmentByFragLocation(fragLocation);

        /* Get the fragment by data location */
        size_t dataLocation[4] = {6, 0, 0, 0};
        Fragment frag2 = temperature.getFragmentByDataLocation(dataLocation);

        /* Output Info */
        cfaErr = cfa_info(file.getId(), 0);
        if(cfaErr)
            throw CFA::Exception(cfaErr);

        /* Close file - frees the memory */
        file.close();

        /* Check for memory leaks */
        cfaErr = cfa_memcheck();
        if(cfaErr)
            throw CFA::Exception(cfaErr);
    }
    catch(const CFA::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

int main(void)
{
    save();
    load();
}