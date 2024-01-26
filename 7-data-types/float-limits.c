//
// Created by En on 2022/11/11.
//
#include <stdio.h>
#include <float.h>
//明确表示是什么浮点数类型（float加后缀F;long double加后缀L,不加默认double）
//math.h中起初接收返回都为double类型，后来才加了一些能接收返回float类型的函数
//非规范化（denormal）浮点数（非常靠近0）可以使用，但在底层硬件实现上的运算性能比规范化（normal）浮点数差（几倍）
//zoom-in view:向两边越来越稀疏
int main() {
    // 3.402823e+38
    printf("FLT_MAX = %e\n", FLT_MAX);
    // 1.175494e-38
    printf("FLT_MIN = %e\n", FLT_MIN);//min指的是最小的正数
    // 1.401298e-45
    printf("FLT_TRUE_MIN = %e\n", FLT_TRUE_MIN);
    // 1.192093e-07
    printf("FLT_EPSILON = %e\n\n", FLT_EPSILON);//能表示的所有数里面大小相距最近的两个数的距离
    // （刻画了浮点数系统所能表达的精度）

    // %lf for scanf; %lf for printf since C99
    // 1.797693e+308
    printf("DBL_MAX = %e\n", DBL_MAX);
    // 2.225074e-308
    printf("DBL_MIN = %e\n", DBL_MIN);
    // 4.940656e-324
    printf("DBL_TRUE_MIN = %e\n", DBL_TRUE_MIN);
    // 2.220446e-16
    printf("DBL_EPSILON = %e\n\n", DBL_EPSILON);

    return 0;
}