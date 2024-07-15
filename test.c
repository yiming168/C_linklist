#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

void test_get();
void test_insert();

int main(int argc, char const *argv[]) {
    linklist H;
    int value;

    H = list_create();
    if (H == NULL) {
        return -1;
    }

    printf("input:");
    while (1) {
        scanf("%d", &value);
        if (value == -1) break;
        list_tail_insert(H, value);
        printf("input:");
    }

    list_show(H);

    list_delete(H, -4);  // 1 3 5 7
    list_show(H);

    free_all(H);

    return 0;
}

void test_get() {
    linklist H;
    int value;
    linklist p;

    H = list_create();
    if (H == NULL) {
        return;
    }

    printf("input:");
    while (1) {
        scanf("%d", &value);
        if (value == -1) break;
        list_tail_insert(H, value);
        printf("input:");
    }

    list_show(H);

    p = list_get(H, 4);  // 1 3 5 7
    if (p != NULL) printf("value = %d ", p->data);

    return;
}

void test_insert() {
    linklist H;
    int value;

    H = list_create();
    if (H == NULL) {
        return;
    }

    printf("input:");
    while (1) {
        scanf("%d", &value);
        if (value == -1) break;
        list_tail_insert(H, value);
        printf("input:");
    }

    list_show(H);

    list_insert(H, 100, 0);  // 1 3 5 7
    list_show(H);

    return;
}