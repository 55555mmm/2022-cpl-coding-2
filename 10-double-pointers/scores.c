//
// Created by En on 2022/12/7.
//
#include <stdio.h>
#include <stdlib.h>

#define COLS 3

void Print(int table[][COLS], int rows);

int main() {
    /**
     * C, Java, Python scores of several musicians
     */
    int rows = 0;
    printf("Please input the number of students.\n");
    scanf("%d", &rows);
//     int scores[4][COLS]={
//             {0,10,20},
//             {10,20,30},
//             {20,30,40},
//             {30,40,50}
//     };

    // malloc here//只关注大小，不关注类型
    int (*scores)[COLS] = malloc(rows*COLS*sizeof **scores);
    if(scores==NULL){
        return 0;
    }

    printf("Please input the scores of these students.\n");

    // fill in data here
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < COLS; ++col) {
            scanf("%d",&scores[row][col]);
        }
    }

    // print it here
    Print(scores,rows);

    // access musician_score_table[3][2]

    // ptr_scores here
     int (*ptr_scores)[COLS] = scores;
     printf("ptr_scores[3][2] = %d\n",
            (*(ptr_scores + 3))[2]);//展开几层都行

    // do not forget to free it
    free(scores);
    return 0;
}

// int table[]: int *table
// int table[][COLS](table是一个数组，数组里的每一个元素又是一个数组): int (*table)[COLS](这是一个指针，指向一个数组！！！)
//table实际上是一个一维数组，这个数组里的每一个元素又是一个数组

void Print(int (*table)[COLS], int rows) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        // table[i][j]: (*(table + i))[j]: *((*(table + i)) + j)
        // table + i: 指向的是整个数组的地址，值一样，从指针的角度看上去，指向的内存是不一样的，这两个指针解读的方式是不一样的
        // 解引用后才是数组里的一维数组的地址
        for (int j = 0; j < COLS; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}