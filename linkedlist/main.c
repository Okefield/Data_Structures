#include <stdio.h>
#include <time.h>
#include "linkedlist.h"


int main() {
    printf("einfuegung;zeitpush;zeitadd;zeitrm\n");

    int n = 10000;

    for (int i = 0; i < 4; i++) {

        node_t *head = NULL;
        clock_t t;

        t = clock();
        for (int j = 0; j < n; j++)
            ll_push(&head, (double)j);
        double tp = (double)(clock() - t) / CLOCKS_PER_SEC;

        double value;
        ll_pop(&head, &value);

        t = clock();
        for (int j = 0; j < n; j++)
            ll_rm(&head, 0);
        double tr = (double)(clock() - t) / CLOCKS_PER_SEC;

        t = clock();
        for (int j = 0; j < n; j++)
            ll_add(&head, 1.0, j);
        double ta = (double)(clock() - t) / CLOCKS_PER_SEC;

        ll_clear(&head);

        printf("%d;%f;%f;%f\n", n, tp, ta, tr);

        n*=10;


    }
    return 0;
}
