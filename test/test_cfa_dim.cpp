#include "CFADim.hpp"
#include "CFAGroup.hpp"

#include <assert.h>

void test_cfa_dim_creation() 
{
    //CFA::Group group(0, "Test Group");
    //CFA::Dim dim(group.getId(), "Test Dim", 0);
    //assert(dim.getId() != -1);
}

void test_cfa_dim_get_id() {}
void test_cfa_dim_get_length() {}
void test_cfa_dim_get_name() {}
void test_cfa_dim_get_type() {}

int main(void)
{
    test_cfa_dim_creation();
    test_cfa_dim_get_id();
    test_cfa_dim_get_name();
    test_cfa_dim_get_type();
}