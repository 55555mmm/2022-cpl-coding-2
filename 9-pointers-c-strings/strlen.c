//
// Created by En on 2022/12/7.
//
#include <stdio.h>

int StrLen(const char *s);
size_t StrLenStd(const char *s);

int main() {
    char msg[20] = "Hello World!";//这种方式修改的是放在数组里的一份拷贝，因此没有问题
    printf("%s\n", msg);

    msg[0] = 'N';
    printf("%s\n", msg);

    // string literal;//"Hello World!"是字符串自变量
    // may be stored in read-only memory有可能被存放在只读的内存区域
    // undefined behavior（如果用如下方式修改字符串变量将引发未定义行为）
    // char *ptr_msg = "Hello World!";//strcmp没有问题(不会修改)
    //用作strcpy里的src没有问题；但要是dest一般会有问题
    //一种解决方案:char *后用malloc来申请一段空间
    // ptr_msg[0] = 'N';
    // interrupted by signal 11: SIGSEGV
    // SIG: signal; SEGV: segmentation violation(段错误：最主要的原因：访问到了不该访问的地方/修改了只读（不能修改）的地方)
    // printf("%s\n", msg);

    printf("StrLen(%s) = %d\n", msg, StrLen(msg));

    return 0;
}

int StrLen(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

size_t StrLenStd(const char *s) {
    const char *sc;
    for (sc = s; *sc != '\0'; sc++);

    return (sc - s);
}