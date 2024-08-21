/// @file lesson1.cpp

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include ".vscode\constants.h"                  // ./obj/header.h
                                                // ./src/code.cpp

/**
 * \brief Основная функция main().
 * 
 * \details Ссылки: Inputer(), Dispatcher(), LineSolver(),
 *                  Outputer(), IsZero(), SquareSolver()
 */

int main ()
{
    double a = 0;                                                                   //*< Коэффициент a
    double b = 0;                                                                   //*< Коэффициент b
    double c = 0;                                                                   //*< Коэффициент c

    Inputer (&a, &b, &c);                                                           //*< Получает коэффициенты уравнения

    double x1 = 0;                                                                  //*< Первый корень
    double x2 = 0;                                                                  //*< Второй корень
    int nRoots = Dispatcher (a, b, c, &x1, &x2);                                    //*< Получаем количество корней

    Outputer (nRoots, x1, x2);

    return 0;
}

/**
 * @brief Производит ввод данных                                                          
 * @param [in] a Коэффициент перед квадратным членом                                
 * @param [in] b Коэффициент перед членом первой степени                            
 * @param [in] c Свободный член уравнения                                           
 */

void Inputer (double* a, double* b, double* c)                                      // Ввод данных
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    printf ("Ваше уравнение имеет вид:\na * x ^ 2 + b * x + c\n");
    printf ("Введите коэффициенты уравнения.\n\n");
    printf ("A   B   C\n");
    
    scanf ("%lg %lg %lg", a, b, c);                                                 // Ввод коэффициентов с клавиатуры
}

/**
 * @brief Проверяет линейность уравнения, отправляет на выполнение соответствующей функции,
 * на выход дает количество корней.
 * @param [in] a  Коэффициент перед квадратным членом                                
 * @param [in] b  Коэффициент перед членом первой степени                            
 * @param [in] c  Свободный член уравнения
 * @param [in] x1 Первый корень уравнения
 * @param [in] x2 Второй корень уравнения
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
 * @brief Решает линейное уравнение, на выход дает количество корней.                              
 * @param [in] b  Коэффициент перед членом первой степени                            
 * @param [in] c  Свободный член уравнения
 * @param [in] x1 Первый корень уравнения
 * @param [in] x2 Второй корень уравнения
 */

int LineSolver (double b, double c, double* x1, double* x2)
{
    assert(isfinite (b));
    assert(isfinite (c));

    assert(x1 != x2);
    assert(x1 != NULL);
    assert(x2 != NULL);

    if (IsZero(b))                                                                   // Если b == 0       
        return (IsZero(c))? SS_INFINITY_ROOTS : ZERO_ROOTS;
    else                                                                             //Если b != 0
    {   
        *x1 = *x2 = (-c / b);
        return ONE_ROOT;
    }
}

 /**
 * @brief Решает квадратное уравнение, на выход дает количество корней.
 * @param [in] a  Коэффициент перед квадратным членом                                
 * @param [in] b  Коэффициент перед членом первой степени                            
 * @param [in] c  Свободный член уравнения
 * @param [in] x1 Первый корень уравнения
 * @param [in] x2 Второй корень уравнения
 */

int SquareSolver (double a, double b, double c, double* x1, double* x2)             // Возвращает количество корней
{
    assert(isfinite (a));
    assert(isfinite (b));
    assert(isfinite (c));

    assert(x1 != x2);
    assert(x1 != NULL);
    assert(x2 != NULL);

    double discriminant = b * b - 4 * a * c;                                        // Вычисляем дискриминант 

    if (discriminant <= 0)                                                          // Проверка на неотрицательный дискриминант
        return ZERO_ROOTS;                                           

    double sqrtDiscriminant = sqrt(discriminant);                                   // Корень из дискриминанта

    if (IsZero(sqrtDiscriminant))                                                   // Один корень
    {
        *x1 = *x2 = -b / (2 * a);                            
        return ONE_ROOT;
    }
    else                                                                            // 2 корня, sqrt_discriminant > EPSILAN
    {
        *x1 = (-b + sqrtDiscriminant) / (2 * a);                                    // Первый корень
        *x2 = (-b - sqrtDiscriminant) / (2 * a);                                    // Второй корень
        return TWO_ROOTS;
    }
}

/**
 * @brief Производит вывод.
 * @param [in] rootsQuantity Количество корней уравнения
 * @param [out] x1            Первый корень уравнения
 * @param [out] x2            Второй корень уравнения
 */

void Outputer (int rootsQuantity, double x1, double x2)                             // Вывод данных
{   
    assert(isfinite (x1));
    assert(isfinite (x2));

    switch (rootsQuantity)
    {
        case ZERO_ROOTS:                                                            // Если нет корней
        {
            printf ("No roots!");                                                
            break;
        }
        case ONE_ROOT:                                                              // Один корень
        {
            printf ("x = %g", x1);                                               
            break;
        }
        case TWO_ROOTS:                                                             // Два корня
        {
            printf ("x1 = %lg, x2 = %lg", x1, x2);                                 
            break;
        }
        case SS_INFINITY_ROOTS:                                                     // Бесконечное число корней 
        {
            printf ("Infinity roots.");                                          
            break;
        }

        default:                                                                    // Что-то пошло не так; корней не 0/1/2/БЕСК
        {
            printf ("main (): ERROR, there is %d roots://", rootsQuantity);              
            break;
        }
    }
}

/**
 * @brief Проверяет double погрешность.
 * @param [in] val Значение входной double переменной
 */

bool IsZero (double val)                                                            // Проверка double на погрешность
{
    assert (isfinite (val));           

    if (EPSILON >= fabs (val))
        return true;
    return false;
}
// TODO рефактор кода
// TODO докси закончить
// TODO enum прочитать 
// TODO тесты