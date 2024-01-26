//
// Created by En on 2022/10/29.
//
#include <stdio.h>

void Print(char ch,int count);
//void:不需要返回值，表示空；没有。

int main() {
    int lines;
    scanf("%d", &lines);

    // add code below
    for (int i = 0; i < lines; i++) {
        Print(' ',lines-1-i);
        Print('*',2*i+1);
        if(i<lines-1) {
            printf("\n");
        }
    }
    return 0;
}
void Print(char ch,int count){
    for(int i=0;i<count;i++){
        printf("%c",ch);
    }
}