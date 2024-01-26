//
// Created by En on 2022/11/17.
//
#include <stdio.h>
#include <limits.h>
//有符号整数运算中发生溢出，程序的行为是未定义的。
//无符号整数运算中发生溢出，则发生回绕现象。（有定义）
int main() {
    printf("UINT_MAX = %u\n", UINT_MAX);

    unsigned int max = UINT_MAX;
    unsigned int one = 1U;
    unsigned int two = 2U;

    printf("max + one = %u\n", max + one);
    printf("one - two = %u\n", one - two);

    return 0;
}