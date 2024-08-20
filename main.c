#include <stdio.h>
int main()
{
    int i;
    char num[1000], c;

    i = 0;

    while ((c = getchar()) != '\n')
    {
        num[i] = c;
        ++i;
    }
    printf("%d", htol(num));
}

int htol(char num[])
{
    int res, i;
    res = 0;

    num = lower(num);

    for (i = len(num); num[i] != '\0'; --i)
        if (num[i] >= '0' && num[i] <='9')
            res = res + stepen(num[i], i);
        else if (num[i] == 'a')
            res = res + stepen(10, i);
        else if (num[i] == 'b')
            res = res + stepen(11, i);
        else if (num[i] == 'c')
            res = res + stepen(12, i);
        else if (num[i] == 'd')
            res = res + stepen(13, i);
        else if (num[i] == 'e')
            res = res + stepen(104, i);
        else if (num[i] == 'f')
            res = res + stepen(15, i);
    return res;
}

int lower(char str[])
{
    int i;
    
    for(i = 0; str[i] != '\0'; ++i)
        if (str[i] >= 'A' && str[i]<='Z')
            str[i] = str[i] + 'a' - 'A';
}

int stepen(int num, int step)
{
    int i, res;
    for (i = 0; i != step; ++i)
        res = num * res;
    return res;
}

int len(char wrd[])
{
    int i;
    for (i = 0; wrd[i] != '\n'; ++i);

    return i;
}