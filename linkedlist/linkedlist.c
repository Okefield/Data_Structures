//
// Created by peter on 9/20/26.
//

#include "linkedlist.h"

#include <stdint.h>
#include <stdlib.h>


void ll_push(node_t ** head, double value) {
    node_t* newnode ;
    newnode = (node_t*) malloc(sizeof(node_t));
    if (newnode != NULL) {
        newnode->data = value;
        if (*head == NULL) {
            *head = newnode;
        }else {
            newnode->next = *head;
            *head = newnode;
        }
    }
}

uint8_t ll_pop(node_t ** head, double* value) {
    if (*head == NULL) {
        return -1;
    }
    node_t* temp = (*head)->next;
    *value = (*head)->data;
    free(*head);
    *head = temp;
    return 0;
}

void ll_add(node_t * head, double value, int position) {
    node_t* newnode = (node_t*) malloc(sizeof(node_t));
    if (newnode != NULL) {
        if (position == 0) {
            ll_push(&head, value);
        }else {
            node_t* temp;
            if (position > 1) {
                temp = head->next;
                for (int i = 0; i < position -1; i++) {
                    temp = temp->next;
                }
            }else
                temp = head;

            newnode->data = value;
            newnode->next = temp->next;
            temp->next = newnode;

        }
    }


}

uint8_t ll_rm(node_t * head, uint8_t position) {
    if (position == 0) {
        ll_pop(&head, NULL);
        return 0;
    }else {
        node_t* temp;
        if (position > 1) {
            temp = head->next;
            for (int i = 0; i < position -1; i++) {
                if (temp->next == NULL) {
                    return -1;
                }
                temp = temp->next;
            }
        }else
            temp = head;

        node_t* delete = temp->next;
        temp->next = delete->next;
        free(delete);
        return 0;
    }

}

uint8_t ll_clear(node_t *head) {
    node_t* current = head;
    node_t* next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    return 0;
}

uint8_t ll_to_array(node_t * head, double array[]) {
    if (head == NULL) {
        return -1;
    }else {
        node_t* temp = head;
        for (int i = 0; i < ll_getLength(head); i++) {
            array[i] = temp->data;
            temp = temp->next;
        }
    }
    return 0;
}



uint16_t ll_getLength(node_t * head) {
    int_fast8_t i = 1;
    node_t* temp = head;
    while (temp->next != NULL) {
        i++;
        temp = temp->next;
    }
    return i;
}
