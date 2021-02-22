//
// Created by 杨胜 on 2021/2/22.
//
#include <iostream>
#include "pointer.h"
using namespace std;

void pointerTest() {

    //指正定义，*号可书写的位置可居左，居右，居中
    int *p;
    char *cp;
    float *fp;
    double *dp;

    //指针赋值
    int *ip;
    int iCount = 18;
    ip = &iCount;
    int *iPtr = &iCount;

    //字面值不能进行&操作
    //ip = &23

    //指针间接操作实体
    cout << "ip指正所指向的实体：" << *ip << endl;
    cout << "ip指正所指向的实体的内存地址：" << ip << endl;
    cout << "iCount的内存地址：" << &iCount << endl;

    //指针的指针，二级指针
    int **p2;
    p2 = &ip;
    cout << "ip针的地址：" << &ip << endl;
    cout << "p2的内容：" << p2 << endl;
    cout << "p2所指向的指针的内容：" << *p2 << endl;
    cout << "p2所指向的实体：" << **p2 << endl;

    //指针类型
    float f = 43.5;
    int *intPtr = reinterpret_cast<int *>(&f);
    cout << "float address: " << "&f=>" << &f << endl;
    cout << "intPtr address: " << "intPtr=>" << *intPtr << endl;
    *intPtr = 100;
    cout << "int:" << *intPtr << endl;
    cout << "float:" << f << endl;

    //几种转换
    //静态转换：static_cast
    //动态转换：dynamic_cast
    //重解释转换：reinterpret_cast
    //写开禁：const_cast

    //指针运算
    int iArray[6];
    for (int i = 0; i < 6; i++) {
        iArray[i] = i * 2;
    }
    for (int* iP = iArray; iP < iArray + 6; iP +=1)
    {
        cout<<*iP<<endl;
    }

    //指针限定
    const int a = 78;
    int b = 10;
    int c = 18;

    //1、指针常量，指针所指向地址不可变，p不能重新赋值
    int* const constP = &b; //指针常量
    int const* constP0 = &b;//等价于上一条
    *constP = 20; //ok
    //constP = &c; 错，不能重新赋值

    //2、常量指针，指针所指向的实体不能变，即*p不能重新赋值
    const int* cip = &a;
    cip = &b; //ok
    //*cip = 10; //error

    const int* const icp = &c;
    //icp = &b; //error
    //*icp = 20; //error
}

void referenceTest() {
    int int1 = 5;
    int& rint = int1;
    cout<<"&int1: "<<&int1<<" int1: "<<int1<<endl;
    cout<<"&rint: "<<&rint<<" rint: "<<rint<<endl;
    int int2 = 8;
    rint = int2;
    //rint关联了int2后，它的值改变了，但是其地址还是不变
    cout<<"&int1: "<<&int1<<" int1: "<<int1<<endl;
    cout<<"&rint: "<<&rint<<" rint1: "<<rint<<endl;

    //rint 初始化后，它所指向的地址就固定了，无法改变。后续修改都是修改此地址的实体

    //引用限定
    const int& cint = int1;
    //cint = 10; //error
    int1 = 8; // ok
}