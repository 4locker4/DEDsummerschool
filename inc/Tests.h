///@file Tests.h

#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "Solvers.h"
#include "Utils.h"

void StartTests         (void);
int  UniversalTest      (int numTest, double a, double b, double c,                      ///< Unit-tests
                         int nRootsRequired, double x1Required, double x2Required);

#endif