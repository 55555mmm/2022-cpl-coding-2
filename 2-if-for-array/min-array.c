//
// Created by En on 2022/10/9.
//
#include <stdio.h>
#define NUM 5
int main(){
    int number[NUM]={0};
    for(int i=0;i<NUM;i++){
        scanf("%d",&number[i]);
    }
    int min =number[0];
    //[]:subscript operator(下标运算符）
    //i++: ++i
    //int i=1   since C99
    for(int i=1;i<NUM;i++){
        if(number[i]<min){
            min=number[i];
        }
    }
    printf("min=%d\n",min);


    return 0;
}