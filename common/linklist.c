// Created by BaoQiang at 2017/1/24 15:40

#include "stdio.h"
#include "stdlib.h"

//typedef int ElemType;
typedef char *ElemType;

#define LENGTH 5

typedef struct node {
    ElemType data;
    struct node *next;
} LNode, *LinkList;

char *datas[LENGTH] = {"1", "2", "3", "4", "5"};

LinkList createLinkList(int n) {
    LinkList current, tail, list = NULL;
    ElemType e;
    int i;
    for (i = 0; i < n; ++i) {
//        scanf("%s", &e);
        e = "head";
        current = (LinkList) malloc(sizeof(LNode));
        current->data = e;
        current->next = NULL;

        if (!list) {
            list = current;
        } else {
            tail->next = current;
        }
        tail = current;
    }
    return list;
}


void insertLink(LinkList *list, LinkList beforeInsert, ElemType e) {
    LinkList current;
    current = (LinkList) malloc(sizeof(LNode));
    current->data = e;
    if (!*list) {
        *list = current;
        current->next = NULL;
    } else {
        current->next = beforeInsert->next;
        beforeInsert->next = current;
    }
}

void deleteLink0(LinkList *list, LinkList beforeDel, LinkList toDel) {
    if (toDel == *list) {
        *list = toDel->next;
    } else {
        beforeDel->next = toDel->next;
    }
    free(toDel);
}

void deleteLink(LinkList *list, LinkList toDel) {
    LinkList current;
    if (toDel == *list) {
        *list = toDel->next;
        free(toDel);
    } else {
        for (current = *list; current->next != toDel; current = current->next);
        if (current->next != NULL) {
            current->next = toDel->next;
            free(toDel);
        }
    }
}

void destroyLink(LinkList *list) {
    LinkList current, after;
    current = *list;
    while (current) {
        after = current->next;
        free(current);
        current = after;
    }
    *list = NULL;
}

void printLink(LinkList list) {
    if (NULL == list) {
        return;
    }

    LinkList current = list;
    while (current) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");

}

LinkList forwardLink(LinkList list, int n) {
    if (NULL == list) {
        return NULL;
    }

    LinkList current = list;

    for (int i = 0; i < n; ++i) {
        current = current->next;
    }
    return current;
}

int main(int argc, char **argv) {
    int i;
    ElemType e;
    LinkList list, current;
    list = current = createLinkList(1);

//    scanf("%c", e);
//    while (e) {
//        insertLink(list, current, e);
//        current = current->next;
//        scanf("%c", e);
//    }

    for (int j = 0; j < LENGTH; ++j) {
        e = datas[j];
        insertLink(&list, current, e);
        current = current->next;
    }

    current = list;
    printLink(list);
    current = forwardLink(list, 2);

    deleteLink(&list, current);
    printLink(list);

    destroyLink(&list);


}