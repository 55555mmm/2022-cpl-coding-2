//
// Created by En on 2022/12/18.
//

//printf
// stdio.c：这些.c文件安装编译器时，没有一起安装进来
#include <stdio.h>//.h文件里放的几乎都是函数的声明和定义，更具体的实现，是放在与.h相对应的.c文件里的
#include <assert.h>

//ll:delete, append(添加)
//#include "ll/ll.h":自己实现
//将实现的链表放入一个新的文件夹，体现实现它与解决问题是两回事（大型程序）

#include "ll/ll.h"
//""与<>的区别在于:
// 如果用<>:程序在编译的时候，编译器会在系统指定的目录下面找这个头文件(路径是系统指定的路径)
// 如果用"":先到工程里面去找，找不到再去系统里面去找


#define NUM 100

void SitAroundCircle(LinkedList *list,int num);
void KillUntilOne(LinkedList *list);
int GetSurvivor(const LinkedList *list);


int main(){
    //先基于声明做实现
    for(int i=1;i<=NUM;i++){
        LinkedList list;
        Init(&list);

        SitAroundCircle(&list,i);
        //Print(&list);
        KillUntilOne(&list);
        int survivor= GetSurvivor(&list);
        printf("%d : %d\n",i,survivor);

        Free(&list);
    }


    return 0;
}

void SitAroundCircle(LinkedList *list,int num){
    for (int i = 1; i <= num ; i++) {
        Append(list,i);
    }

}

void KillUntilOne(LinkedList *list){
    Node *node = list->head;

    while (!IsSingleton(list)){
        Delete(list,node);
        node=node->next;
    }
}

int GetSurvivor(const LinkedList *list){
    assert(IsSingleton(list));//后跟条件表达式：结果为真还是假
    //如果结果为真，assert（断言）通过，接着往下执行
    //如果结果为假，assert失败，会抛一个错误，整个程序终止（会报错）
    return GetHeadVal(list);
}

