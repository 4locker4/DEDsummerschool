///@file InputOutput.cpp

#include "..\inc\InputOutput.h"

/**
 * @brief Performs data entry
 * \param [in] a Coefficient before the quadratic term
 * \param [in] b Coefficient before the first degree term
 * \param [in] c Free term of the equation
 */

void Inputer (struct Coefficient* parameters)                                        // Data entry
{
    assert (parameters != NULL);

    printf ("Your equation is:\na * x ^ 2 + b * x + c\n");
    printf ("Enter the coefficients of the equation.\n\n");
    printf ("A   B   C\n");

    while (scanf ("%lg %lg %lg", &parameters -> a, &parameters -> b, &parameters -> c) != 3)                                  // Check, what kind of data User input
    {
        printf ("Oh no! You entered incorrect data.\n");
        printf ("Please, put coefficients, not chars.\n");

        BufferCleaner();                                                            // Clean Buffer
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
    assert (isfinite (decision.x1));
    assert (isfinite (decision.x2));

    switch (decision.nRoots)
    {
        case ZERO_ROOTS:                                                            // If there are no roots
        {
            printf ("No roots!");
            break;
        }
        case ONE_ROOT:                                                              // One root
        {
            printf ("x = %g", decision.x1);
            break;
        }
        case TWO_ROOTS:                                                             // Two roots
        {
            printf ("x1 = %lg, x2 = %lg", decision.x1, decision.x2);
            break;
        }
        case SS_INFINITY_ROOTS:                                                     // Infinite number of roots
        {
            printf ("Infinity roots.");
            break;
        }

        default:                                                                    // Something went wrong; no roots like 0/1/2/INF
        {
            printf ("main (): ERROR, there is %d roots://", decision.nRoots);
            break;
        }
    }
}