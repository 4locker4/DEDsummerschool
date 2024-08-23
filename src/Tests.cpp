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
int UniversalTest (int testNum, struct Coefficient parameters, struct Roots decision)
{
    TestConst expected = {decision.nRoots, decision.x1, decision.x2};

    Dispatcher (parameters, &decision);

    if (expected.nRoots != decision.nRoots ||
        !DoubleComparison (expected.x1Required, decision.x1) ||
        !DoubleComparison (expected.x2Required, decision.x2))
    {
        printf ("ERROR, Test number %d/n", testNum);
        printf ("Input Data: a = %lg, b = %lg, c = %lg\n", parameters.a, parameters.b, parameters.c);
        printf ("Exprcted Data: x1 = %lg, x2 = %lg, nRoots = %d\n", expected.x1Required, expected.x2Required, expected.nRoots);
        printf ("Received Data: x1 = %lg, x2 = %lg, nRoots = %ldn\n", decision.x1, decision.x2, decision.nRoots);

        return 0;
    }
    else
    {
        printf ("Nice! Test number %d is fine!\n", testNum);
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

    TestRes data[QUANTITY]
    {
        {{1, 2, -3}, {-3, 1, 2}},
        {{5, 0, 0}, {0, 0, 1}},
        {{0, 5, -3}, {0.6, 0.6, 1}},
        {{0.25, -25, 0}, {100, 0, 2}},
        {{0.1, 0.999, -0.01}, {-10, 0.01, 2}},
        {{-1, 66, -128}, {64, 2, 2}}
    };

    for (int testNum = 0; testNum <= QUANTITY; testNum++)
    {
        UniversalTest (testNum, data[testNum].parameters, data[testNum].decision);
    }

    printf ("\nThere are/is %d right test(s).\n", rightTests);
    printf ("There are/is %d wrong test(s).\n", (falseTests - rightTests));
}