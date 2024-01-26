//
// Created by En on 2022/12/18.
//

//不同文件夹cmakelists要链接到ll.c文件应该这样写: ../12-linkedlist//ll//ll.c
#include <stdio.h>
#include <stdlib.h>
#include "ll.h"//ll.c与ll.h在同一个文件夹下，可直接写

void Init(LinkedList *list){
    list->head=NULL;
    list->tail=NULL;
}

bool IsEmpty(const LinkedList *list){
    return list->head == NULL;
}

bool IsSingleton(const LinkedList *list){
    return !IsEmpty(list) && list->head == list->tail;
    //如果list是空链表：list->head == NULL && list->tail == NULL
}

void Print(const LinkedList *list){
    if(IsEmpty(list)){
        return;
    }
    Node *node = list->head;

    do{
        printf("%d ",node->val);
        node=node->next;
    }while (node != list->head);
}

void Append(LinkedList *list,int val){
    Node *node = malloc(sizeof *node);
    if(node == NULL){
        printf("Error: malloc failed in Append()\n");
        return;
    }
    node->val = val;

    if(IsEmpty(list)){
        list->head=node;
    } else{
        list->tail->next = node;//顺序不可随意调整
    }
    list->tail=node;
    list->tail->next=list->head;

    //SIGSEGV : segmentation fault:段错误//访问了不该访问的内存（解引用了空指针也是访问了不该访问的内存）
}

void Delete(LinkedList *list, Node *prev){
    if(IsEmpty(list)){
        list->head=NULL;
        list->tail=NULL;
        return;
    }
    if(IsSingleton(list)){
        free(prev);
        list->head=NULL;
        list->tail=NULL;
        return;
    }
    Node *cur = prev->next;
    Node *next = cur->next;
    prev->next=next;

    //cur != list->head || cur != list->tail
    if(cur==list->head){
        list->head=next;
    }

    if(cur==list->tail){
        list->tail=prev;
    }
    free(cur);
}

int GetHeadVal(const LinkedList *list){
    if(IsEmpty(list)){
        return -1;
    }
    return list->head->val;
}

void Free(LinkedList *list){
    while (!IsEmpty(list)){
        Delete(list,list->head);
    }
}