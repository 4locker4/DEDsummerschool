/// @file Tests.cpp

#include "..\inc\Tests.h"

/**
 * @brief Function for unit tests
 * \param [in]  testNum     Number of the test
 * \param [in]  parameters  Struct with coefficient of equation
 * \param [in]  decision    Struct with roots
 * \param [out] return      Is test right or not (true/false)
 */

int UniversalTest (const int testNum, const TestData* data)
{
    my_assert (testNum >= 0);
    
    my_assert (data != NULL);

    my_assert (isfinite (data->parameters.a));
    my_assert (isfinite (data->parameters.b));
    my_assert (isfinite (data->parameters.c));

    my_assert (data->decision.nRoots >= -1);    
    my_assert (isfinite (data->decision.x1));    
    my_assert (isfinite (data->decision.x2));    

    Roots results = {};                                                                         // Initilization

    Dispatcher (&data->parameters, &results);                                                   // Solve test                                       

    if (results.nRoots == data->decision.nRoots &&
        DoubleComparison (results.x1, data->decision.x1) &&
        DoubleComparison (results.x2, data->decision.x2))
    {
        COLOR_PRINT (GREEN, "Nice! Test number %d is fine!\n", testNum);
        return 1;   
    }
    else
    {
        COLOR_PRINT (RED, "\nERROR, Test number %d\n", testNum);
        COLOR_PRINT (RED, "Input Data:     a = %3lg,  b = %3lg, c      = %3lg\n", 
                           data->parameters.a, data->parameters.b, data->parameters.c);
        COLOR_PRINT (RED, "Expacted Data: x1 = %3lg, x2 = %3lg, nRoots = %3d\n", 
                           data->decision.x1, data->decision.x2, data->decision.nRoots);
        COLOR_PRINT (RED, "Received Data: x1 = %3lg, x2 = %3lg, nRoots = %3d\n\n", 
                           results.x1, results.x2, results.nRoots);
        return 0;
    }
}

/**
 * @brief Function which include all data for tests
 */

void StartTests()                                                                               // Test starter
{
    int rightTests = 0;
    int falseTests = 6;

    TestData data[QUANTITY] =                                                                   // Test Data
    {   // a       b       c       x1     x2  nRoots
        {{ 1,      12,     -13 }, { -13,   1,  2}},
        {{ 5,      0,      0   }, {   0,   0,  1}},
        {{ 0,      5,     -3   }, { 0.6, 0.6,  1}},
        {{ 0.25, -25,      0   }, {   0, 100,  2}},
        {{ 0.1,    0.999, -0.01}, {0.01, -10,  2}},
        {{-1,      66,    -128 }, {   2,  64,  2}}
    };

    for (int testNum = 0; testNum <= HOW_MANY_TESTS; testNum++)                                  // Run tests
    {
        rightTests += UniversalTest (testNum, &data[testNum]);
    }

    COLOR_PRINT (GREEN, "\nThere are/is %d right test(s).\n", rightTests);
    COLOR_PRINT (RED,   "There are/is %d wrong test(s).\n",  (falseTests - rightTests));
}