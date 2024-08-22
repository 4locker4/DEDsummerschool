///@file Tests.cpp

#include "..\inc\Tests.h"

/**
 * @brief Function for unit tests
 * \param [in] numTest          Number of the test
 * \param [in] a                Coefficient before the quadratic term
 * \param [in] b                Coefficient before the first degree term
 * \param [in] c                Free term of the equation
 * \param [in] nRootsRequired   Expected quantity of roots
 * \param [in] x1Required       Expected first root of the equation
 * \param [in] x2Required       Expected second root of the equation
 */
int UniversalTest (int numTest, double a, double b, double c,                       // Function for tests
                   int nRootsRequired, double x1Required, double x2Required)
{
    double x1 = 0;
    double x2 = 0;

    int nRoots = Dispatcher (a, b, c, &x1, &x2);

    if (DoubleComparison (nRoots, nRootsRequired) ||
        DoubleComparison (x1, x1Required) ||
        DoubleComparison (x2, x2Required))
    {
        printf ("ERROR, Test number %d/n", numTest);
        printf ("Input Data: a = %lg, b = %lg, c = %lg\n", a, b, c);
        printf ("Exprcted Data: x1 = %lg, x2 = %lg, nRoots = %lg\n", x1Required, x2Required, nRootsRequired);
        printf ("Received Data: x1 = %lg, x2 = %lg, nRoots = %lg\n\n", x1, x2, nRoots);

        return 0;
    }
    else
    {
        printf ("Nice! Test number %d is fine!\n", numTest);
        return 1;
    }
}

/**
 * @brief Function which include all data for tests
 * 
 */
void StartTests()                                                               // Test starter
{
    int rightTests = 0;
    int falseTests = 6;

    rightTests += UniversalTest (1, 1, 2, -3, 2, 1, -3);
    rightTests += UniversalTest (2, 5, 0, 0, 1, 0, 0);
    rightTests += UniversalTest (3, 0, 5, -3, 1, 0.6, 0.6);
    rightTests += UniversalTest (4, 0.25, -25, 0, 2, 0, 100);
    rightTests += UniversalTest (5, 0.1, 0.999, -0.01, 2, 0.01, -10);
    rightTests += UniversalTest (6, -1, 66, -128, 2, 2, 64);

    printf ("\nThere are/is %d right test(s).\n", rightTests);
    printf ("There are/is %d wrong test(s).\n", (falseTests - rightTests));
}