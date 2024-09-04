/// @file Tests.cpp

#include "..\inc\Tests.h"

/**
 * @brief Function for unit tests
 * \param [in]  testNum     Number of the test
 * \param [in]  parameters  Struct with coefficient of equation
 * \param [in]  decision    Struct with roots
 * \param [out] return      Is test right or not (true/false)
 */

int UniversalTest (const int testNum, struct TestData arrayOfInd)
{
    my_assert (testNum >= 0);

    my_assert (isfinite (arrayOfInd.parameters.a));
    my_assert (isfinite (arrayOfInd.parameters.b));
    my_assert (isfinite (arrayOfInd.parameters.c));

    my_assert (arrayOfInd.decision.nRoots >= -1);    
    my_assert (isfinite (arrayOfInd.decision.x1));    
    my_assert (isfinite (arrayOfInd.decision.x2));    

    Roots results = {};                                                                         // Initilization

    Dispatcher (&arrayOfInd.parameters, &results);                                                   // Solve test                                       

    if (results.nRoots == arrayOfInd.decision.nRoots &&
        DoubleComparison (results.x1, arrayOfInd.decision.x1) &&
        DoubleComparison (results.x2, arrayOfInd.decision.x2))
    {
        COLOR_PRINT (GREEN, "Nice! Test number %d is fine!\n", testNum);
        return 1;   
    }
    else
    {
        COLOR_PRINT (RED, "\nERROR, Test number %d\n", testNum);
        COLOR_PRINT (RED, "Input Data:     a = %3lg,  b = %3lg, c      = %3lg\n", 
                           arrayOfInd.parameters.a, arrayOfInd.parameters.b, arrayOfInd.parameters.c);
        COLOR_PRINT (RED, "Expacted Data: x1 = %3lg, x2 = %3lg, nRoots = %3d\n", 
                           arrayOfInd.decision.x1, arrayOfInd.decision.x2, arrayOfInd.decision.nRoots);
        COLOR_PRINT (RED, "Received Data: x1 = %3lg, x2 = %3lg, nRoots = %3d\n\n", 
                           results.x1, results.x2, results.nRoots);
        return 0;
    }
}

/**
 * @brief Function which include all data for tests
 */

void StartTests(int argc, const char argv[])                                                                               // Test starter
{
    int rightTests = 0;
    int falseTests = 6;

    char * strAddres = FileOpeners (argc, argv[2]);                                      // Возвращает адрес, который указывает на что?

    TestData * arrayOfInd = FillingTheArray (strAddres);

    for (int testNum = 0; testNum <= HOW_MANY_TESTS; testNum++)                                  // Run tests
    {
        rightTests += UniversalTest (testNum, arrayOfInd[testNum]);
    }

    COLOR_PRINT (GREEN, "\nThere are/is %d right test(s).\n", rightTests);
    COLOR_PRINT (RED,   "There are/is %d wrong test(s).\n",  (falseTests - rightTests));
}

char * FileOpeners (int argc, char fileName)                                                // Нужен ассерт 
{  
    FILE* fileWithTests = FileNameReader (argc, &fileName);
    my_assert (fseek (fileWithTests, 0, SEEK_END) == -1);

    const int fileSize = ftell (fileWithTests);                                                   // Считываем количество символов типа char в файле
  
    my_assert (fseek (fileWithTests, 0, SEEK_SET) == -1);
   
    char * fileAddres = (char *) calloc (fileSize + 1, sizeof (char));                            // Выделяем динамическую память под будущую строку, считанную из файла
                                                                                                  // возвращает адрес первого элемента

    size_t howManyElementsPut = fread (fileAddres, sizeof (char), fileSize, fileWithTests);       // Выдает длину записанной в динамическую память строки, она должна совпадать с 
                                                                                                  // длинной динамической памяти
                                                                                                  // На этой стадии в динамическую память записаны все символы из файла, теперь наша 
                                                                                                  // задача выудить их оттуда порциями по 3, закинуть в структуры и передать в функцию
    my_assert (howManyElementsPut != fileSize);                                                   // Возможно надо +1 т.к. \0
    my_assert (fclose (fileWithTests) != 0);
    *(fileAddres + fileSize) = '\0';
    return fileAddres;
    // Нужно вернуть адрес первого элемента. Количество символов не требуется, у нас в конце \0
}

TestData * FillingTheArray (char * fileFirstElement)
{
    int strLen = StrCounter ((int*) fileFirstElement);

    my_assert (strLen == 0);

    struct TestData * pointerToStructs = (TestData *) calloc (strLen, sizeof (TestData));

    for (int counter = 0; counter < strLen; counter++)
    {   
        sscanf (fileFirstElement, "%lg %lg %lg %lg %lg %d", 
        &pointerToStructs[counter].parameters.a, &pointerToStructs[counter].parameters.b,
        &pointerToStructs[counter].parameters.c, &pointerToStructs[counter].decision.x1,
        &pointerToStructs[counter].decision.x2,  &pointerToStructs[counter].decision.nRoots);
    }
    free (fileFirstElement);
    return pointerToStructs;
}

FILE* FileNameReader (int argc, char argv[])
{
    my_assert (argc != 3);
    
    FILE* fileWithTests = fopen (&argv[2],  "r");                                                   // Открываем файл, который ввел пользователь
    
    my_assert (fileWithTests != NULL);

    return fileWithTests;
  
}
