/// @file DoubleCompare.h

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "Solvers.h"

enum spectrum1
{
    TEST = 0,                                                                       ///< Test mode
    PUT  = 1                                                                        ///< Put mode
};


bool IsZero             (double val);                                               ///< Double error check
bool DoubleComparison   (double firstNum, double secondNum);                        ///< Checking equality double
void BufferCleaner      ();                                                         ///< Buffer cleaner

#endif

