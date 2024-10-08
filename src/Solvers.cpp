///@file Solvers.cpp

#include "..\inc\Solvers.h"

/**
 * @brief Run Square Solver
 */

void RunSolver ()
{
    Coefficient parameters {};
    Roots decision {};

    Inputer (&parameters);                                                                   // Gets equation coefficients

    Dispatcher (&parameters, &decision);                                                     // Solve the equation

    Outputer (&decision);                                                                    // Output results
}

/**
 * @brief Checks the linearity of the equation, sends it to the corresponding function,
 * the output is the number of roots.
 * \param [in] parameters  Struct with coefficient of equation
 * \param [in] decision    Struct with roots
 */

void Dispatcher (const struct Coefficient* parameters, struct Roots* decision)
{
    my_assert (parameters != NULL);
    my_assert (decision   != NULL);
    
    my_assert (isfinite (parameters->a));
    my_assert (isfinite (parameters->b));
    my_assert (isfinite (parameters->c));


    if (IsZero (parameters->a))
    {
        LineSolver (parameters->b, parameters->c, decision);
    }
    else
    {
        SquareSolver (parameters, decision);
    }
}

/**
 * @brief Solves a linear equation and gives the output number of roots.
 * \param [in] b         Coefficient before the first degree term
 * \param [in] c         Free term of the equation
 * \param [in] decision  Struct with roots
 */

void LineSolver (const double b, const double c, struct Roots* decision)
{
    my_assert (decision != NULL);

    my_assert (isfinite (b));
    my_assert (isfinite (c));

    if (IsZero (b))
    {                                    
        if (IsZero (c))
        {
            decision->nRoots = SS_INFINITY_ROOTS;
        }
        else
        {
            decision->nRoots = ZERO_ROOTS;
        }
        return;
    }
    else                                                                              
    {
        if (IsZero (-c / b))                                                                    // If x1 = x2 = 0    
        {
            decision->x1 = decision->x2 = 0;
            decision->nRoots = ONE_ROOT;
        }
        else                                                                                    // If the equation is linear
        {
            decision->x1 = decision->x2 = (-c / b);
            decision->nRoots = ONE_ROOT;
        }
        return;
    }
}

 /**
 * @brief Solves a quadratic equation and gives the output number of roots.
 * \param [in] parameters Struct with coefficient before the quadratic term
 * \param [in] decision   Struct with roots of quadratic term
 */

void SquareSolver (const struct Coefficient* parameters, struct Roots* decision)                // Returns the number of roots
{
    my_assert (parameters != NULL);
    my_assert (decision   != NULL);

    my_assert (isfinite (parameters->a));
    my_assert (isfinite (parameters->b));
    my_assert (isfinite (parameters->c));

    if (IsZero (parameters->c))                                                                 // If c == 0
    {
        if (IsZero (parameters->b))
        {
            decision->x1 = decision->x2 = 0;
            decision->nRoots = ONE_ROOT;
            return;
        }

        decision->x1 = 0;
        decision->x2 = (-parameters->b / parameters->a);
       
        decision->nRoots = TWO_ROOTS;
        
        return;
    }

    double discriminant = parameters->b * parameters->b - 4 * parameters->a * parameters->c;    // Calculate the discriminant
    if (discriminant <= -EPSILON)                                                               // Testing for non-negative discriminant
    {
        decision->nRoots = ZERO_ROOTS;
        return;
    }

    double sqrtDiscriminant = sqrt (discriminant);                                              // Root of the discriminant
    if (IsZero (sqrtDiscriminant))                                                              // One root
    {
        decision->x1 = decision->x2 = -parameters->b / (2 * parameters->a);
        decision->nRoots = ONE_ROOT;
        return;
    }
    else                                                                                        // 2 roots, sqrt_discriminant > EPSILAN
    {
        decision->x1 = (-parameters->b + sqrtDiscriminant) / (2 * parameters->a);               // First root
        decision->x2 = (-parameters->b - sqrtDiscriminant) / (2 * parameters->a);               // Second root
        decision->nRoots = TWO_ROOTS;
        return;
    }
}