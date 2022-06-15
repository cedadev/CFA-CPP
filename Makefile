# Makefile for CFA-CPP library and examples

# Input / output directories
SRC_DIR=src
CFA_SRC_DIR=../CFA-C/src
CFA_LIB_DIR=../CFA-C/lib
BLD_DIR=build
BLD_EX_DIR=$(BLD_DIR)/examples
TST_OUT_DIR=examples
TST_EX_OUT_DIR=$(TST_OUT_DIR)/test
TST_SRC_DIR=test
LIB_DIR=lib

# CFA-CPP sources
CFA_CPP_SRC=$(SRC_DIR)/*.cpp
CFA_CPP_LIB=libcfacpp.so

# precompiled CFA_LIB
CFA_LIB=libcfa.so

# CPP flags (-g for breakpoint debugging)
CC = g++
CFLAGS=-I$(SRC_DIR) -I$(CFA_SRC_DIR)
DEBUGFLAGS=-O0 -D_DEBUG -Wall -Wextra -g

# Linker flags for shared library
SFLAGS=-L$(CFA_LIB_DIR) -shared -fPIC -lnetcdf -lcfa

# Linker flags for everthing else
LFLAGS=-L$(LIB_DIR) -L$(CFA_LIB_DIR) -lcfa -lcfacpp -lnetcdf -lstdc++

# make everything (just the library at the moment.  Will have the tests and
# the examples eventually)
all: $(CFA_CPP_LIB)

# Make the output directories
$(LIB_DIR):
	mkdir $(LIB_DIR)

$(BLD_DIR):
	mkdir $(BLD_DIR)

$(BLD_EX_DIR): $(BLD_DIR)
	mkdir $(BLD_EX_DIR)

$(TST_OUT_DIR):
	mkdir $(TST_OUT_DIR)

$(TST_EX_OUT_DIR): $(TST_OUT_DIR)
	mkdir $(TST_EX_OUT_DIR)

$(CFA_CPP_LIB) : $(CFA_CPP_SRC) $(LIB_DIR)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(SFLAGS) -lstdc++ $< -o $(LIB_DIR)/$@

example% : $(TST_SRC_DIR)/examples/example%.cpp $(CFA_CPP_LIB) $(BLD_EX_DIR) $(TST_EX_OUT_DIR)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(LFLAGS) $< -o $(BLD_DIR)/examples/$@

clean:
	rm -r $(LIB_DIR)/*
	rm -r $(BLD_DIR)/*
	rm -r $(TST_OUT_DIR)/*