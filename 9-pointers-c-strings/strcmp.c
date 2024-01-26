//
// Created by En on 2022/12/7.
//

//1、在c语言当中，字符串就是字符数组（特殊在于这个字符数组一定要以\0结尾）
//2、C String Arrays(C字符串数组)，实际上还是一个数组，每一个元素都是一个C语言的字符串。
#include <stdio.h>

int StrCmp(const char *s1, const char *s2);
int StrCmpStd(const char *s1, const char *s2);

int StrNCmpStd(const char *s1, const char *s2, int n);

int main() {
    const char *str1 = "hi, C";
    const char *str2 = "hi, c";

    printf("StrCmp(\"%s\", \"%s\") = %d\n",
           str1, str2, StrCmp(str1, str2));
    // printf("StrCmpStd(\"%s\", \"%s\") = %d\n",
    //        str1, str2, StrCmpStd(str1, str2));
    //
    // int n = 2;
    // printf("StrNCmp(\"%s\", \"%s\", %d) = %d\n",
    //        str1, str2, n, StrNCmp(str1, str2, n));

    return 0;
}

int StrCmp(const char *s1, const char *s2) {
    while (*s1 == *s2 && (*s1 != '\0' && *s2 != '\0')) {
        s1++;
        s2++;
    }

    if (*s1 == '\0' && *s2 == '\0') {
        return 0;
    }

    // char: unsigned char, signed char
    //若是return *s1 - *s2 ,若是unsigned char，当*s1<*s2时，两个相减会溢出，且产生回绕现象
    //虽然返回的是int类型，可能不会出现问题,但仍有风险。
    return (*(const unsigned char *) s1)
           < (*(const unsigned char *) s2) ? -1 : 1;
}

int StrCmpStd(const char *s1, const char *s2) {
    for (; *s1 == *s2; s1++, s2++) {
        if (*s1 == '\0') {
            return 0;
        }
    }

    return (*(const unsigned char *) s1)
           < (*(const unsigned char *) s2) ? -1 : 1;
}

int StrNCmpStd(const char *s1, const char *s2, int n) {
    for (; 0 < n; n--, s1++, s2++) {
        if (*s1 != *s2) {
            return (*(const unsigned char *) s1)
                   < (*(const unsigned char *) s2) ? -1 : 1;
        } else if (*s1 == '\0') { // *s1 == *s2 == '\0'
            return 0;
        }
    }

    return 0;
}