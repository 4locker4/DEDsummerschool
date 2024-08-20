#include <stdio.h>
#include <math.h>

const int SS_INFINITY_ROOTS = -1;                                               // Константа для обозначения бесконечного количества корней

int SquareSolver(double a, double b, double c, double* x1, double* x2);

int main()
{
    printf("Ваше уравнение имеет вид:\na * x ^ 2 + b * x + c\n");
    printf("Введите коэффициенты уравнения.\n\n");
    printf("A   B   C\n");

    double a = 0;                                                               // Коэффициент a
    double b = 0;                                                               // Коэффициент b
    double c = 0;                                                               // Коэффициент c

    scanf("%lg %lg %lg", &a, &b, &c);

    double x1 = 0;                                                              // Первый корень
    double x2 = 0;                                                              // Второй корень
    int nRoots = SquareSolver(a, b, c, &x1, &x2);                               // Получаем количество корней

    switch(nRoots)
    {
        case 0:                                                                 // Если нет корней
        {
            printf("No roots!");                                                
            break;
        }
        case 1:                                                                 // Один корень
        {
            printf("x = %g", x1);                                               
            break;
        }
        case 2:                                                                 // Два корня
        {
            printf("x1 = %g, x2 = %g", x1, x2);                                 
            break;
        }
        case SS_INFINITY_ROOTS:                                                 // Бесконечное число корней 
        {
            printf("Infinity roots.");                                          
            break;
        }

        default:                                                                // Что-то пошло не так; корней не 0/1/2/БЕСК
        {
            printf("main(): ERROR, there is %d roots://", nRoots);              
            break;
        }
    }

    return 0;
}

int SquareSolver(double a, double b, double c, double* x1, double* x2)          // Возвращает количество корней
{
    
    if (a == 0)
    {
        if (b == 0) return (c == 0)? SS_INFINITY_ROOTS : 0;                     // Если b == 0, то идет выбор: БЕСК или 0 число корней

        else return (c == 0)? 0 : (-c / b); // b != 0                           // Если b != 0, то идет выбор: 1 или 0 число корней
    }


    double discriminant = b * b - 4 * a * c;                                    // Вычисляем дискриминант 
    if (discriminant < 0) return 0;                                             // Проверка на неотрицательный дискриминант 

    double sqrtDiscriminant = sqrt(discriminant);                               // Корень из дискриминанта
    if (sqrtDiscriminant == 0)                                                  // Один корень
    {
        *x1 = *x2 = (-b + sqrtDiscriminant) / 2 / a;                            // Вычисляем х1 = х2
        return 1;
    }
    else                                                                        // 2 корня, sqrt_discriminant > 0
    {
        *x1 = (-b + sqrtDiscriminant) / 2 / a;                                  // Первый корень
        *x2 = (-b - sqrtDiscriminant) / 2 / a;                                  // Второй корень
        return 2;
    }
}