///@file Errors.h

#ifndef ERRORS_H
#define ERRORS_H

#include  <stdlib.h>

#include "Utils.h"

#define my_assert(expr) if (!(expr))\
                        {\
                            COLOR_PRINT(RED, "ERROR: \"" #expr "\", file %s, function %s, line %d\n", \
                                        __FILE__, __func__, __LINE__);\
                            exit (1);\
                        }

#endif // ERRORS_H