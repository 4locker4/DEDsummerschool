/// @file Tests.cpp

#include "..\inc\Tests.h"

/**
 * @brief Function for unit tests
 * \param [in]  testNum     Number of the test
 * \param [in]  parameters  Struct with coefficient of equation
 * \param [in]  decision    Struct with roots
 * \param [out] return      Is test right or not (true/false)
 */

int UniversalTest (int testNum, struct Coefficient parameters, struct Roots decision)
{
    my_assert (testNum >= 0);
    
    my_assert (isfinite (parameters.a));
    my_assert (isfinite (parameters.b));
    my_assert (isfinite (parameters.c));

    my_assert (decision.nRoots >= -1);    
    my_assert (isfinite (decision.x1));    
    my_assert (isfinite (decision.x2));    

    TestConst expected = {decision.nRoots, decision.x1, decision.x2};

    Dispatcher (parameters, &decision);

    if (expected.nRoots != decision.nRoots ||
        !DoubleComparison (expected.x1Required, decision.x1) ||
        !DoubleComparison (expected.x2Required, decision.x2))
    {
        RED_PRINT ("\nERROR, Test number %d\n", testNum);
        RED_PRINT ("Input Data: a = %lg, b = %lg, c = %lg\n", parameters.a, parameters.b, parameters.c);
        RED_PRINT ("Expacted Data: x1 = %lg, x2 = %lg, nRoots = %d\n", expected.x1Required, expected.x2Required, expected.nRoots);
        RED_PRINT ("Received Data: x1 = %lg, x2 = %lg, nRoots = %d\n\n", decision.x1, decision.x2, decision.nRoots);

        return 0;
    }
    else
    {
        GREEN_PRINT ("Nice! Test number %d is fine!\n", testNum);
        return 1;
    }
}

/**
 * @brief Function which include all data for tests
 */

void StartTests()                                                               // Test starter
{
    int rightTests = 0;
    int falseTests = 6;

    FILE* TestData;

    TestRes data[QUANTITY] = 
    {   // a       b       c        x1     x2  nRoots
        {{ 1,      2,     -3   }, { 0,    -3,   2}},
        {{ 5,      0,      0   }, { 0,     0,   1}},
        {{ 0,      5,     -3   }, { 0.6,   0.6, 1}},
        {{ 0.25, -25,      0   }, { 0,     100, 2}},
        {{ 0.1,    0.999, -0.01}, { 0.01, -10,  2}},
        {{-1,      66,    -128 }, { 2,     64,  2}}
    };

    for (int testNum = 0; testNum <= HOWTEST; testNum++)
    {
        rightTests += UniversalTest (testNum, data[testNum].parameters, data[testNum].decision);
    }

    GREEN_PRINT ("\n"
            "There are/is %d right test(s).\n", rightTests);
 
    RED_PRINT ("There are/is %d wrong test(s).\n", (falseTests - rightTests));
}