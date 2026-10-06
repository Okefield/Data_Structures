#include <stdio.h>

#include "linkedlist.h"

int main(void) {
    node_t *head = NULL;

    ll_push(&head, 5.15);
    ll_push(&head, 10.98);
    ll_add(head, 15.0, 1);
    ll_push(&head, 26.75);

    if(ll_rm(head, 2) == -1) {
        printf("error\n");
    };

    for (int i = 1; i < 5; i++) {
        double value = 0;
        if (ll_pop(&head, &value)  == 0)
            printf("%f\n", value);

    }

    ll_push(&head, 5.15);
    ll_push(&head, 10.98);

    double array[ll_getLength(head)];
    ll_to_array(head, array);
    printf("\n");

    for (int i = 0; i < ll_getLength(head); i++) {
        printf("%f\n", array[i]);
    }


    ll_clear(head);
    return 0;
}
