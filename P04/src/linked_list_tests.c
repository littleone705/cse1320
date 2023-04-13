#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "linked_list_tests.h"
//#include "run_test.h"

Node *create_node(void *data) {
    Node *n = calloc(1, sizeof(Node));
    n->data = data;

    return n;
}

void insert_node(Node **head, Node *new_node, int position) {
    Node *prev = NULL;
    Node *current = *head;
    int cur_pos = 0;

    while (current != NULL && cur_pos < position) {
        cur_pos++;
        prev = current;
        current = current->next;
    }

    if (current == *head) {
        new_node->next = current;
        *head = new_node;
    } else {
        new_node->next = current;
        prev->next = new_node;
    }
}

void release(Node *n) {
    if (n != NULL) {
        Node *temp = n->next;
        free(n->data);
        free(n);
        release(temp);
    }
}

void linked_list_insert_sequential_start(int num_samples, int sample_size){
    Node *head = NULL;

    for (int i = 0; i < num_samples; i++) {
        void *sample = calloc(1, sample_size);
        Node *new = create_node(sample);
        insert_node(&head, new, 0);
        }
        release(head);
}

void linked_list_insert_sequential_end(int num_samples, int sample_size){
    Node *head = NULL;

    for (int i = 0; i < num_samples; i++) {
        void *sample = calloc(1, sample_size);
        Node *new = create_node(sample);
        insert_node(&head, new, i);
        }
        release(head);
}

void linked_list_insert_random(int num_samples, int sample_size){
    Node *head = NULL;

    for (int i = 0; i < num_samples; i++) {
        void *sample = calloc(1, sample_size);
        Node *new = create_node(sample);
        int idx = rand() % (i + 1);
        insert_node(&head, new, idx);
        }
        release(head);
}