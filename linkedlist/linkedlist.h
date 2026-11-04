//
// Created by peter on 9/20/26.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H


#include <stdint.h>

typedef struct node {
    double data;
    struct node *next;
} node_t;

void ll_push(node_t ** head, double value);

int8_t ll_pop(node_t ** head, double *value);

void ll_add(node_t ** head, double value, int position);

int8_t ll_rm(node_t ** head, uint8_t position);

int8_t ll_clear(node_t ** head);

int8_t ll_to_array(node_t * head, double array[]);

uint16_t ll_getLength(node_t * head);

void ll_push_back(node_t **head, double value);

int8_t ll_pop_back(node_t **head, double *value);

int32_t ll_find(node_t *head, double value);

#endif //LINKEDLIST_LINKEDLIST_H
