//
// Created by En on 2022/12/18.
//
/**
 * file: sort.c
 *
 * See also bsearch: https://en.cppreference.com/w/c/algorithm/bsearch
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void PrintInts(const int *integers, int len);
void PrintStrs(const char *str[], int len);

int CompareInts(const void *left, const void *right);
int CompareStrs(const void *left, const void *right);

int main() {
    // sort an array of integers
    int integers[] = {-2, 99, 0, -743, 2, INT_MIN, 4};
    int size_of_integers = sizeof integers / sizeof *integers;

    /**
     * q: quick
     * qsort: https://en.cppreference.com/w/c/algorithm/qsort
     * void qsort( void *ptr, size_t count, size_t size,
              int (*comp)(const void *, const void *) );
     *参数分别是：要排的数组首地址，要排的数组有多少元素，每个元素大小，以及比较规则
     */
    int (*comp)(const void*, const void*) = CompareInts;//函数指针可以进行赋值
    // 函数可以当做变量去使用，可以学学函数程序语言（function programming）

    // sort ints here
    qsort(integers, size_of_integers,
          sizeof *integers, comp);
    PrintInts(integers, size_of_integers);

    // Sorting an array of strings
    const char *names[] = {
            "Luo Dayou",
            "Cui Jian",
            "Dou Wei",
            "Zhang Chu",
            "He Yong",
            "Wan Qing",
            "WuTiaoRen",
            "ZuoXiao",
            "Hu Mage",
            "Li Zhi"
    };
    int size_of_names = sizeof names / sizeof *names;

    // sort musicians here
    comp = CompareStrs;
    qsort(names, size_of_names,
          sizeof *names, comp);
    PrintStrs(names, size_of_names);
}

void PrintInts(const int *integers, int len) {
    printf("\n");
    for (int i = 0; i < len; ++i) {
        printf("%d ", integers[i]);
    }
    printf("\n");
}

void PrintStrs(const char *str[], int len) {
    printf("\n");
    for (int i = 0; i < len; i++) {
        printf("%s\n", str[i]);
    }
    printf("\n");
}

// actual argument: const int *left
int CompareInts(const void *left, const void *right) {
    int left_int = *(const int*) left;//要先强制转换成想要比较的类型
    int right_int = *(const int *) right;

    if (left_int < right_int) {
        return -1;
    }

    if (left_int > right_int) {
        return 1;
    }

    return 0;
    // return left_int - right_int;
}

// actual argument: char *const *left
//left/right ：是指向字符串的指针，因此实际类型：char **
int CompareStrs(const void *left, const void *right) {
    char *const *pp1 = left;
    char *const *pp2 = right;
    return strcmp(*pp1, *pp2); // 参数：const char *
}