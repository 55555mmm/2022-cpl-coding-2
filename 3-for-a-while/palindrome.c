//
// Created by En on 2022/10/14.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LEN 21
char string[LEN] = "";

int main() {
    scanf("%20s", string);

    // add code below
    int len=0;
    while (string[len]!='\0'){
        len++;
    }

    bool is_palindrome = true;

    // add code below
    for(int i=0,j=len-1;i<j;i++,j--){
        if(string[i]!=string[j]){
            is_palindrome=false;
            break;
        }
    }


    printf("\"%s\" is %s a palindrome.\n", string,
           is_palindrome ? "" : "not");

    return 0;
}