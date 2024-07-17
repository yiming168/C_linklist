#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

void test_get();
void test_insert();
void test_delete();
void test_reverse();
void test_adjmax();

int main(int argc, char const *argv[]) {
    linklist H1, H2;
    int a[] = {1, 4, 6, 9, 10};
    int b[] = {2, 4, 16, 18, 30};
    size_t i;
    H1 = list_create();
    if (H1 == NULL) return -1;

    H2 = list_create();
    if (H2 == NULL) {
        free(H1);
        return -1;
    }

    for (i = 0; i < sizeof(a) / sizeof(int); i++) {
        list_tail_insert(H1, a[i]);
    }

    for (i = 0; i < sizeof(b) / sizeof(int); i++) {
        list_tail_insert(H2, b[i]);
    }

    puts("H1 before merge");
    list_show(H1);
    puts("H2 before merge");
    list_show(H2);

    list_merge(H1, H2);
    puts("H1 after merge:");
    list_show(H1);
    free_all(H1);

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

void test_delete() {
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

    list_delete(H, -4);  // 1 3 5 7
    list_show(H);

    free_all(H);

    return;
}
void test_reverse() {
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

    list_reverse(H);  // 1 3 5 7
    list_show(H);

    free_all(H);

    return;
}

void test_adjmax() {
    linklist H, p;
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

    p = list_adjmax(H);  // 1 3 5 7 9 8 6 4 2
    if (p != NULL && p->next != NULL) {
        printf("adjacent two numbers %d, %d have the maximum sum of %d.\n",
               p->data, p->next->data, p->data + p->next->data);
    }

    free_all(H);
}