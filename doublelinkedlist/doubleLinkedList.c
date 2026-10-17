//
// Created by peter on 10/7/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "doubleLinkedList.h"

DoubleLinkedList* createDoubleLinkedList() {
    DoubleLinkedList* list = (DoubleLinkedList*) malloc(sizeof(DoubleLinkedList));
    list->tail = NULL;
    list->head = list->tail;
    list->size = 0;
    return list;
}

uint8_t dll_push(DoubleLinkedList* list, double data) {
    if (list->tail == NULL && list->head == NULL) {
        node_t* newNode = (node_t*) malloc(sizeof(node_t));
        newNode->data = data;
        newNode->next = list->head;
        list->head = newNode;
    }
}



