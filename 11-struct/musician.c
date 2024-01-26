//
// Created by En on 2022/12/18.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum gender {
    MALE, FEMALE,
} Gender;//枚举类型

typedef struct score {
    int c_score; // 4(字节)要求存放地址空间的首地址为4的倍数
    int java_score; // 4
    int python_score; // 4 (+4)(整个结构体里需要占据的最大字节数为8，因此也要在地址为8的倍数的地方结束，所以要补4个字节)
    //对齐的概念
} Score;

// tag:musician
typedef struct musician {
    char *name; // 8：最大占用字节数：8，要求存放在首地址为8的倍数的地址空间里
    Gender gender; // 1 (+ 7):内存对齐：填充了7个字节（编译器自动填充，访问不到），因为下一个存放的是char *类型，要求存放的地址空间首地址为8的倍数
    char *album; // 8

    Score score;//结构体里面能包含结构体：能嵌套
} Musician;

void PrintMusician(const Musician *m);
int CompareMusicians(const void *m1, const void *m2);

int main() {
    printf("sizeof Musician : %zu\n", sizeof(Musician));
    //

    Musician luo = {
            .name = "luo dayou",
            .gender = MALE,//赋值都是整数，不会报错
            .album = "ZhiHuZheYe",
            .score = {10, 20, 30},
            // .score.c_score = 10,
            // .score.java_score = 20,
            // .score.python_score = 30,
    };

    Musician cui = {
            .name = "cui jian",
            .gender = MALE,
            .album = "XinChangZhengLuShangDeYaoGun",
            .score.c_score = 10,
            .score.java_score = 20,
            .score.python_score = 30,
    };

    char album[] = "YiKeBuKenMeiSuDeXin";

    Musician zhang = {
            .name = "zhang chu",
            .gender = MALE,
            .album = album,//可重名：一个在结构体里，一个在main函数里
            //指针拷贝，说明有两个指针指向了同一个数组
            //拷贝到guo后，通过指针修改guo也会影响到zhang
            .score.c_score = 10,
            .score.java_score = 20,
            .score.python_score = 30,
    };

    Musician guo = zhang;//结构体可直接赋值：信息的完全拷贝：如果有指针，两个指针指向同一个变量，需注意，不然易出错
    guo.name = "guo";//拷贝的关系，不会影响到zhang
    //虽然结构体之间可相互赋值，但不能整体去比较是否相等！（例如：guo==zhang（×））

    strcpy(guo.album, "YiKeJiuMeiSuDeXin");
    PrintMusician(&guo);
    PrintMusician(&zhang);

    Musician musicians[] = {luo, cui, zhang};//可以把结构体变量放在一个数组里
    int len = sizeof musicians / sizeof *musicians;//类型的大小和变量的大小
    for (int i = 0; i < len; i++) {
        PrintMusician(musicians + i);
    }

    qsort(musicians, len,
          sizeof *musicians, CompareMusicians);
    for (int i = 0; i < len; i++) {
        PrintMusician(musicians + i);
    }

    return 0;
}

void PrintMusician(const Musician *m) {//结构体太大，拷贝影响性能，改传指针
    printf("\n%s\t%d\t%s\t%d\t%d\t%d\n",
           m->name,//指针：相当于(*m).name：.运算符优先级更高
           m->gender,
           m->album,
           m->score.c_score,
           m->score.java_score,
           m->score.python_score);
}

// actual argument: const Musician *
int CompareMusicians(const void *m1, const void *m2) {
    const Musician *m_left = m1;//强制类型转换
    const Musician *m_right = m2;
    return strcmp(m_left->album, m_right->album);
}