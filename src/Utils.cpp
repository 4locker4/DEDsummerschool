/// @file Utils.cpp

#include "..\inc\Utils.h"

/**
 * @brief Checks double error.
 * \param [in]  val    Value of the input double variable
 * \param [out] return Return is this doouble == 0
 */

bool IsZero (const double val)                                                            // Checking double for errors
{
    my_assert (isfinite (val));

    if (EPSILON >= fabs (val))
    {
        return true;
    }
    return false;
}

/**
 * @brief Compearing two double nums
 * \param [in]  firstNum   First double num
 * \param [in]  secondNum  Second double num
 * \param [out] true/false Is this true or false
 */

bool DoubleComparison (const double firstNum, const double secondNum)               // Compare two double
{
    my_assert (isfinite (firstNum));
    my_assert (isfinite (secondNum));

    return IsZero (firstNum - secondNum);
}

/**
 * @brief Clean buffer
 */

void BufferCleaner ()                                                               // Clean Buffer
{   
    int ch = 0;

    while ((ch = getchar ()) != '\n' && ch != EOF) {}
}

/**
 * @brief Function, which skips spaces after User`s text and returns first not-space char
 * \param [out] lastChar Returns false (not \\n or EOF) or True (if \\n or EOF)
 */

bool SkipSpaces ()
{
    int isSpace = 0;

    while ((isSpace = getchar ()) == ' ' || isSpace == '\t') {}
    
    if (isSpace == '\n' || isSpace == EOF)
    {
        return true;
    }
    return false;
}

// Дальше идет незаконченый код
/*void FileOpener (int argc, char * argv[])
{
    if (argc != 2)                                                                                // Проверяем, ввел ли пользователь флаг на чтение файла
    {  
        printf ("Please enter the name of the test data file.\n");  
        exit (EXIT_FAILURE);  
    }  
  
    FILE* fileWithTests = fopen (argv[1], "r");                                                   // Открываем файл, который ввел пользователь
  
    if (fileWithTests == NULL)                                                                    // Проверяем, открылся ли файл
    {  
        printf ("Error. Can`t open file: %s\n", argv[1]);  
        exit (EXIT_FAILURE);  
    }  
  
    if (fseek (fileWithTests, 0, SEEK_END) == -1)                                                 // Устанавливаем каретку в конец
    {  
        printf ("Something went wrong, we are out of file.\nPlease, try again.\n");  
        exit (EXIT_FAILURE);  
    }  
    if (fseek (fileWithTests, 0, SEEK_SET) == -1)                                                 // Устанавливаем каретку в начало (возможно не понадобится)
    {  
        printf ("Something went wrong, we are out of file.\nPlease, try again.\n");  
        exit (EXIT_FAILURE);  
    }  
      
    const int fileSize = ftell (fileWithTests);                                                   // Считываем количество символов типа char в файле
  
    char * fileFirstElement = (char *) calloc (fileSize, sizeof (char));                          // Выделяем динамическую память под будущую строку, считанную из файла
                                                                                                  // возвращает адрес первого элемента
  
    size_t howManyElementsPut = fread (fileFirstElement, sizeof (char), fileSize , fileWithTests);// Выдает длину записанной в динамическую память строки, она должна совпадать с 
                                                                                                  // длинной динамической памяти
                                                                                                  // На этой стадии в динамическую память записаны все символы из файла, теперь наша 
                                                                                                  // задача выудить их оттуда порциями по 3, закинуть в структуры и передать в функцию
    if (fclose (fileWithTests) == EOF)  
    {  
        printf ("Error while closing file");  
    }  
}

int StrCounter (int * fileFirstElement, int fileSize)                                             // Count quantity of tests
{
        int counterNextStr = 0;

    for (int i = 0; i < fileSize; i ++)
    {
        if (*(fileFirstElement + i) == '\n')
        {
            ++counterNextStr;
        }
    }
    return counterNextStr;
}

void TestArrayReturner (int fileSize, char * fileFirstElement)                                    // Put values into array of struct (test data array)
{
    char * addr = 0;

    int strQuantity = StrCounter ((int*) fileFirstElement, fileSize);

    if (strQuantity == 0)
    {
        printf ("There is no tests in Your file.\n");
        return;
    }
    
    double * forArray = (double*) calloc (strQuantity, sizeof (double) * 5 + sizeof (unsigned long));

    // for (int i = 0; i < fileSize; i += 6){}
}  */
