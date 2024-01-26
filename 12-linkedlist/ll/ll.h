//
// Created by En on 2022/12/18.
//

//clion自动生成，只需保证整个工程的.h里面生成的这个常量命名是唯一的
#ifndef INC_2022_CPL_CODING_2_LL_H//检查该常量是否定义过，若未定义，那就定义一下这个常量并执行下面的代码。
// 若定义过，那么这个条件不成立，下面的代码就不起作用了
#define INC_2022_CPL_CODING_2_LL_H
//C语言不允许重复定义函数和变量，这三行代码可防止同时#include多份头文件时发生重复定义的问题

// adding code here

#include <stdbool.h>

typedef struct node{
    int val;//编号
    struct node *next;//指针大小是固定的
    //当自定义类型的时候，重要的是要确定这个类型的大小，因为当用这个类型去声明变量时，需要知道这个变量在内存中占用的大小
    //指向下一个节点的指针
} Node;//!第十二行不能写成 ： Node *node 原因：结构体声明未结束，Node不可见

// Invariants:(不变式：永远成立的条件)
// (1) head always points to the first node : head永远保持指向第一个节点
// (2) tail always points to the last node
typedef struct ll{
    Node *head;
    Node *tail;
} LinkedList;

void Init(LinkedList *list);//初始化链表

bool IsEmpty(const LinkedList *list);
bool IsSingleton(const LinkedList *list);

/**
 * @brief Return -1 if list is empty.
 * @param list
 * @return
 */
int GetHeadVal(const LinkedList *list);
Node *Search(const LinkedList *list, int val);
//!功能：搜索一个值为val的节点，返回这个节点的指针。如果没有，返回空指针，如果有多个，可返回第一个

void Print(const LinkedList *list);

void Append(LinkedList *list,int val);

void Insert(LinkedList *list,Node *prev,int val);
//!在prev后面插入节点，更灵活，不一定是末尾

void Delete(LinkedList *list, Node *prev);

void Free(LinkedList *list);//链表里的节点都是malloc出来的空间，要及时free掉

#endif //INC_2022_CPL_CODING_2_LL_H
