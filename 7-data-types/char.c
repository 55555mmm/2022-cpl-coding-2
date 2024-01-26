//
// Created by En on 2022/11/11.
//
#include <stdio.h>

int main() {
    // (signed) char on my computer: -128 ~ 127
    // using unsigned char c = 150;
    char c = 150;//有无符号看系统
    int i = 900;

    printf("i / c = %d\n", i / c);

    return 0;
}