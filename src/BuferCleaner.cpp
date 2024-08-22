#include "C:\Users\eremc\.vscode\Tests\.vscode\c++\inc\BuferCleaner.h"

void BuferCleaner (void)
{
    int i;
    
    while (i = getchar(), i != EOF || i != '\n');
}