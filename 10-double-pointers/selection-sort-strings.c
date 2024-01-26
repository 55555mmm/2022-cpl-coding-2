//
// Created by En on 2022/12/7.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define  LEN 10

void Swap(char **left, char **right);
void Print(char *arr[], int len);
void SelectionSort(char *arr[], int len);

int main() {
    char *musicians[10] = {//[]在类型信息声明时优先级高于*
            // 因此在读这段声明的代码时，应该解释为：musicians是一个数组，数组里的每一个元素都是一个char *类型的指针
            //const char *musicians[10]:这个数组的每一个元素是一个指针，这个指针指向的内容是const
            //char * const musicians[10]:musicians是一个数组，这个数组里的每一个元素是一个常量指针（这个指针的指向不能修改）（此处不能加）
            "Luo Dayou",
            "Cui Jian",
            "Dou Wei",
            "Zhang Chu",
            "Yao",
            "Wan Qing",
            "ZuoXiao",
            "ErShou Rose",
            "Hu Mage",
            "Li Zhi",
    };


    Print(musicians, LEN);
    SelectionSort(musicians, LEN);
    Print(musicians, LEN);
}

//char arr[]: char *arr
//char *arr[]:char **arr
void Print(char *arr[], int len) {
    printf("\n");
    for (int i = 0; i < len; i++) {
        printf("%s\n", arr[i]);
    }
    printf("\n");
}

void SelectionSort(char *arr[], int len) {
    for (int i = 0; i < len; i++) {
        // find the minimum of numbers[i .. len - 1]
        char *min = arr[i];
        int min_index = i;
        for (int j = i + 1; j < len; j++) {
            if (strcmp(min,arr[j])>0) {
                min = arr[j];
                min_index = j;
            }
        }
        // swap arr[i] and arr[min_index]
        Swap(arr + i, arr + min_index);
    }
}
//传进来的是char **类型
void Swap(char **left, char **right) {
    char *temp = *left;
    *left = *right;
    *right = temp;
}
