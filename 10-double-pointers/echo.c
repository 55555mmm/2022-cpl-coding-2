//
// Created by En on 2022/12/7.
//
#include <stdio.h>

/**
 * @brief program/command-line arguments(命令行参数)
 * @param argc c: count the number of arguments(不是传进来的，而是自己计算的，帮你数运行该函数时传进来了几个参数)
 * @param argv v: vector(数组或向量)
 *  argv[0]: program name
 *  argv[1 ... argc - 1]: ant hengxin(传进来的参数)
 *  argv[argc]: NULL
 *
 * @return
 * gcc 后得到一个echo可运行文件（平时运行直接敲回车）
 * // echo ant hengxin（可输入几个参数）(功能：将传进来的参数原样输出)
 */
int main(int argc,char *argv[]){//main函数允许接受两个参数（整型和字符串数组）
//    for (int i = 1; i < argc; i++) {
//        printf("%s\n",argv[i]);
//    }
    //第一个方法：命令提示符：可惜不能换行
    //第二个方法：Edit Run Configuration 将参数填入程序参数的一栏
    for(char **ptr=argv+1;*ptr !=NULL;ptr++){
        printf("%s\n",*ptr);
    }
    // *++ptr vs. *ptr++
    // *--ptr vs. *ptr--
    char **ptr = argv;
    while (*++ptr != NULL){
        printf("%s\n",*ptr);
    }

    return 0;
}