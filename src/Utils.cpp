///@file IsZero.cpp

#include "C:\Users\eremc\.vscode\Tests\.vscode\c++\inc\Utils.h"

/**
 * @brief Checks double error.
 * \param [in] val Value of the input double variable
 */

bool IsZero (double val)                                                            // Checking double for errors
{
    assert (isfinite (val));

    if (EPSILON >= fabs (val))
        return true;
    return false;
}

bool DoubleComparison (double firstNum, double secondNum)                           // Compare two double
{
    if (fabs(firstNum - secondNum) >= EPSILON)
        return false;
    return true;
}

bool VerifyItNum (double* a, double* b, double* c)
{
    int rightData = scanf ("%lg %lg %lg", a, b, c);

    if (rightData == 3)
        return true;
    printf ("Oh no! You entered incorrect data.\n");
    printf ("Please, put coefficients, not chars.");

    
    return false;
}