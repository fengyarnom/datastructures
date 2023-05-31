//
// Created by yarnom on 31/05/23.
//
#include "stack.h"

NodePtr
init_node(int data,NodePtr next){
    NodePtr new_node = (NodePtr)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = next;

    return new_node;
}

StackPtr
init_stack(){
    StackPtr new_stack =
            (StackPtr)malloc(sizeof(Stack));

    new_stack->size = 0;
    new_stack->head = NULL;
    new_stack->tail = NULL;

    return new_stack;
}

int
size(StackPtr stack){
    return stack->size;
}

int
is_empty(StackPtr StackPtr){
    if(!size(StackPtr)){
        return 1;
    }
    return 0;
}

void
push(StackPtr stack,int data){
    if(is_empty(stack)){
        NodePtr new_node = init_node(data,NULL);
        stack->head =new_node;
        stack->tail = new_node;
    }else{
        NodePtr new_node = init_node(data,stack->head);
        stack->head = new_node;
    }

    stack->size += 1;
}

int
pop(StackPtr stack){
    if(is_empty(stack)){
        perror("该栈为空");
        return -1;
    }

    NodePtr temp = stack->head;
    stack->head = stack->head->next;

    free(temp);
    stack->size -= 1;
    return 0;
}

int
print_stack(StackPtr stack){
    if(is_empty(stack)){
        printf("[]\n");
        return -1;
    }
    for (NodePtr iterator = stack->head;iterator != stack->tail->next;iterator=iterator->next) {
        if(iterator == stack->head){
            printf("[ ");
        }
        if(iterator!=stack->tail){
            printf("%d -> ",iterator->data);
        }
        if(iterator==stack->tail){
            printf("%d ]\n",iterator->data);
        }

    }
    printf("Size:%d\n",stack->size);
    return 0;
}

NodePtr
peek(StackPtr stack){
    if(is_empty(stack)){
        perror("该栈为空");
    }
    return stack->head;
}

int
main(){
    StackPtr stack = init_stack();
    push(stack,5);
    push(stack,10);
    push(stack,66);

    print_stack(stack);

    pop(stack);
    print_stack(stack);

    printf("%d\n", peek(stack)->data);
    return 0;
}
