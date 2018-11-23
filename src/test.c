#include <stdio.h>
int ptrtest1()
{
    int array[20] = {0};
    int *ptr = array;
    for (int i = 0; i < 20; i++)
    {
        (*ptr)++;
        ptr++;
    }
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}
int ptrtest2()
{
    char a[20] = " You_are_a_girl";
    char *p = a;
    char **ptr = &p;
    //printf("p=%d\n",p);
    //printf("ptr=%d\n",ptr);
    //printf("*ptr=%d\n",*ptr);
    printf("**ptr=%c\n", **ptr);
    ptr++;
    //printf("ptr=%d\n",ptr);
    //printf("*ptr=%d\n",*ptr);
    printf("**ptr=%c\n", **ptr);
}

int ptrtest3()
{
    int a, b;
    int array[10];
    int *pa;
    pa = &a;         //&a 是一个指针表达式。
    int **ptr = &pa; //&pa 也是一个指针表达式。
    *ptr = &b;       //*ptr 和&b 都是指针表达式。
    pa = array;
    pa++; //这也是指针表达式。
    char *arr[20];
    char **parr = arr; //如果把arr 看作指针的话，arr 也是指针表达式
    char *str;
    str = *parr;       //*parr 是指针表达式
    str = *(parr + 1); //*(parr+1)是指针表达式
    str = *(parr + 2); //*(parr+2)是指针表达式
}
int ptrtest4()
{
    char *str[3] = {
        "Hello,thisisasample!",
        "Hi,goodmorning.",
        "Helloworld"};
    char s[80];
    strcpy(s, str[0]); //也可写成strcpy(s,*str);
    strcpy(s, str[1]); //也可写成strcpy(s,*(str+1));
    strcpy(s, str[2]); //也可写成strcpy(s,*(str+2));
    printf("%s", str[0]);
    printf("%s", str[1]);
    printf("%s", str[2]);
}
int ptrtest5()
{
    int array[10];
    int(*ptr)[10];
    ptr = &array;
}
//TODO: function ptr
int funptrtest()
{
    int fun1(char *, int);
    int (*pfun1)(char *, int);
    pfun1 = &fun1;
}
int main(void)
{
    funptrtest();
}