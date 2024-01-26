#include <stdio.h>

//
// Created by En on 2022/10/9.
//
int main(){
    int a=0;
    int b=0;
    scanf("%d%d",&a,&b);
    int min=0;
    /*if(a>=b){
        min=b;
    }else{
        min=a;
    }*/
    min = a>=b ? b:a;

    printf("min(%d,%d)=%d\n",a,b,min);
    return 0;
}