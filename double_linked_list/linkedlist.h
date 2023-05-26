//
// Created by yarnom on 26/05/23.
//

#ifndef DATASTRUCTURES_LINKEDLIST_H
#define DATASTRUCTURES_LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* pre;
}Node , *NodePtr;

typedef struct {
    int size;
    NodePtr head;
    NodePtr tail;
}DoubleLinkedList,*DoubleLinkedListPtr;

NodePtr init_node(int data,NodePtr pre,NodePtr next);
DoubleLinkedListPtr init_double_linked_list();

int size(DoubleLinkedListPtr linked_list);
int is_empty(DoubleLinkedListPtr linked_list);

void insert_to_head(DoubleLinkedListPtr linked_list,int data);
void insert_to_tail(DoubleLinkedListPtr linked_list,int data);
int insert_at(DoubleLinkedListPtr linked_list,int data,int index);

int remove_head(DoubleLinkedListPtr linked_list);
int remove_tail(DoubleLinkedListPtr linked_list);
int remove_at(DoubleLinkedListPtr linked_list,int index);

int index_of(DoubleLinkedListPtr linked_list,int num);
int print_linked_list(DoubleLinkedListPtr linked_list);

NodePtr peek_head(DoubleLinkedListPtr linked_list);
NodePtr peek_tail(DoubleLinkedListPtr linked_list);
#endif //DATASTRUCTURES_LINKEDLIST_H
