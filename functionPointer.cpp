//
// Created by Jdqm on 2021/2/24.
//

#include <vector>
#include <algorithm>
using namespace std;

//定义函数指针，将函数名替换为(*p)，括号不能省
int (*gp) (int);

int *gp1(int);
int* gp2(int a); //等价于上一行

//初始化函数指针
int g(int a);
int (*cp)(int) = g;

typedef int (*Fun) (int, int);

int m(int, int);
Fun fun = m;
//Fun = m; error



int mm();
typedef int Func(); //将函数类型"int()"声明为Func

Func* pf = mm; //int()* pf;

int (*func(int))();

