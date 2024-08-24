/// @file main.h

#ifndef MENU_H
#define MENU_H

#include <stdio.h>

#include "Solvers.h"
#include "InputOutput.h"
#include "Tests.h"
#include "Utils.h"

void Menu      ();                                                                   ///< Choose, what User want`s to do (No parameters)
void RunSolver ();                                                                   ///< Run Square Solver
void StarTests ();                                                                   ///< Start Tests
int  TestOrPut ();                                                                   ///< User choose

#endif // MENU_H