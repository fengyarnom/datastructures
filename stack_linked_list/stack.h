//
// Created by yarnom on 31/05/23.
//

#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

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
}Stack,*StackPtr;

StackPtr init_stack();

int size(StackPtr stack);
int is_empty(StackPtr StackPtr);

void push(StackPtr stack,int data);
int pop(StackPtr stack);
int print_stack(StackPtr stack);
NodePtr peek(StackPtr stack);
#endif //DATASTRUCTURES_STACK_H
