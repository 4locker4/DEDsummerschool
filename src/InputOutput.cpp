/// @file InputOutput.cpp

#include "..\inc\InputOutput.h"

/**
 * @brief Performs data entry
 * \param [in] a Coefficient before the quadratic term
 * \param [in] b Coefficient before the first degree term
 * \param [in] c Free term of the equation
 */

void Inputer (struct Coefficient* parameters)                                        // Data entry
{
    my_assert (parameters != NULL);

    YELLOW_PRINT ("Your equation is:\na * x ^ 2 + b * x + c\n");
    YELLOW_PRINT ("Enter the coefficients of the equation.\n\n");
    YELLOW_PRINT ("A   B   C\n");

    while (scanf ("%lg %lg %lg", &parameters -> a,                                  // Check, what kind of data User input
                                 &parameters -> b,
                                 &parameters -> c) != 3)                                  
    {   
        RED_PRINT ("Oh no! You entered incorrect data.\n");
        RED_PRINT ("Please, put coefficients, not chars.\n");

        BufferCleaner();                                                            // Clean Buffer
    }
    char ch = 0;

    if ((ch = getchar()) != '/n')
    {
        YELLOW_PRINT ("\nYou entered some more symbols, that`s not good, but ok.\n\n")
    }

    return;
}

/**
 * @brief Produces output.
 * \param [in] rootsQuantity Number of roots of the equation
 * \param [in] x1            First root of the equation
 * \param [in] x2            Second root of the equation
 */

void Outputer (struct Roots decision)                                               // Data output
{
    my_assert (isfinite (decision.x1));
    my_assert (isfinite (decision.x2));

    switch (decision.nRoots)
    {
        case ZERO_ROOTS:                                                            // If there are no roots
        {
            YELLOW_PRINT ("No roots!");
            break;
        }
        case ONE_ROOT:                                                              // One root
        {
            YELLOW_PRINT ("x = %g", decision.x1);
            break;
        }
        case TWO_ROOTS:                                                             // Two roots
        {
            YELLOW_PRINT ("x1 = %lg, x2 = %lg", decision.x1, decision.x2);
            break;
        }
        case SS_INFINITY_ROOTS:                                                     // Infinite number of roots
        {
            YELLOW_PRINT ("Infinity roots.");
            break;
        }

        default:                                                                    // Something went wrong; no roots like 0/1/2/INF
        {
            RED_PRINT ("main (): ERROR, there is %d roots://", decision.nRoots);
            break;
        }
    }
}