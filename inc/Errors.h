///@file Errors.h

#ifndef ERRORS_H
#define ERRORS_H

#include "Utils.h"

#define my_assert(expr) if (!(expr))\
                        {\
                            RED_PRINT ("ERROR: \"" #expr "\", file %s, function %s, line %d\n", \
                                       __FILE__, __func__, __LINE__);\
                            abort();\
                        }

#endif // ERRORS_H