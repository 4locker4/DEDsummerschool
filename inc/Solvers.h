/// @file Solvers.h

#ifndef SOLVERS_H
#define SOLVERS_H

#include <stdio.h>
#include <math.h>

#include "Utils.h"
#include "InputOutput.h"
#include "Errors.h"

struct Coefficient                                                                  ///< Coefficients
{
    double a;                                                                       ///< First coef
    double b;                                                                       ///< Secord coef
    double c;                                                                       ///< Third coef
};

struct Roots                                                                        ///< Roots
{
    double x1;                                                                      ///< First root
    double x2;                                                                      ///< Second root
    int nRoots;                                                                     ///< Number of roots
};

enum spectrum 
{
    ZERO_ROOTS,                                                                     ///< Number of equation roots: 0
    ONE_ROOT,                                                                       ///< Number of equation roots: 1
    TWO_ROOTS,                                                                      ///< Number of equation roots: 2
    SS_INFINITY_ROOTS = -1                                                          ///< Number of equation roots: 0 INFINITY
};

const double EPSILON = 1e-10;                                                       ///< Error constant double

void Dispatcher   (const struct Coefficient* parameters, struct Roots* decision);   ///< Distributor for linear and quadratic equations
void LineSolver   (const double b, const double c, struct Roots* decision);         ///< Solve linear equations
void SquareSolver (const struct Coefficient* parameters, struct Roots* decision);   ///< Solving a quadratic equation    
void RunSolver    ();                                                               ///< Start soling

#endif // SOLVERS_H
