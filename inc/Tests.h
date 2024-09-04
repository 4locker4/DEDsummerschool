/// @file Tests.h

#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>

#include "Solvers.h"
#include "Utils.h"
#include "Errors.h"

const int QUANTITY        = 6;                                                                          ///< Size of array with tests
const int HOW_MANY_TESTS  = 5;                                                                          ///< Numbers of tests

struct TestData
{
    struct Coefficient parameters;                                                                      ///< Coefficients
    struct Roots       decision;                                                                        ///< Roots      
};

void StartTests      (int argc, const char argv[]);                                                     ///< Start solving equation
int  UniversalTest   (const int testNum, struct TestData arrayOfInd);                                 ///< Function for unit tests
char * FileOpeners     (int argc, char argv[]);
TestData * FillingTheArray (char * fileFirstElement);
FILE* FileNameReader (int argc, char argv[]);

#endif ///TESTS_H

