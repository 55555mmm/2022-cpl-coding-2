//
// Created by En on 2022/11/19.
//
//对于一个函数：可传指针进来，也可返回指针
//对于一个函数想返回多个值：可通过传进指针，将计算出来的值赋值给传进来的指针指向的地方（在函数里修改），从而达到返回多个值的效果。
#include <stdio.h>
#include <stdlib.h>

//In expressions,the name of an array is a synonym for the address of its first element.
//But an array name is not a variable.
//数组名是数组第一个元素地址，相当于指针，但数组名不是一个变量。

void WrongSwap(int left, int right);
void Swap(int *left,int *right);
void Print(const int *arr, int len);//含义：arr是一个指针，该指针指向一个int型的变量，这个变量是一个常量（不允许修改）
void SelectionSort(int arr[], int len);

int main() {
    int len=0;
    scanf("%d",&len);

    //return value: (返回类型（也是指针）：（指向空类型的指针）void *（不知道存什么类型，返回void）)(malloc返回值：申请到的那块空间的首地址)
    int *numbers = malloc(len * sizeof (*numbers));//(类型转换)（C不需要写；C++需要）
    //int *：存int类型
    //统一改名快捷键：shift+F6
    //NULL: null pointer(空指针)((void *) 0)(含义：将整数0（内存为0的第一块空间：操作系统不允许任何程序访问的第一个字节的位置）强制转换成地址)
    //空指针可以理解成：不指向任何地方的指针（指了也没用）
    //C语言保证：空指针与其他非空指针肯定不相等,因此可以这样写（如下）；
    if(numbers==NULL){
        printf("Memory allocation failed!\n");
        return 0;
    }

    for(int i=0; i < len; i++){
        scanf("%d",&numbers[i]);
    }

    Print(numbers, len);
    // numbers: the address of the first element of the `numbers` array
    // pass by value: the copy of the address of the first element of the `numbers` array
    SelectionSort(numbers, len);
    Print(numbers, len);
    //自动变量：它们所占的空间自动分配自动释放（普通变量定义之后存放在栈上）
    //通过malloc申请的空间不在栈上面，在堆上面
    free(numbers);
    //同一块空间不能free两次
    //同一块空间被free之后不能再被访问
    //像oj或是自己写的小程序这样的一次性程序main函数里面忘记free问题不大，malloc函数分配的空间在堆区里（操作系统帮你管理）。
    //当忘记free的时候，操作系统会将分配给你的空间帮你回收掉。
    //但如果是正式的程序或是比较大型的程序（如操作系统），这种程序会默认它会一直运行，若是总是忘记free，很快将会耗光内存。
    //自己写的小程序被别人拿去当作大程序的其中一部分，若是malloc忘记free也会造成内存泄露，对整个大的程序都会有影响。
}

void Print(const int arr[], int len) {
    printf("\n");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// arr: the (copy of the) address of the first element of the numbers` array
//数组作为形参写法：int arr[] vs. int *arr
void SelectionSort(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        // find the minimum of numbers[i .. len - 1]
        //arr[i] <=> *(arr + i) <=> *(i + arr) <=> i[arr]
        int min = arr[i];//根据被它指向的元素的数据类型来决定它跳过多少
        //由于数组空间连续，因此可以对指针做加法/减法
        int min_index = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < min) {
                min = arr[j];
                min_index = j;
            }
        }

        // swap arr[i] and arr[min_index]
        //int tmp = arr[i];
        //arr[i] = arr[min_index];
        //arr[min_index] = tmp;
        // WrongSwap(1 = arr[1], 5 = arr[5])
        // WrongSwap(arr[i], arr[min_index]);
        // &arr[i]= &(*(arr+i))= arr+i
        Swap(&arr[i],&arr[min_index]);
    }
}
void Swap(int *left,int *right){
    int temp=*left;
    *left=*right;
    *right=temp;
}
// left = 1, right = 5
void WrongSwap(int left, int right) {
    int tmp = left;
    left = right;
    right = tmp;
}
// left = 5, right = 1
