# CFA-CPP
C++ bindings for the CFA-C reference implementation of the CFA conventions

## Goal
Currently, [NetCDF](https://github.com/ncasuk/ncas-isc/tree/main/python/presentations/read_write_data) files managed by CEDA are on disk/tape and we want to move them to ObjectStorage but they are too large to be sent over the internet. This library makes use of the [CFA-C](https://github.com/cedadev/CFA-C) library in order to split the NetCDF files up so that users can access them over the internet.

## Resources and Conventions
Current naming conventions follow the [NetCDF++](http://unidata.github.io/netcdf-cxx4/ncDim_8h_source.html) library conventions.

# Changlog
15/06/2022 - Initial project skeleton, VSCode project and Vagrant VM for testing setup
