/// @file IsZero.cpp

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
    int ch = 0;

    while ((ch == getchar ()) != '\n' && ch != EOF){}
}

/**
 * @brief Return what user want: test or put vals
 */

int TestOrPut ()
{
    int ch1 = 0;
    int ch2 = 0;

    while (true)
    {   
        ch1 = getchar ();
        ch2 = getchar ();
        
        if (ch1 == 't' && ch2 == '\n')
        {
            return TEST;
        }
        else if (ch1 == 'p' && ch2 == '\n')
        {
            return PUT;
        }
        else
        {   
            if (ch1 != '\n' && ch2 != '\n')
            {
                BufferCleaner();
                printf ("Watch out! You input wrong data. Shut up and read Kernighan and Ritchie!!!\n");
            }
        }
    }
}