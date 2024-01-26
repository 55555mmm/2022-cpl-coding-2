//
// Created by En on 2022/11/11.
//
// Visualization of function call: https://pythontutor.com/visualize.html#code=%23include%20%3Cstdio.h%3E%0A%0Aint%20Min%28int%20a,%20int%20b%29%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20int%20a%20%3D%2025%3B%0A%20%20int%20b%20%3D%2037%3B%0A%20%20%0A%20%20int%20min%20%3D%20Min%28a,%20b%29%3B%0A%20%20printf%28%22%25d%22,%20min%29%3B%0A%0A%20%20return%200%3B%0A%7D%0A%0Aint%20Min%28int%20a,%20int%20b%29%20%7B%0A%20%20return%20a%20%3E%20b%20%3F%20b%20%3A%20a%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
//

//stack:栈（空间）
//heap:堆（空间）
//stack frame:栈帧:为调用的函数专门分配的空间
//函数调用结束，整块栈帧消失（解释了为何函数里变量作用域被限制在函数里）

#include <stdio.h>

#define NUM 5
int Min(const int nums[],int len);

int main() {
    int numbers[NUM]={34,37,25,45,43};
    int min= Min(numbers,NUM);
    printf("%d\n",min);
    return 0;
}
int Min(const int nums[],int len){
    if(len==1){
        return nums[0];
    }
    int partial_min= Min(nums,len-1);
    return partial_min<nums[len-1]?partial_min:nums[len-1];
}

