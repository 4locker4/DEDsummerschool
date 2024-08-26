/// @file main.h

#ifndef MENU_H
#define MENU_H

#include <stdio.h>

#include "Solvers.h"
#include "Tests.h"
#include "Utils.h"
#include "Errors.h"
                                                                                
const int SYMB = 1;                                                                     ///< Symbols in argv string

enum UsersChoise
{
    ERROR = -1,                                                                         ///< If user enter something  wrong
    PUT = 'p',                                                                          ///< To put Your values
    TEST = 't',                                                                         ///< To start tests
    HELP = 'h'                                                                          ///< To take help
};

void Menu          (int argc, char* argv[]);                                            ///< Choose, what User want`s to do (No parameters)
int  GetFlags      (int argc, char* str);                                               ///< argv flags
void HelpList      ();                                                                  ///< Help-list

#endif // MENU_H