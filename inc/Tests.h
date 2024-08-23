///@file Tests.h

#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "Solvers.h"
#include "Utils.h"

const int QUANTITY = 6;

struct TestRes
{
    struct Coefficient parameters;
    struct Roots decision;
};

struct TestConst
{
    int nRoots;
    double x1Required, x2Required;
};

void StartTests         ();                                                              ///< Start solving equation
int  UniversalTest      (int testNum, struct Coefficient parameters, struct Roots decision);

#endif