// Created by BaoQiang at 2017/1/23 22:04

#include "stdio.h"
#include "stdlib.h"

typedef int ElemType;
//typedef double ElemType;
//typedef char ElemType;

#define MaxSize 10

typedef struct {
    ElemType *elem;
    int length;
    int listSize;
} SqList;

void initSqList(SqList *list) {
    list->elem = (ElemType *) malloc(MaxSize * sizeof(ElemType));
    if (!list->elem) {
        exit(0);
    }
    list->length = 0;
    list->listSize = MaxSize;
}

void insertElem(SqList *list, int i, ElemType item) {
    if (NULL == list || i < 0 || i > list->length) {
        printf("This insert is illegal\n");
        exit(0);
    }

    ElemType *base, *p;

    if (list->length == list->listSize) {
        base = (ElemType *) realloc(list->elem, (list->listSize * 2 - 1) * sizeof(ElemType));
        list->elem = base;
        list->listSize = list->listSize * 2 - 1;
    }

    for (p = &(list->elem[list->length]); p > &(list->elem[i]); p--) {
        *p = *(p - 1);
    }
    list->elem[i] = item;
    list->length++;
}

void deleteElem(SqList *list, int i) {
    if (NULL == list || i < 0 || i >= list->length) {
        printf("This delete is illegal\n");
        exit(0);
    }

    ElemType *q;
    for (q = &(list->elem[i]); q < &(list->elem[list->length]); q++) {
        *q = *(q + 1);
    }
    list->length--;
}

void printSqList(SqList *list) {
    for (int i = 0; i < list->length; ++i) {
        printf("%f ", list->elem[i]);
//        printf("%c ", list->elem[i]);
    }
    printf("\n");
}


int main(int argc, char **argv) {
    SqList sqList;
    int i;

    initSqList(&sqList);

    for (i = 0; i < 15; ++i) {
        insertElem(&sqList, i, i);
    }
    printSqList(&sqList);

    insertElem(&sqList, 3, 22);
    printSqList(&sqList);

    deleteElem(&sqList, 5);
    printSqList(&sqList);
}
