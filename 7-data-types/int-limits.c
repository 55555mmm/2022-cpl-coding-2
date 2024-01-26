//
// Created by En on 2022/11/17.
//
// file: limits.h

#include <stdio.h>
#include <limits.h>

int main() {
    printf("INT_MIN = %d\n", INT_MIN);
    printf("INT_MAX = %d\n\n", INT_MAX);

    printf("UINT_MIN = %u\n", 0U);//确定无符号加后缀U
    printf("UINT_MAX = %u\n\n", UINT_MAX);//int型输出为%d,无符号为%u

    printf("LONG_MIN = %ld\n", LONG_MIN);//长整型要加l
    printf("LONG_MAX = %ld\n\n", LONG_MAX);

    printf("ULONG_MIN = %lu\n", 0UL);//确定无符号且要在长整型下做运算，加后缀UL
    printf("ULONG_MAX = %lu\n\n", ULONG_MAX);

    // long long int: >= 64 bits
    printf("LLONG_MIN = %lld\n", LLONG_MIN);//longlong:ll
    printf("LLONG_MAX = %lld\n\n", LLONG_MAX);

    printf("ULONG_LONG_MIN = %llu\n", 0ULL);//同上理
    printf("ULONG_LONG_MAX = %llu\n\n", ULONG_LONG_MAX);

    return 0;
}