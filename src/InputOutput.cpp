/// @file InputOutput.cpp

#include "..\inc\InputOutput.h"

/**
 * @brief Performs data entry
 * \param [in] a Coefficient before the quadratic term
 * \param [in] b Coefficient before the first degree term
 * \param [in] c Free term of the equation
 */

void Inputer (struct Coefficient* parameters)                                       // Data entry
{
    my_assert (parameters != NULL);

    COLOR_PRINT (YELLOW, "Your equation is:\na * x ^ 2 + b * x + c\n");
    COLOR_PRINT (YELLOW, "Enter the coefficients of the equation.\n\n");
    COLOR_PRINT (YELLOW, "A   B   C\n");

    while (scanf ("%lg %lg %lg", &parameters -> a,                                  // Check, what kind of data User input
                                 &parameters -> b,
                                 &parameters -> c) != 3)                                  
    {   
        COLOR_PRINT (RED, "Oh no! You entered incorrect data.\n");
        COLOR_PRINT (RED, "Please, put coefficients, not chars.\n");

        BufferCleaner();                                                            // Clean Buffer
    }
    
    int ch = 0;

    if ((ch = SkipSpaces()) != '\n' && ch != EOF)                                   // Сhecks characters after entered values
    {
        COLOR_PRINT (YELLOW, "\nYou entered some more symbols, that`s not good, but ok.\n\n");
        BufferCleaner();
    }

    return;
}

/**
 * @brief Produces output.
 * \param [in] rootsQuantity Number of roots of the equation
 * \param [in] x1            First root of the equation
 * \param [in] x2            Second root of the equation
 */

void Outputer (const struct Roots* decision)                                        // Data output
{   
    my_assert (decision != NULL);

    my_assert (isfinite (decision->x1));
    my_assert (isfinite (decision->x2));

    switch (decision->nRoots)
    {
        case ZERO_ROOTS:                                                            // If there are no roots
        {
            COLOR_PRINT (RED, "No roots!");
            break;
        }
        case ONE_ROOT:                                                              // One root
        {
            COLOR_PRINT (YELLOW, "x = %g", decision->x1);
            break;
        }
        case TWO_ROOTS:                                                             // Two roots
        {
            COLOR_PRINT (GREEN, "x1 = %lg, x2 = %lg", decision->x1, decision->x2);
            break;
        }
        case SS_INFINITY_ROOTS:                                                     // Infinite number of roots
        {
            COLOR_PRINT (RED, "Infinity roots.");
            break;
        }

        default:                                                                    // Something went wrong; no roots like 0/1/2/INF
        {
            COLOR_PRINT (RED, "main (): ERROR, there is %d roots://", decision->nRoots);
            break;
        }
    }
}