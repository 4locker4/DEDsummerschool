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

/**
 * @brief Compearing two double nums
 * \param [in] firstNum  First double num
 * \param [in] secondNum Second double num
 */

bool DoubleComparison (double firstNum, double secondNum)                           // Compare two double
{
    assert (isfinite (firstNum));
    assert (isfinite (secondNum));

    return IsZero (firstNum - secondNum);
}

/**
 * @brief Clean buffer
 */

void BufferCleaner ()                                                               // Clean Buffer
{   
    char ch;
    while (true)
    {
        ch = getchar();
        
        if (ch == '\n' || ch == EOF)
            break;
    }
}