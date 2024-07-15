#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

int main(int argc, char const *argv[]) {
    linklist H;
    int value;
    linklist p;

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

    p = list_get(H, 4);  // 1 3 5 7
    if (p != NULL) printf("value = %d\n", p->data);

    return 0;
}
