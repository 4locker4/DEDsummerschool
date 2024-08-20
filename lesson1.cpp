#include <stdio.h>
#include <math.h>

const int EPSILON           = 0.1e-10;                                               // Погрешность double
const int SS_INFINITY_ROOTS = -1;                                                    // Константа для обозначения бесконечного количества корней                                                        // Константа для обозначения одн
const int ZERO_ROOTS        = 0;                                                     // Константа для обозначения 0 корней
const int ONE_ROOT          = 1;                                                     // Константа для обозначения 1 корня
const int TWO_ROOTS         = 2;                                                     // Константа для обозначения 2 корней

void Inputer(double* a, double* b, double* c);
int SquareSolver(double a, double b, double c, double* x1, double* x2);                                      
void Outputer(int nRoots, double x1, double x2);
bool IsZero(double val);         

int main()
{
    double a = 0;                                                                   // Коэффициент a
    double b = 0;                                                                   // Коэффициент b
    double c = 0;                                                                   // Коэффициент c

    Inputer(&a, &b, &c);                                                            // Получает коэффициенты уравнения

    double x1 = 0;                                                                  // Первый корень
    double x2 = 0;                                                                  // Второй корень
    int nRoots = SquareSolver (a, b, c, &x2, &x2);                                   // Получаем количество корней

    Outputer(nRoots, x1, x2);

    return 0;
}

void Inputer (double* a, double* b, double* c)                                       // Ввод данных
{
    printf("Ваше уравнение имеет вид:\na * x ^ 2 + b * x + c\n");
    printf("Введите коэффициенты уравнения.\n\n");
    printf("A   B   C\n");
    
    scanf("%lg %lg %lg", a, b, c);                                                  // Ввод коэффициентов с клавиатуры
}

int SquareSolver(double a, double b, double c, double* x1, double* x2)              // Возвращает количество корней
{
    if (IsZero(a))
    {
        if (IsZero(b)) 
            {
                if (IsZero(c))                                                      // Все коэффициенты 0
                    return SS_INFINITY_ROOTS;
                else
                    return ZERO_ROOTS;                                              // Коэффициет с != 0
            }                                                     
        else                                                                        // Коэффициент b != 0
        {
            *x1 = *x2 = (-c / b);
            return ONE_ROOT;                                                        // Линейное уравнение
        }                     
    }

    double discriminant = b * b - 4 * a * c;                                        // Вычисляем дискриминант 

    if (discriminant < EPSILON)                                                     // Проверка на неотрицательный дискриминант
        return 0;                                           

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

void Outputer(int rootsQuantity, double x1, double x2)                              // Вывод данных
{
    switch(rootsQuantity)
    {
        case ZERO_ROOTS:                                                            // Если нет корней
        {
            printf("No roots!");                                                
            break;
        }
        case ONE_ROOT:                                                              // Один корень
        {
            printf("x = %g", x1);                                               
            break;
        }
        case TWO_ROOTS:                                                             // Два корня
        {
            printf("x1 = %g, x2 = %g", x1, x2);                                 
            break;
        }
        case SS_INFINITY_ROOTS:                                                     // Бесконечное число корней 
        {
            printf("Infinity roots. And I'm Groot.");                                          
            break;
        }

        default:                                                                    // Что-то пошло не так; корней не 0/1/2/БЕСК
        {
            printf("main(): ERROR, there is %d roots://", rootsQuantity);              
            break;
        }
    }
}

bool IsZero(double val)                                                             // Проверка double на погрешность
{
    if (EPSILON >= fabs(val))
        return true;
    return false;
}

