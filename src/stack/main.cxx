#include <stdlib.h>
#include <stdio.h>
#include "sqstack.h"
//例3-1
int match(char *exp, int n)
{
    char stack[100];
    int top = -1;
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == '(')
        {
            stack[++top] = '(';
            printf("push( ");
        }
        if (exp[i] == ')')
        {
            if (top < 0)
                return 0;
            else
            {
                printf("pop) ");
                --top;
            }
        }
    }
    return top == -1 ? 1 : 0;
}
int op(int a, char Op, int b)
{
    if (Op == '+')
        return a + b;
    else if (Op == '-')
        return a - b;
    else if (Op == 'x')
        return a * b;
    else if (Op == '/')
        return b != 0 ? a / b : 0;
    else
        return 0;
}

int com(char *exp)
{
    int i, a, b, c;
    int stack[MAXSIZE], top = -1;
    char Op;
    for (i = 0; exp[i] != '\0'; ++i)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
            stack[++top] = exp[i] - '0';
        else
        {
            Op = exp[i];
            a = stack[top--];
            b = stack[top--];
            c = op(a, Op, b);
            stack[++top] = c;
        }
    }
    return stack[top];
}
int main()
{
    char exp[] = "((()))())";
    int a = match(exp, 13);
    printf("%d", a);
}