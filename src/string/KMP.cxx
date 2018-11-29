#include "str.h"
#include <stdlib.h>
void getnext(String substr, int next[])
{
    int i = 1,
        j = 0;
    next[1] = 0;
    while (i < substr.length)
    {
        if (j == 0 || substr.ch[i] == substr.ch[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

int KMP(String str, Str substr, int next[])
{
    int i = 1, j = 1;
    while (i <= str.length && j <= substr.length)
    {
        if (j == 0 || str.ch[i] == substr.ch[j])
        {
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if (j > substr.length)
        return i - substr.length;
    else
        return 0;
}