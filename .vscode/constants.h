#ifndef CONSTANTS_H
#define CONSTANTS_H

const int EPSILON           = 0.1e-10;                                              // Погрешность double
const int SS_INFINITY_ROOTS = -1;                                                   // Константа для обозначения бесконечного количества корней                                                        // Константа для обозначения одн
const int ZERO_ROOTS        = 0;                                                    // Константа для обозначения 0 корней
const int ONE_ROOT          = 1;                                                    // Константа для обозначения 1 корня
const int TWO_ROOTS         = 2;                                                    // Константа для обозначения 2 корней

//----------------------------------------------------------------------------------------------------------------------------------------------


void Inputer (double* a, double* b, double* c);                                     // Ввод данных
int Dispatcher (double a, double b, double c, double* x1, double* x2); 
int LineSolver(double b, double c, double* x1, double* x2);
int SquareSolver (double a, double b, double c, double* x1, double* x2);            // Решение квадратного уравнения            
void Outputer (int nRoots, double x1, double x2);                                   // Вывод данных 
bool IsZero (double val);                                                           // Проверка double погрешности

#endif