//
// Created by yarnom on 26/05/23.
//

#ifndef SINGLE_LINKED_LIST_LINKEDLIST_H
#define SINGLE_LINKED_LIST_LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node , *NodePtr;

typedef struct {
    int size;
    NodePtr head;
    NodePtr tail;
}SingleLinkedList,*SingleLinkedListPtr;

NodePtr init_node(int data,NodePtr next);
SingleLinkedListPtr init_single_linked_list();

int size(SingleLinkedListPtr linked_list);
int is_empty(SingleLinkedListPtr linked_list);

void insert_to_head(SingleLinkedListPtr linked_list,int data);
void insert_to_tail(SingleLinkedListPtr linked_list,int data);
int insert_at(SingleLinkedListPtr linked_list,int data,int index);

int remove_head(SingleLinkedListPtr linked_list);
int remove_tail(SingleLinkedListPtr linked_list);
int remove_at(SingleLinkedListPtr linked_list,int index);

int index_of(SingleLinkedListPtr linked_list,int num);
int print_linked_list(SingleLinkedListPtr linked_list);

NodePtr peek_head(SingleLinkedListPtr linked_list);
NodePtr peek_tail(SingleLinkedListPtr linked_list);
#endif //SINGLE_LINKED_LIST_LINKEDLIST_H
