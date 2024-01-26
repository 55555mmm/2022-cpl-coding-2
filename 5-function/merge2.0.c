//
// Created by En on 2022/10/29.
//
#include <stdio.h>
#define LEN_L 5
#define LEN_R 6

void Print(const int arr_1[],int len_1,const int arr_2[],int len_2);

int main() {
    int L[LEN_L]={1,3,5,7,9};
    int R[LEN_R]={0,2,4,6,8,10};
    Print(L,LEN_L,R,LEN_R);
    return 0;
}
void Print(const int arr_1[],int len_1,const int arr_2[],int len_2){
    int l = 0;
    int r = 0;
    while (l < len_1 && r < len_2) {
        if (arr_1[l] <= arr_2[r]) {
            printf("%d", arr_1[l]);
            l++;
        } else {
            printf("%d", arr_2[r]);
            r++;
        }
    }
    while ( l< len_1) {
        printf("%d", arr_1[l]);
        l++;
    }
    while (r < len_2) {
        printf("%d", arr_2[r]);
        r++;
    }
}
