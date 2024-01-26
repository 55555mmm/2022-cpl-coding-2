//
// Created by En on 2022/10/29.
//
#include <stdio.h>
#include <stdbool.h>

bool IsLeapYear(int year);

int main(){
    //year:in the main function: local variable(局部变量)
    //scope(life time):从被定义开始到所在函数结束
    int year=0;
    scanf("%d",&year);

    //year:actual argument(实参)
    bool leap= IsLeapYear(year);

    if(!leap){//即leap!=true
        printf("The year %d is a common year.\n",year);
    } else{
        printf("The year %d is a leap year.\n",year);
    }

    return 0;
}
//year:formal parameter(形式参数：形参)
//scope as a local variable(函数体内)
//In C,pass by value (传值)
bool IsLeapYear(int year){//bool:函数的返回类型
    return ((year % 4==0 && year % 100 !=0)||
            (year % 400==0));
    //遇到return语句代码即结束，后面语句不再执行
}
