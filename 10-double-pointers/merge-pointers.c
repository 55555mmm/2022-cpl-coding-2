//
// Created by En on 2022/12/18.
//
#include <stdio.h>
#include <stdlib.h>

#define LEN_L 5
#define LEN_R 6

//返回数组：就是返回指针（这个指针指向数组首地址）
int *Merge(int L[], int llen, int R[], int rlen);
//*解引用运算符优先级低于函数调用运算符()
//因此解读为：Merge是一个函数，返回一个int *类型的指针

int main() {
    int L[LEN_L] = {1, 3, 5, 7, 9};
    int R[LEN_R] = {0, 2, 4, 6, 8, 10};

    int *merge = Merge(L, LEN_L, R, LEN_R);
    for (int i = 0; i < LEN_L + LEN_R; i++) {
        printf("%d ", merge[i]);
    }

    return 0;
}

int *Merge(int L[], int llen, int R[], int rlen) {
    int *merge = malloc((llen + rlen) * sizeof *merge);

    int l = 0;
    int r = 0;
    int m = 0;

    while (l < llen && r < rlen) {
        if (L[l] <= R[r]) {
            merge[m] = L[l];
            m++;
            l++;
        } else {
            merge[m] = R[r];
            m++;
            r++;
        }
    }

    // l >= llen || r >= rlen
    while (r < rlen) {
        merge[m] = R[r];
        m++;
        r++;
    }

    while (l < llen) {
        merge[m] = L[l];
        m++;
        l++;
    }

    return merge;
}