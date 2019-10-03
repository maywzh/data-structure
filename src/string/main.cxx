#include "str.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
    double x = 99;
    double *p = &x;
    *p = x;
    printf("%f", *p);
    return 1;
}