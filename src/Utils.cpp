///@file IsZero.cpp

#include "..\inc\Utils.h"

/**
 * @brief Checks double error.
 * @param[in] val Value of the input double variable
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
    assert (isfinite (firstNum));
    assert (isfinite (secondNum));

    return IsZero (firstNum - secondNum);
}

/**
 * @brief Clean buffer
 */

void BufferCleaner ()
{
    int ch = 0;
    
    while ((ch = getchar()) != EOF || ch != '\n');
}