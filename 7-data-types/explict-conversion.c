//
// Created by En on 2022/11/11.
//
#include <stdio.h>
#include <limits.h>

int main() {
    double pi = 3.14159;

    // below: obtain its fractional part
    double fraction = pi - (int) pi;

    int num = 1000000000;
    printf("LLONG_MAX = %lld\n", LLONG_MAX);
    // long long llint = num * num;
    // long long llint = (long long) num * num;//(不溢出)
    long long llint = (long long) (num * num);//乘法依然在int范围里，已溢出（溢出）

    printf("llint = %lld\n", llint);

    return 0;
}