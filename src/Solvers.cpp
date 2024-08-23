#include "..\inc\Solvers.h"

void RunSolver ()
{
    Coefficient parameters {};
    Roots decision {};

    Inputer (&parameters);                                                                  // Gets equation coefficients

    Dispatcher (parameters, &decision);                                                     // Solve the equation

    Outputer (decision);                                                                    // Output results
}

/**
 * @brief Checks the linearity of the equation, sends it to the corresponding function,
 * the output is the number of roots.
 * \param [in] a  Coefficient before the quadratic term
 * \param [in] 
 */

void Dispatcher (struct Coefficient parameters, struct Roots* decision)
{
    assert (isfinite (parameters.a));
    assert (isfinite (parameters.b));
    assert (isfinite (parameters.c));

    assert (decision != NULL);

    if (IsZero (parameters.a))
        LineSolver (parameters.b, parameters.c, decision);
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

void LineSolver (double b, double c, struct Roots* decision)
{
    assert (isfinite (b));
    assert (isfinite (c));

    assert (decision != NULL);

    if (IsZero (b)) 
    {                                    
        if (IsZero(c))
        {
            decision -> nRoots = SS_INFINITY_ROOTS;
        }
        else
        {
            decision -> nRoots = ZERO_ROOTS;
        }

        return;
    }
    else                                                                              
    {
        decision -> x1 = decision -> x2 = (-c / b);
        decision -> nRoots = ONE_ROOT;
        return;
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

void SquareSolver (struct Coefficient parameters, struct Roots* decision)                    // Returns the number of roots
{
    assert (isfinite (parameters.a));
    assert (isfinite (parameters.b));
    assert (isfinite (parameters.c));

    assert (decision != NULL);

    if (IsZero (parameters.c))                                                               // If c == 0
    {
        decision -> x1 = 0;
        decision -> x2 = (parameters.b / -parameters.a);
       
        decision -> nRoots = TWO_ROOTS;
        
        return;
    }

    double discriminant = parameters.b * parameters.b - 4 * parameters.a * parameters.c;    // Calculate the discriminant
    if (discriminant <= -EPSILON)                                                           // Testing for non-negative discriminant
    {
        printf ("1\n");
        decision -> nRoots = ZERO_ROOTS;
        return;
    }

    double sqrtDiscriminant = sqrt(discriminant);                                           // Root of the discriminant
    if (IsZero(sqrtDiscriminant))                                                           // One root
    {
        decision -> x1 = decision -> x2 = (-parameters.b / parameters.a);
        decision -> nRoots = ONE_ROOT;
        return;
    }
    else                                                                                    // 2 roots, sqrt_discriminant > EPSILAN
    {
        decision -> x1 = (-parameters.b + sqrtDiscriminant) / (2 * parameters.a);           // First root
        decision -> x2 = (-parameters.b - sqrtDiscriminant) / (2 * parameters.a);           // Second root
        decision -> nRoots = TWO_ROOTS;
        return;
    }
}