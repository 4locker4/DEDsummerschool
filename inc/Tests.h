/// @file Tests.h

#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "Solvers.h"
#include "Utils.h"

const int QUANTITY = 6;                                                                         ///< Size of array with tests
const int HOWTEST  = 5;                                                                         ///< Numbers of tests

struct TestRes
{
    struct Coefficient parameters;                                                              ///< Coefficients
    struct Roots       decision;                                                                ///< Roots      
};

struct TestConst                                                                 
{
    int    nRoots;                                                                              ///< Numbers of roots
    double x1Required, x2Required;                                                              ///< Values of roots
};

void StartTests         ();                                                                     ///< Start solving equation
int  UniversalTest      (int testNum, struct Coefficient parameters, struct Roots decision);    ///< Function for unit tests

#endif ///TESTS_H

