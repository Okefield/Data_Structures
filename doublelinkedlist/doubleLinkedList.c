//
// Created by peter on 10/7/26.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "doubleLinkedList.h"

DoubleLinkedList* createDoubleLinkedList() {
    DoubleLinkedList* list = (DoubleLinkedList*) malloc(sizeof(DoubleLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

uint8_t dll_push(DoubleLinkedList* list, double data) {
    if (list == NULL) {
        return -1;
    }

    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (new_node == NULL) {
        return -1;
    }

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = list->head;

    if (list->head == NULL) {

        list->tail = new_node;
    } else {

        list->head->prev = new_node;
    }

    list->head = new_node;
    list->size++;

    return 0;
}

uint8_t dll_pop(DoubleLinkedList* list, double* data) {
    if (list == NULL || list-> size == 0) {
        return -1;
    }

    node_t* temp = list->head;
    *data = temp->data;

    list->head = temp->next;

    if (list->head == NULL) {
        list->tail = NULL;
    }else {
        list->head->prev = NULL;
    }

    free(temp);
    list->size--;

    return 0;
}

uint8_t dll_clear(DoubleLinkedList* list) {
    if (list == NULL) return -1;

    node_t* current = list->head;
    while (current != NULL) {
        node_t* next_node = current->next;
        free(current);
        current = next_node;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return 0;
}



