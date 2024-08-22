#include "C:\Users\eremc\.vscode\Tests\.vscode\c++\inc\Solvers.h"

/**
 * @brief Checks the linearity of the equation, sends it to the corresponding function,
 * the output is the number of roots.
 * \param [in] a  Coefficient before the quadratic term
 * \param [in] b  Coefficient before the first degree term
 * \param [in] c  Free term of the equation
 * \param [in] x1 First root of the equation
 * \param [in] x2 Second root of the equation
 */

int Dispatcher (double a, double b, double c, double* x1, double* x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != x2);
    assert (x1 != NULL);
    assert (x2 != NULL);

    if (IsZero(a))
        return LineSolver (b, c, x1, x2);
    else
        return SquareSolver (a, b, c, x1, x2);
}

/**
 * @brief Solves a linear equation and gives the output number of roots.
 * \param [in] b  Coefficient before the first degree term
 * \param [in] c  Free term of the equation
 * \param [in] x1 First root of the equation
 * \param [in] x2 Second root of the equation
 */

int LineSolver (double p, double q, double* x1, double* x2)
{
    assert (isfinite (p));
    assert (isfinite (q));

    assert (x1 != x2);
    assert (x1 != NULL);
    assert (x2 != NULL);

    if (IsZero (p))                                                                   // If b == 0
        return (IsZero(q))? SS_INFINITY_ROOTS : ZERO_ROOTS;
    else                                                                              // If b != 0
    {
        *x1 = *x2 = (-q / p);
        return ONE_ROOT;
    }
}

 /**
 * @brief Solves a quadratic equation and gives the output number of roots.
 * \param [in] a  Coefficient before the quadratic term
 * \param [in] b  Coefficient before the first degree term
 * \param [in] c  Free term of the equation
 * \param [in] x1 First root of the equation
 * \param [in] x2 Second root of the equation
 */

int SquareSolver (double a, double b, double c, double* x1, double* x2)             // Returns the number of roots
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != x2);
    assert (x1 != NULL);
    assert (x2 != NULL);

    if (IsZero(c))                                                                  // If c == 0
    {
        *x1 = 0;
        *x2 = (-b / a);
        return TWO_ROOTS;
    }

    double discriminant = b * b - 4 * a * c;                                        // Calculate the discriminant

    if (discriminant <= 0)                                                          // Testing for non-negative discriminant
        return ZERO_ROOTS;

    double sqrtDiscriminant = sqrt(discriminant);                                   // Root of the discriminant

    if (IsZero(sqrtDiscriminant))                                                   // One root
    {
        *x1 = *x2 = -b / (2 * a);
        return ONE_ROOT;
    }
    else                                                                            // 2 roots, sqrt_discriminant > EPSILAN
    {
        *x1 = (-b + sqrtDiscriminant) / (2 * a);                                    // First root
        *x2 = (-b - sqrtDiscriminant) / (2 * a);                                    // Second root
        return TWO_ROOTS;
    }
}