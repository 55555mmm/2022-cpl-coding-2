//
// Created by En on 2022/10/29.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LEN 21
char string[LEN] = "";

bool IsPalindrome(const char str[]);
//c语言中的字符串：以'\0'结束的字符数组
//字符串与其他普通数组的最大区别
//若能确定传进来的数组为字符串，可把'int len'去掉
//原因：字符串长度可计算
int main() {
    scanf("%20s", string);

    printf("\"%s\" is %s a palindrome.\n", string,
           IsPalindrome(string) ? "" : "not");

    return 0;
}
bool IsPalindrome(const char str[]){
//    int len = 0;
//    while (str[len] != '\0') {
//        len++;
//    }
    int len=strlen(str);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}