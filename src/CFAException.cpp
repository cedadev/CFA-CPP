#include "cfa_errs.h"
#include "CFAException.hpp"

CFA::Exception::Exception(int errCode) 
{
    switch(errCode)
    {
        case CFA_MEM_ERR:
            message = "Cannot create memory";
            break;
        case CFA_MEM_LEAK:
            message = "Debugging check for memory leak";
            break;
        case CFA_BOUNDS_ERR:
            message = "Bounds error in dynamic array";
            break;
        case CFA_EOS:
            message = "End of string";
            break;
        case CFA_NOT_FOUND_ERR:
            message = "Cannot find CFA Group";
            break;
        case CFA_DIM_NOT_FOUND_ERR:
            message = "Cannot find CFA Dimension";
            break;
        case CFA_VAR_NOT_FOUND_ERR:
            message = "Cannot find CFA Variable";
            break;
        case CFA_VAR_NO_AGG_INSTR:
            message = "Aggregation instructions missing";
            break;
        case CFA_VAR_FRAGS_DEF:
            message = "Fragments already defined";
            break;
        case CFA_VAR_FRAGS_UNDEF:
            message = "Fragments not defined yet";
            break;
        case CFA_VAR_FRAG_DIM_NOT_FOUND:
            message = "Fragment dimension not found";
            break;
        case CFA_VAR_NO_FRAG:
            message = "Fragment not defined";
            break;
        case CFA_VAR_NO_FRAG_INDEX:
            message = "Either the frag_location or data_location not set";
            break;
        case CFA_UNKNOWN_FILE_FORMAT:
            message = "Unsupported CFA file format";
            break;
        case CFA_NOT_CFA_FILE:
            message = "Not a CFA file - does not contain relevant metadata";
            break;
        case CFA_UNSUPPORTED_VERSION:
            message = "Unsupported version of CFA-netCDF";
            break;
        case CFA_NO_FILE:
            message = "Output / Input file not created";
            break;
        case CFA_AGG_DATA_ERR:
            message = "Something went wrong parsing the aggregated_data attribute";
            break;
        case CFA_AGG_DIM_ERR:
            message = "Something went wrong parsing the aggregated_dimensions attribute";
            break;
        case CFA_AGG_NOT_DEFINED:
            message = "Aggregation Instructions have not been defined";
            break;
        case CFA_AGG_NOT_RECOGNISED:
            message = "Unrecognised Aggregation Instruction";
            break;
        default:
            message = "Unknown Exception";
    }
}

const char *CFA::Exception::what() const noexcept
{
    return message.c_str();
}