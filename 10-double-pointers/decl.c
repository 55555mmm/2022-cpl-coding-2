//
// Created by En on 2022/12/7.
//

//双重指针(Double Pointers)：指向指针的指针
//指针数组:Pointer Array(大的结构上是一个数组，但数组的每个元素是一个指针)
//Pointers and 2D Arrays:指针和二维数组
//Function Pointers:函数指针(指向函数的指针)

int main() {
    char **argv;//argv是一个指针，这个指针指向一个指针，指向的指针指向char

    int *names[10];//name是一个数组，这个数组的每一个元素是一个指针，这个指针指向int

    int (*musician_score_table)[10];//musician_score_table是一个指针，这个指针指向一个数组，这个数组有十个元素，每个元素是一个int

    int *StrCpyStd(char *dest, const char *src);//StrCpyStd是一个函数，这个函数有两个参数，而且返回一个int *的指针

    int (*comp)(const void *left, const void *right);//comp是一个指针，指向一个函数，这个函数接受两个参数，返回一个int

    int atexit(void (*func)(void));//atexit是一个函数，函数参数是一个指针，这个指针指向一个函数，这个函数没有参数，返回void。
    // 外面大的这个atexit函数返回一个int
    //总的来说，atexit这个函数，接受一个函数指针，返回一个int
    //这个函数是C语言标准库里的函数。

    void (*signal(int sig, void (*handler)(int)))(int);
    //signal是一个函数，有两个函数参数，一个是int，一个是个函数指针（接受int返回void）
    //signal是一个函数返回一个函数指针，这个指针指向一个函数，这个函数接受一个int，返回一个void
    //C标准库里的函数

    char (*(*func(int num, char *str))[])();
    //func是一个函数，接受两个参数，返回一个指针，指针指向一个数组，这个数组的每一个元素都是一个指针，这个指针指向一个函数，这个函数没有参数，返回char

    char (*(*arr[3])())[5];
    //arr是一个数组，这个数组里有3个元素，每个元素是一个指针，这个指针指向一个函数，这个函数没有参数，返回一个指针，这个指针指向一个数组，这个数组有5个元素，每个元素是char
}