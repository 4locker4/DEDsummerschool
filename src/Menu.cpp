/// @file Menu.cpp

#include "..\inc\Menu.h"

/**
 * @brief Choose, what User want`s to do (No parameters).
 */

void Menu ()
{
    printf ("Hello! I'm Your programm. Choose, what do You want:\n\n");
    printf ("[t\\p]\n\nt - Test me\np - Put Your's values\n\n");

    if (TestOrPut () == TEST)                                                    // User choose Test
    {
        StartTests ();
    }
    else                                                                        // User choose Put vals
    {
        RunSolver ();
    }
}