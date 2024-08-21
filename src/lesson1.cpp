/// @file lesson1.cpp

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "C:\Users\eremc\.vscode\Tests\.vscode\c++\inc\Headers.h"

/**
 * @brief Links:  Inputer(), Dispatcher(), LineSolver(),
 *                 Outputer(), IsZero(), SquareSolver()
 */

int main ()
{   
    #define NOT_USUAL

    StartTests(1);

    return 0;

    #ifdef USUAL
    double a = 0;                                                                   ///< Coefficient a
    double b = 0;                                                                   ///< Coefficient b
    double c = 0;                                                                   ///< Coefficient c

    Inputer (&a, &b, &c);                                                         // Gets equation coefficients

    double x1 = 0;                                                                  // First root
    double x2 = 0;                                                                  // Second root

    int nRoots = Dispatcher (a, b, c, &x1, &x2);                                    // We get the number of roots

    Outputer (nRoots, x1, x2);

    return 0;

    #endif
}

/**
 * @brief Performs data entry                                                       
 * @param [in] a Coefficient before the quadratic term                                
 * @param [in] b Coefficient before the first degree term                         
 * @param [in] c Free term of the equation                                          
 */

void Inputer (double* a, double* b, double* c)                                      // Data entry
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    printf ("Ваше уравнение имеет вид:\na * x ^ 2 + b * x + c\n");
    printf ("Введите коэффициенты уравнения.\n\n");
    printf ("A   B   C\n");
    
    scanf ("%lg %lg %lg", a, b, c);                                                 // Entering odds from the keyboard
}

/**
 * @brief Checks the linearity of the equation, sends it to the corresponding function,
 * the output is the number of roots.
 * @param [in] a  Coefficient before the quadratic term                                
 * @param [in] b  Coefficient before the first degree term                         
 * @param [in] c  Free term of the equation  
 * @param [in] x1 First root of the equation
 * @param [in] x2 Second root of the equation
 */

int Dispatcher (double a, double b, double c, double* x1, double* x2)
{
    assert(isfinite (a));
    assert(isfinite (b));
    assert(isfinite (c));

    assert(x1 != x2);
    assert(x1 != NULL);
    assert(x2 != NULL);

    if (IsZero(a))
        return LineSolver (b, c, x1, x2);
    else
        return SquareSolver (a, b, c, x1, x2);
}

/**
 * @brief Solves a linear equation and gives the output number of roots.                              
 * @param [in] b  Coefficient before the first degree term                         
 * @param [in] c  Free term of the equation  
 * @param [in] x1 First root of the equation
 * @param [in] x2 Second root of the equation
 */

int LineSolver (double b, double c, double* x1, double* x2)
{
    assert(isfinite (b));
    assert(isfinite (c));

    assert(x1 != x2);
    assert(x1 != NULL);
    assert(x2 != NULL);

    if (IsZero(b))                                                                   // If b == 0       
        return (IsZero(c))? SS_INFINITY_ROOTS : ZERO_ROOTS;
    else                                                                             // If b != 0
    {   
        *x1 = *x2 = (-c / b);
        return ONE_ROOT;
    }
}

 /**
 * @brief Solves a quadratic equation and gives the output number of roots.
 * @param [in] a  Coefficient before the quadratic term                                
 * @param [in] b  Coefficient before the first degree term                         
 * @param [in] c  Free term of the equation  
 * @param [in] x1 First root of the equation
 * @param [in] x2 Second root of the equation
 */

int SquareSolver (double a, double b, double c, double* x1, double* x2)             // Returns the number of roots
{
    assert(isfinite (a));
    assert(isfinite (b));
    assert(isfinite (c));

    assert(x1 != x2);
    assert(x1 != NULL);
    assert(x2 != NULL);

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

/**
 * @brief Produces output.
 * @param [in] rootsQuantity Number of roots of the equation
 * @param [in] x1 First root of the equation
 * @param [in] x2 Second root of the equation
 */

void Outputer (int rootsQuantity, double x1, double x2)                             // Data output
{   
    assert(isfinite (x1));
    assert(isfinite (x2));

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

/**
 * @brief Checks double error.
 * @param [in] val Value of the input double variable
 */

bool IsZero (double val)                                                            // Checking double for errors
{
    assert (isfinite (val));           

    if (EPSILON >= fabs (val))
        return true;
    return false;
}

int UniversalTest (int numTest, double a, double b, double c, int nRootsRequired, double x1Required, double x2Required)
{
    double x1 = 0;
    double x2 = 0;

    int nRoots = Dispatcher(a, b, c, &x1, &x2);

    if (DoubleComparison(nRoots, nRootsRequired) || DoubleComparison(x1, x1Required) || DoubleComparison(x2, x2Required))
    {   
        printf ("ERROR, Test №%d/n", numTest);
        printf("Input Data: a = %lg, b = %lg, c = %lg\n", a, b, c);
        printf("Exprcted Data: x1 = %lg, x2 = %lg, nRoots = %lg\n", x1Required, x2Required, nRootsRequired);
        printf("Received Data: x1 = %lg, x2 = %lg, nRoots = %lg\n", x1, x2, nRoots);

        return 0;
    }

    else
    {
        printf ("Nice! Test №%d is fine!", numTest);
        return 1;
    }

        
}

int StartTests(int TestNum)
{
    int rightTests = 0;
    int falseTests = 0;

    rightTests += UniversalTest (1, 1, 2, -3, 2, 1, -3);
    rightTests += UniversalTest (2, 5, 0, 0, 1, 0, 0);
    rightTests += UniversalTest (3, 0.1, 0.999, -0.01, 2, -0.01, 10);

    printf ("Правильных тестов: %d", rightTests);
    
    return 0;
}

bool DoubleComparison (double firstNum, double secondNum)
{
    if ((firstNum - EPSILON) <= secondNum <= (firstNum + EPSILON))
        return false;
    return true;
}