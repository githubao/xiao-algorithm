// Created by BaoQiang at 2017/1/23 20:40

#include "stdio.h"
#include "stdlib.h"

#define MaxSize 100

typedef int ElemType;

typedef struct {
    ElemType *elem;
    int length;
    int listsize;
} Sqlist;

void initSqlist(Sqlist *L) {
    L->elem = (int *) malloc(MaxSize * sizeof(ElemType));
    if (!L->elem) {
        exit(0);
    }
    L->length = 0;
    L->listsize = MaxSize;
}

main() {
    printf("hello");
	getchar();
}


