//
// Created by En on 2022/11/11.
//
#include <stdio.h>

int Sum(int nums[], int len);

int main() {
    int numbers[] = {1, 2, 3, 4, 5};

    int sum = Sum(numbers, sizeof numbers / sizeof numbers[0]);
    //语法：sizeof:a kind of operator(运算符)后跟表达式（expression）（可不用括号）或类型（type）(要用括号括起来)
    //语义：sizeof 也可这么写：sizeof numbers / sizeof numbers[0]
    printf("sum = %d\n", sum);

    return 0;
}
int Sum(int nums[], int len){
    if(len==0){
        return 0;
    }
    int partial_sum= Sum(nums,len-1);
    return partial_sum+nums[len-1];
}




