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

uint8_t dll_add(DoubleLinkedList* list, double data, int pos) {
    if (list == NULL || pos < 0 || pos > list->size) {
        return -1;
    }

    if (pos == 0) {
        return dll_push(list, data);
    }

    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = data;

    if (pos == list->size) {
        new_node->next = NULL;
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
        list->size++;
        return 0;
    }


    node_t* current;
    if (pos < list->size / 2) {
        current = list->head;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
    } else {
        current = list->tail;
        for (int i = list->size - 1; i > pos; i--) {
            current = current->prev;
        }
    }


    new_node->next = current;
    new_node->prev = current->prev;
    current->prev->next = new_node;
    current->prev = new_node;

    list->size++;
    return 0;
}


uint8_t dll_remove(DoubleLinkedList* list, int pos) {
    if (list == NULL || list->size == 0 || pos < 0 || pos >= list->size) {
        return -1;
    }


    if (pos == 0) {
        double temp;
        dll_pop(list, &temp);
        return 0;
    }


    if (pos == list->size - 1) {
        node_t* temp = list->tail;
        list->tail = temp->prev;
        list->tail->next = NULL;
        free(temp);
        list->size--;
        return 0;
    }


    node_t* current;
    if (pos < list->size / 2) {
        current = list->head;
        for (int i = 0; i < pos; i++) {
            current = current->next;
        }
    } else {
        current = list->tail;
        for (int i = list->size - 1; i > pos; i--) {
            current = current->prev;
        }
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    free(current);
    list->size--;
    return 0;
}

uint8_t dll_toarray(DoubleLinkedList* list, double array[]) {
    if (list == NULL || array == NULL) return 0;

    node_t* current = list->head;
    int i = 0;
    while (current != NULL) {
        array[i++] = current->data;
        current = current->next;
    }

    return 1;
}




