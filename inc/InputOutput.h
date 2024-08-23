///@file InputOutput.h

#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "Solvers.h"
     
void Outputer (struct Roots decision);                                                 ///< Data output
void Inputer  (struct Coefficient* parameters) ;                                        ///< Data entry       

#endif