//
// Created by En on 2022/11/17.
//
#include <limits.h>
#include <stdio.h>

int SquareInt(int num);
double SquareDouble(double num);
//隐式/强制类型转换：定义初始化、赋值/函数调用/函数返回
//类型提升（算术表达式、逻辑表达式）

int main() {
    // narrowing conversion (still in the range)
    int i = 3.14159;//类型的窄化（窄化后在范围内）

    // out of the range: undefined behavior!!!
    int j = UINT_MAX;//（窄化后依然不在范围内）触发UB
    //用double接收int一般没问题（int类型提升为double）

    // arguments; narrowing conversion
    double k = 3.14159;
    SquareInt(k);

    // return value; narrowing conversion
    int m = SquareDouble(k);

    return 0;
}

int SquareInt(int num) {
    return num * num;
}

double SquareDouble(double num) {
    return num * num;
}