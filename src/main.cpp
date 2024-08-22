/// @file lesson1.cpp

#include "C:\Users\eremc\.vscode\Tests\.vscode\c++\inc\main.h"

/**
 * @brief Links:  Inputer(), Dispatcher(), LineSolver(),
 *                 Outputer(), IsZero(), SquareSolver()
 */

int main ()
{
    #define START_TESTS

    StartTests();

    #ifdef START_TESTS

    double a = 0;                                                                   ///< Coefficient a
    double b = 0;                                                                   ///< Coefficient b
    double c = 0;                                                                   ///< Coefficient c

    Inputer (&a, &b, &c);                                                           // Gets equation coefficients

    double x1 = 0;                                                                  // First root
    double x2 = 0;                                                                  // Second root

    int nRoots = Dispatcher (a, b, c, &x1, &x2);                                    // We get the number of roots

    Outputer (nRoots, x1, x2);

    #endif

    return 0;
}

