///@file Menu.cpp

#include "..\inc\Menu.h"

void Menu ()
{
    printf ("Hello! I'm Your programm. Choose, what do You want:\n\n");
    printf ("[t\\p]\n\nt - Test me\np - Put Your's values\n");

    char ch1, ch2;

    while (((ch1 = getchar()) != 't' || ch1 != 'p') || ((ch2 = getchar()) != '\n' || ch2 != EOF))
    { 
        printf("Take a look closer, You entered something wrong.\n\n");  
        BufferCleaner ();
    }

    if (ch1 == 't')
    {
        //StartTests();
        ;
    }
    else
    {
        RunSolver();
    }
}