/// @file Headers.h

#ifndef CONSTANTS_H
#define CONSTANTS_H

enum spectrum 
{
    ZERO_ROOTS,                                                                     ///< Number of equation roots: 0
    ONE_ROOT,                                                                       ///< Number of equation roots: 1
    TWO_ROOTS,                                                                      ///< Number of equation roots: 2
    SS_INFINITY_ROOTS = -1                                                          ///< Number of equation roots: 0 INFINITY
};

const int EPSILON           = 0.1e-10;                                              ///< Error constant double


//----------------------------------------------------------------------------------------------------------------------------------------------


void Inputer (double* a, double* b, double* c);                                     ///< Data entry
int Dispatcher (double a, double b, double c, double* x1, double* x2);              ///< Distributor for linear and quadratic equations
int LineSolver(double b, double c, double* x1, double* x2);
int SquareSolver (double a, double b, double c, double* x1, double* x2);            ///< Solving a quadratic equation           
void Outputer (int nRoots, double x1, double x2);                                   ///< Data output 
bool IsZero (double val);                                                           ///< Double error check
int StartTests(int TestNum);

int UniversalTest (int numTest, double a, double b, double c,                      ///< Unit-tests
                    int nRootsRequired, double x1Required, double x2Required);
bool DoubleComparison (double firstNum, double secondNum);                          ///< Checking equality double

#endif