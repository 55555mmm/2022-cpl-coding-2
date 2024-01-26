#include <stdio.h>

//
// Created by En on 2022/10/9.
//
int main(){
    int a;
    int b;
    int c;
    scanf("%d%d%d",&a,&b,&c);
    int min;
    if (a>b){
        if(b>=c){
            min=c;
        } else{
            min=b;
        }
    }else{//a<=b
        if(a>=c){
            min=c;
        } else{
            min=a;
        }
    }
    printf("min(%d,%d,%d)=%d",a,b,c,min);
    return 0;
}