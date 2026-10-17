#include <stdio.h>
#include <doubleLinkedList.h>

#include "doubleLinkedList.h"

int main(void) {
    DoubleLinkedList* list1 = createDoubleLinkedList();
    dll_push(list1, 1);
    dll_push(list1, 2);
}
