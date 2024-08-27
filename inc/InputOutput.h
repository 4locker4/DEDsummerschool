/// @file InputOutput.h

#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include "Errors.h"
#include "Solvers.h"
     
void Outputer (const struct Roots* decision);                                                 ///< Data output
void Inputer  (struct Coefficient* parameters) ;                                              ///< Data entry       

#endif