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
        printf("%d ", p->next->data);
        p = p->next;
    }
    puts("");

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

    if (pos < -1) {
        printf("invalid position.\n");
        return NULL;
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

int list_insert(linklist H, data_t value, int pos) {
    linklist preNode, newNode;
    if (H == NULL) {
        printf("H is NULL\n");
        return -1;
    }
    // 1. locate the node of previous one
    preNode = list_get(H, pos - 1);
    if (preNode == NULL) return -1;

    // 2. new node
    if ((newNode = (linklist)malloc(sizeof(listnode))) == NULL) {
        printf("Malloc failed\n");
        return -1;
    }
    newNode->data = value;

    // 3. link the two sides of the newNode.
    newNode->next = preNode->next;
    preNode->next = newNode;

    return 0;
}

int list_delete(linklist H, int pos) {
    linklist preNode, temp;
    if (H == NULL) {
        printf("H is NULL\n");
        return -1;
    }

    // locate the node of previous one
    preNode = list_get(H, pos - 1);
    if (preNode == NULL) return -1;
    if (preNode->next == NULL) {
        printf("position is out of range.\n");
        return -1;
    }

    // update
    temp = preNode->next;
    preNode->next = temp->next;
    // free memory space.
    printf("free:%d\n", temp->data);
    free(temp);
    temp = NULL;

    return 0;
}
int free_tail(linklist H) {
    linklist p;
    if (H == NULL) {
        printf("H is NULL\n");
        return -1;
    }

    if (H->next == NULL) {
        printf("no data in the list");
        return -1;
    }

    p = H;
    while (p->next->next != NULL) {
        p = p->next;
    }

    if (p->next != NULL) free(p->next);
    p->next = NULL;

    return 0;
}

int free_all(linklist H) {
    linklist p, q;
    if (H == NULL) {
        printf("H is NULL\n");
        return -1;
    }
    p = H;
    printf("free:");
    while (p->next != NULL) {
        q = p;
        p = p->next;
        printf("%d ", q->data);
        free(q);
        q = NULL;
    }
    printf("%d ", p->data);
    free(p);
    p = NULL;
    puts("");

    return 0;
}

int list_headinsert(linklist H, linklist temp) {
    temp->next = H->next;
    H->next = temp;
    return 0;
}

int list_reverse(linklist H) {
    linklist p, temp;
    if (H == NULL) {
        printf("H is NULL\n");
        return -1;
    }

    if (H->next == NULL || H->next->next == NULL) {
        return 0;
    }

    p = H->next->next;
    H->next->next = NULL;

    while (p != NULL) {
        temp = p;
        p = p->next;
        list_headinsert(H, temp);
    }

    return 0;
}

linklist list_adjmax(linklist H) {
    if (H == NULL) {
        printf("H is NULL\n");
        return NULL;
    }

    if (H->next == NULL || H->next->next == NULL) {
        printf("Elements are less than 2.\n");
        return NULL;
    }

    linklist p = H->next;
    linklist r = p;
    data_t maxsum = p->data + p->next->data;

    while (p->next->next != NULL) {
        p = p->next;
        if ((p->data + p->next->data) > maxsum) {
            maxsum = p->data + p->next->data;
            r = p;
        }
    }

    return r;
}

int list_merge(linklist H1, linklist H2) {
    linklist p, q, r;

    if (H1 == NULL || H2 == NULL) {
        printf("List H1 or H2 is NULL\n");
        return -1;
    }

    r = H1;
    p = H1->next;
    q = H2->next;
    free(H2);
    H2 = NULL;

    while (p && q) {
        if (p->data <= q->data) {
            r->next = p;
            r = r->next;
            p = p->next;
        } else {
            r->next = q;
            r = r->next;
            q = q->next;
        }
    }

    if (p == NULL) {
        r->next = q;
    } else {
        r->next = p;
    }

    return 0;
}