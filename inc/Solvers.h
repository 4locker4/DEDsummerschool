///@file Solvers.h

#ifndef SOLVERS_H
#define SOLVERS_H

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "Utils.h"
#include "InputOutput.h"

struct Coeficient                                                                   // Coefficients
{
    double a = 0;
    double b = 0; 
    double c = 0;
};

struct Roots                                                                        // Roots
{
    double x1 = 0;
    double x2 = 0;
    int nRoots = 0;
};

enum spectrum 
{
    ZERO_ROOTS,                                                                     ///< Number of equation roots: 0
    ONE_ROOT,                                                                       ///< Number of equation roots: 1
    TWO_ROOTS,                                                                      ///< Number of equation roots: 2
    SS_INFINITY_ROOTS = -1                                                          ///< Number of equation roots: 0 INFINITY
};

const int EPSILON           = 0.1e-10;                                              ///< Error constant double

void Dispatcher   (struct Coeficient parameters, Roots* docision);                         ///< Distributor for linear and quadratic equations
void LineSolver   (struct Coeficient parameters, Roots* dicision);                         ///< Solve linear equations
void SquareSolver (struct Coeficient parameters, Roots* docision);                         ///< Solving a quadratic equation    
void RunSolver    ();                                                               ///< Start soling

#endif // SOLVERS_H