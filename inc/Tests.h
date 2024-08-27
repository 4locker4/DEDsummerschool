/// @file Tests.h

#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Solvers.h"
#include "Utils.h"
#include "Errors.h"

const int QUANTITY = 6;                                                                                 ///< Size of array with tests
const int HOWTEST  = 5;                                                                                 ///< Numbers of tests

struct TestData
{
    struct Coefficient parameters;                                                                      ///< Coefficients
    struct Roots       decision;                                                                        ///< Roots      
};

void StartTests         ();                                                                             ///< Start solving equation
int  UniversalTest      (const int testNum, const struct TestData* data);      ///< Function for unit tests

#endif ///TESTS_H

