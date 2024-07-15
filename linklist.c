#include "linklist.h"

#include <stdio.h>
#include <stdlib.h>

linklist list_create() {
    linklist H;

    H = (linklist)malloc(sizeof(listnode));
    if (H == NULL) {
        printf("Malloc failed\n");
        return H;
    }

    H->data = 0;
    H->next = NULL;

    return H;
}

int list_tail_insert(linklist H, data_t value) {
    linklist newNode;
    linklist q = H;

    if (H == NULL) {
        printf("H is NULL\n");
        return -1;
    }

    newNode = (linklist)malloc(sizeof(listnode));
    if (newNode == NULL) {
        printf("Malloc failed\n");
        return -1;
    }
    newNode->data = value;
    newNode->next = NULL;

    // locate tail
    while (q->next != NULL) {
        q = q->next;
    }

    q->next = newNode;

    return 0;
}

int list_show(linklist H) {
    linklist p;

    if (H == NULL) {
        printf("H is NULL");
        return -1;
    }
    p = H;
    while (p->next != NULL) {
        printf("%d\n", p->next->data);
        p = p->next;
    }

    return 0;
}

// get the node position.
linklist list_get(linklist H, int pos) {
    linklist p;
    if (H == NULL) {
        printf("H is NULL\n");
        return NULL;
    }

    if (pos == -1) {
        return H;
    }

    p = H;
    while (pos >= 0) {
        if ((p = p->next) == NULL) {
            printf("postion is out of range.\n");
            return NULL;
        } else {
            pos--;
        };
    }
    return p;
}
int list_insert(linklist H, data_t value, int pos) { return 0; }