//
// Created by En on 2022/10/29.
//
#include <stdio.h>

#define LEN 20

void Print(const int arr[],int len);
void SelectionSort(int arr[],int len);

int main() {
    int numbers[LEN] = {0};
    /*
     * Input the array
     * Note: fails to run this program in "Run" (Ctrl + D)
     * See: https://youtrack.jetbrains.com/issue/CPP-5704
     * Use "Terminal" instead.
     */
    int len = -1;
    while (scanf("%d", &numbers[++len]) != EOF);

    Print(numbers,len);
    // numbers: the address of the first element of the numbers' array
    //(array)pass by value: the copy of the address of the first element of the numbers' array
    SelectionSort(numbers,len);
    Print(numbers,len);

    return 0;
}
void Print(const int arr[],int len){
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void SelectionSort(int arr[],int len){
    for (int i = 0; i < len - 1; i++) {
        // find the minimum value of numbers[i .. n - 1]
        int min = arr[i];
        int min_index = i;

        for (int j = i + 1; j < len; j++) {
            if (arr[j] < min) {
                min = arr[j];
                min_index = j;
            }
        }
        // swap numbers[i] and numbers[min_index]
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}
