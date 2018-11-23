#include <stdio.h>
#include <stdlib.h>

typedef void (*FunType)(int);
//前加一个typedef关键字，这样就定义一个名为FunType函数指针类型，而不是一个FunType变量。
//形式同 typedef int* PINT;
void myFun(int x);
void hisFun(int x);
void herFun(int x);
void callFun(FunType fp, int x);
int main()
{
    callFun(myFun, 100); //传入函数指针常量，作为回调函数
    callFun(hisFun, 200);
    callFun(herFun, 300);

    return 0;
}

void callFun(FunType fp, int x)
{
    fp(x); //通过fp的指针执行传递进来的函数，注意fp所指的函数有一个参数
}

void myFun(int x)
{
    printf("myFun: %d\n", x);
}
void hisFun(int x)
{
    printf("hisFun: %d\n", x);
}
void herFun(int x)
{
    printf("herFun: %d\n", x);
}