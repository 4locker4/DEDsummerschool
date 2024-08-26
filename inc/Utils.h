/// @file DoubleCompare.h

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>

#include "Solvers.h"

#define RESET   "\x1b[0m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"

#define RED_PRINT(...)\
    printf (RED);\
    printf (__VA_ARGS__);\
    printf (RESET)

#define GREEN_PRINT(...)\
    printf (GREEN);\
    printf (__VA_ARGS__);\
    printf (RESET)

#define YELLOW_PRINT(...)\
    printf (YELLOW);\
    printf (__VA_ARGS__);\
    printf (RESET);

bool IsZero             (double val);                                               ///< Double error check
bool DoubleComparison   (double firstNum, double secondNum);                        ///< Checking equality double
void BufferCleaner      ();                                                         ///< Buffer cleaner

#endif

