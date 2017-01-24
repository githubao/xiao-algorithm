// Created by BaoQiang at 2017/1/23 20:40

#include "stdio.h"

#define MaxSize 100

void insertElem(int SqList[], int *len, int i, int x) {
    int t;
    if (*len == MaxSize || i < 0 || i > *len) {
        printf("This insert is illegal\n");
        return;
    }
    for (t = *len; t > i; t--) {
        SqList[t] = SqList[t - 1];
    }
    SqList[i] = x;
    *len += 1;
}

void deleteElem(int *sqList, int *len, int i) {
    int j;
    if (i < 0 || i >= *len) {
        printf("This delete is illegal\n");
        return;
    }
    for (j = i; j <= *len - 1; j++) {
        sqList[j] = sqList[j + 1];
    }
    *len = *len - 1;
}

void printSqList(int sqList[], int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", sqList[i]);
    }
    printf("\n");
}


int main(int argc, char **argv) {
    int sqList[MaxSize];
    int len = 6;
    int i;
    for (i = 0; i < len; ++i) {
//        scanf("%d", &sqList[i]);
        sqList[i] = i + 1;
    }
    printSqList(sqList, len);

//    insertElem(sqList, &len, 3, 0);
    insertElem(sqList, &len, 6, 22);
    printSqList(sqList, len);

//    insertElem(sqList, &len, 11, 0);

    deleteElem(sqList, &len, 5);
    printSqList(sqList, len);
}


