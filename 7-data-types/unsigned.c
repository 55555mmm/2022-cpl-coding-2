//
// Created by En on 2022/11/17.
//
#include <stdio.h>

int main() {
    int array[] = {0, 1, 2, 3, 4};
    int i = -1;//未说明，默认是signed

    size_t size = sizeof array;//size_t:新类型：底层：无符号整型
    printf("The size of the array is %zu\n", size);
    //size_t:自定义的类型，不属于c语言内置的几种基本的数据类型之一。
    //size_t输出：%z  好处：直观 ;..._t:命名规范
    //typedef unsigned long long int size_t
    //typedef long clock_t

    if (i <= size) {//混用了有符号与无符号整数，i==-1（有符号）会先被转化/解读成无符号整数（回绕到最大的数）
        printf("i <= sizeof array\n");//要么确保不是负数，要么确保不要混用
    } else {//尽量少用无符号，除非明确知道自己在做什么
        printf("i > sizeof array\n");
    }

    return 0;
}