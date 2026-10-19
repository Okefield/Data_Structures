#include <stdio.h>

#include "doubleLinkedList.h"

int main(void) {
    DoubleLinkedList* list1 = createDoubleLinkedList();
    dll_push(list1, 1);
    dll_push(list1, 2);

    double data;
    for (int i = 0; i <= list1->size; i++) {
        dll_pop(list1, &data);
        printf("%lf\n", data);
        fflush(stdout);
    }

    dll_push(list1, 1);
    dll_push(list1, 2);

    dll_clear(list1);

}
