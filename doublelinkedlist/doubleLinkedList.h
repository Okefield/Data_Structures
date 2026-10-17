//
// Created by peter on 10/7/26.
//

#ifndef DOUBLELONKEDLIST_DOUBLELINKEDLIST_H
#define DOUBLELONKEDLIST_DOUBLELINKEDLIST_H

#endif //DOUBLELONKEDLIST_DOUBLELINKEDLIST_H

#include <stdint.h>

typedef struct node{
    double data;
    struct node* next;
    struct node* prev;
}node_t;

typedef struct {
    node_t* head;
    node_t* tail;
    int size;
} DoubleLinkedList;

DoubleLinkedList* createDoubleLinkedList();

uint8_t dll_pop(DoubleLinkedList* list, double* data);

uint8_t dll_push(DoubleLinkedList* list, double data);

uint8_t dll_add(DoubleLinkedList* list, double data, int pos);

uint8_t dll_remove(DoubleLinkedList* list, int pos);

uint8_t dll_clear(DoubleLinkedList* list);

uint8_t dll_toarray(DoubleLinkedList* list, double array[]);


