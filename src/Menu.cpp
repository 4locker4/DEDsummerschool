///@file Menu.cpp

#include "..\inc\Menu.h"

/**
 * @brief Choose, what User want`s to do (No parameters).
 */

void Menu ()
{
    printf ("Hello! I'm Your programm. Choose, what do You want:\n\n");
    printf ("[t\\p]\n\nt - Test me\np - Put Your's values\n");

    int ch1, ch2; 

    while (true)
    {   
        ch1 = getchar();
        ch2 = getchar();
        
        if (ch2 == '\n')
        {
            if (ch1 != 't' && ch1 != 'p')
            {
                printf ("Take a look closer, You entered something wrong.\n\n");  
                BufferCleaner ();
            }
            else
                break;
        }
    }

    if (ch1 == 't')
    {
        StartTests();
        
    }
    else
    {
        RunSolver();
    }
}