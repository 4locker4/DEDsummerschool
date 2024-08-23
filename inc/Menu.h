///@file main.h

#ifndef MENU_H
#define MENU_H

#include <stdio.h>

#include "Solvers.h"
#include "InputOutput.h"
#include "Tests.h"

const int LEN = 3;

void Menu ();
void RunSolver ();
void StartTests();
void BufferCleaner ();

#endif // MENU_H