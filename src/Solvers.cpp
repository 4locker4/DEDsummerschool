#include "..\inc\Solvers.h"

void RunSolver ()
{
    Coeficient parameters {};
    Roots decision {};

    Inputer (&parameters);                                                                  // Gets equation coefficients

    Dispatcher (parameters, &decision);                                                     // We get the number of roots

    Outputer (decision);
}

/**
 * @brief Checks the linearity of the equation, sends it to the corresponding function,
 * the output is the number of roots.
 * \param [in] a  Coefficient before the quadratic term
 * \param [in] b  Coefficient before the first degree term
 * \param [in] c  Free term of the equation
 * \param [in] x1 First root of the equation
 * \param [in] x2 Second root of the equation
 */

void Dispatcher (struct Coeficient parameters, struct Roots* decision)
{
    assert (isfinite (parameters.a));
    assert (isfinite (parameters.b));
    assert (isfinite (parameters.c));

    assert (decision != NULL);

    if (IsZero(parameters.a))
        LineSolver (parameters, decision);
    else
        SquareSolver (parameters, decision);
}

/**
 * @brief Solves a linear equation and gives the output number of roots.
 * \param [in] b  Coefficient before the first degree term
 * \param [in] c  Free term of the equation
 * \param [in] x1 First root of the equation
 * \param [in] x2 Second root of the equation
 */

void LineSolver (struct Coeficient parameters, struct Roots* decision)
{
    assert (isfinite (parameters.a));
    assert (isfinite (parameters.b));

    assert (decision != NULL);

    if (IsZero (parameters.a))                                     
        if (IsZero(parameters.b))
            decision -> nRoots = SS_INFINITY_ROOTS;
        else
            decision -> nRoots = ZERO_ROOTS;
    else                                                                              
    {
        decision->x1 = decision->x2 = (-parameters.b / parameters.a);
        decision->nRoots = ONE_ROOT;
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

void SquareSolver (struct Coeficient parameters, struct Roots* decision)                                  // Returns the number of roots
{
    assert (isfinite (parameters.a));
    assert (isfinite (parameters.b));
    assert (isfinite (parameters.c));

    assert (decision != NULL);

    if (IsZero (parameters.c))                                                               // If c == 0
    {
        decision -> x1 = 0;
        decision -> x2 = (-parameters.b / parameters.a);
        decision -> nRoots = TWO_ROOTS;
        return;
    }

    double discriminant = parameters.b * parameters.b - 4 * parameters.a * parameters.c;    // Calculate the discriminant

    if (discriminant <= -EPSILON)                                                           // Testing for non-negative discriminant
        decision -> nRoots = ZERO_ROOTS;

    double sqrtDiscriminant = sqrt(discriminant);                                           // Root of the discriminant

    if (IsZero(sqrtDiscriminant))                                                           // One root
    {
        decision -> x1 = decision -> x2 = (-parameters.b / parameters.a);
        decision -> nRoots = ONE_ROOT;
    }
    else                                                                            // 2 roots, sqrt_discriminant > EPSILAN
    {
        decision -> x1 = (-parameters.b + sqrtDiscriminant) / (2 * parameters.a);                                    // First root
        decision -> x2 = (-parameters.b - sqrtDiscriminant) / (2 * parameters.a);                                    // Second root
        decision -> nRoots = TWO_ROOTS;
    }
}