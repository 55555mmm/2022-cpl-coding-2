//
// Created by En on 2022/10/29.
//
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

bool IsPrime(int number);

int main() {
    int max = 0;
    scanf("%d", &max);

    // add code below
    int count=0;
    for(int number=2;number<=max;number++){
        if(IsPrime(number)){//decide whether is_prime is true(==1)
            count++;
            printf("%d ",number);
        }
    }
    printf("\nCount=%d\n",count);

    return 0;
}
bool IsPrime(int number){
    for(int i=2;i*i<=number;i++){
        if(number%i==0){
            return false;
        }
    }
    return true;
}