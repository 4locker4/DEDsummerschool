/// @file DoubleCompare.h

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <math.h>
#include <string.h>

#include "Solvers.h"
#include "Errors.h"

#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"

#define COLOR_PRINT(color, ...) printf (color); printf(__VA_ARGS__); printf(RESET);

bool IsZero             (const double val);                                         ///< Double error check
bool DoubleComparison   (const double firstNum, const double secondNum);            ///< Checking equality double
void BufferCleaner      ();                                                         ///< Buffer cleaner
int  SkipSpaces         ();                                                         ///< Skip spaces and tabs after User`s text, returns first char

#endif

