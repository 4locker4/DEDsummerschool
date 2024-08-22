///@file DoubleCompare.h

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "Solvers.h"

bool IsZero             (double val);                                               ///< Double error check
bool DoubleComparison   (double firstNum, double secondNum);                        ///< Checking equality double
void BufferCleaner ();

#endif