//
// Created by En on 2022/11/11.
//
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

bool IsEqual(double x, double y);

int main() {
    printf("%d\n", IsEqual(DBL_MAX, DBL_MAX - 100));
    //越往右越稀疏，在double表示里相等

    printf("%.50f\n", DBL_MAX - (DBL_MAX - 100));

    return 0;
}

bool IsEqual(double x, double y) {
    return fabs(x - y) <= DBL_EPSILON;
}