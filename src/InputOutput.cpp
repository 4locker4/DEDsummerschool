///@file InputOutput.cpp

#include "C:\Users\eremc\.vscode\Tests\.vscode\c++\inc\InputOutput.h"

/**
 * @brief Performs data entry
 * \param [in] a Coefficient before the quadratic term
 * \param [in] b Coefficient before the first degree term
 * \param [in] c Free term of the equation
 */

void Inputer (double* a, double* b, double* c)                                       // Data entry
{
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);

    printf ("Ваше уравнение имеет вид:\na * x ^ 2 + b * x + c\n");
    printf ("Введите коэффициенты уравнения.\n\n");
    printf ("A   B   C\n");

    while (!VerifyItNum(a, b, c));
}

/**
 * @brief Produces output.
 * \param [in] rootsQuantity Number of roots of the equation
 * \param [in] x1 First root of the equation
 * \param [in] x2 Second root of the equation
 */

void Outputer (int rootsQuantity, double x1, double x2)                             // Data output
{
    assert (isfinite (x1));
    assert (isfinite (x2));

    switch (rootsQuantity)
    {
        case ZERO_ROOTS:                                                            // If there are no roots

        {
            printf ("No roots!");
            break;
        }
        case ONE_ROOT:                                                              // One root
        {
            printf ("x = %g", x1);
            break;
        }
        case TWO_ROOTS:                                                             // Two roots
        {
            printf ("x1 = %lg, x2 = %lg", x1, x2);
            break;
        }
        case SS_INFINITY_ROOTS:                                                     // Infinite number of roots
        {
            printf ("Infinity roots.");
            break;
        }

        default:                                                                    // Something went wrong; no roots like 0/1/2/INF
        {
            printf ("main (): ERROR, there is %d roots://", rootsQuantity);
            break;
        }
    }
}


