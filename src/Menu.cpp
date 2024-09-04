/// @file Menu.cpp

#include "..\inc\Menu.h"

/**
 * @brief Choose, what User want`s to do.
 * \param [in] argc Quantity of flags
 * \param [in] argv User1s flags
 */

void Menu (const int argc, const char* argv[])
{
    my_assert (argv != NULL);
    my_assert (argc >= 1);

    if (argc == 1)
    {
        RunSolver();
    }
    else
    {
        switch (GetFlags (argc, argv[1]))
        {
            case TEST: 
            {
                StartTests (argc, *argv);
                break;
            }
            case PUT:
            {
                RunSolver ();
                break;
            }
            case HELP:
            {
                HelpList ();
                break;
            }
            case ERROR:
            {
                COLOR_PRINT (RED, "Please, enter only one flag.\n");
                break;
            }

            default:
            {
                COLOR_PRINT (RED, "You entered something wrong. Be careful.");
                break;
            }
        }
    }
}

/**
 * @brief Function, which return flags
 * \param [in]  argc  Quantity of argv
 * \param [in]  str   Second string from argv
 * \param [out] const What flag User entered
 */

int GetFlags (const int argc, const char* str)
{
    my_assert (str != NULL);
    my_assert (argc > 0);

    int lenStr = strlen (str); 

    if (argc > 2)
    {
        return ERROR;
    }

    if (lenStr == 2 && str[0] == '-')
    {   
        return str[SYMB];
    }
    else
    {
        if (strcmp (str, "--test") == 0)
        {
            return TEST;
        }
        else if (strcmp (str, "--help") == 0)
        {
            return HELP;
        }
        else if (strcmp (str, "--put") == 0)
        {
            return PUT;
        }
        else
        {
            return ERROR;
        }
    }
}

/**
 * @brief User assistance function
 */

void HelpList ()
{
    printf ("\nThis program solve`s quadratic equations.\nFor more infomation watch README.md\n\n");
    printf ("--test (-t) - For  test program\n\n");
    printf ("--put (-p) - For put Your values\n\n");
    printf ("--help (-h) - For help-list\n\n");
}