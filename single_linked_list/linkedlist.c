#include "linkedlist.h"

NodePtr
init_node(int data,NodePtr next){
    NodePtr new_node = (NodePtr)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = next;

    return new_node;
}

SingleLinkedListPtr
init_single_linked_list(){
    SingleLinkedListPtr new_linked_list =
            (SingleLinkedListPtr)malloc(sizeof(SingleLinkedList));

    new_linked_list->size = 0;
    new_linked_list->head = NULL;
    new_linked_list->tail = NULL;

    return new_linked_list;
}

int
size(SingleLinkedListPtr linked_list){
    return linked_list->size;
}

int
is_empty(SingleLinkedListPtr linked_list){
    if(!size(linked_list)){
        return 1;
    }
    return 0;
}

void
insert_to_head(SingleLinkedListPtr linked_list,int data){
    if(is_empty(linked_list)){
        NodePtr new_node = init_node(data,NULL);
        linked_list->head =new_node;
        linked_list->tail = new_node;
    }else{
        NodePtr new_node = init_node(data,linked_list->head);
        linked_list->head = new_node;
    }

    linked_list->size += 1;
}

void
insert_to_tail(SingleLinkedListPtr linked_list,int data){
    if(is_empty(linked_list)){
        NodePtr new_node = init_node(data,NULL);
        linked_list->head =new_node;
        linked_list->tail = new_node;
    }else{
        NodePtr new_node = init_node(data,NULL);
        linked_list->tail->next = new_node;
        linked_list->tail = new_node;
    }

    linked_list->size += 1;
}

int
insert_at(SingleLinkedListPtr linked_list,int data,int index){

    if(index < 0 || index > size(linked_list)){
        perror("索引必须大于零且小于当前链表长度");
        return -1;
    }
    if(index == 0){
        insert_to_head(linked_list,data);
    }
    else if(index == size(linked_list) - 1){
        insert_to_tail(linked_list,data);
    }
    else{
        NodePtr iterator = linked_list->head;
        int counter = 0;

        while(iterator != linked_list->tail->next && counter != index - 1){
            counter++;
            iterator = iterator->next;
        }

        NodePtr new_node = init_node(data,iterator->next);
        iterator->next = new_node;

    }

    linked_list->size++;
    return 0;
}

int
remove_head(SingleLinkedListPtr linked_list){
    if(is_empty(linked_list)){
        perror("该链表为空");
        return -1;
    }

    NodePtr temp = linked_list->head;
    linked_list->head = linked_list->head->next;

    free(temp);
    linked_list->size -= 1;
    return 0;
}

int
remove_tail(SingleLinkedListPtr linked_list){
    if(is_empty(linked_list)){
        perror("该链表为空");
        return -1;
    }

    NodePtr iterator = linked_list->head;

    while(iterator->next != linked_list->tail){
        iterator = iterator->next;
    }

    NodePtr temp = iterator->next;
    linked_list->tail = iterator;
    free(temp);
    linked_list->size -= 1;

    return 0;
}


int
remove_at(SingleLinkedListPtr linked_list,int index){
    if(is_empty(linked_list)){
        perror("该链表为空");
        return -1;
    }

    if(index == 0){
        remove_head(linked_list);
    }
    else if(index == size(linked_list) - 1){
        remove_tail(linked_list);
    }else{
        NodePtr iterator = linked_list->head;
        int counter = 0;

        while(counter != index - 1){
            counter++;
            iterator = iterator->next;
        }

        NodePtr temp = iterator->next;
        iterator->next = temp->next;
        free(temp);
        linked_list->size -= 1;

    }

    return 0;
}


int
index_of(SingleLinkedListPtr linked_list,int num){
    NodePtr iterator = linked_list->head;
    int counter = 0;
    while(iterator != linked_list->tail->next){
        if(num == iterator->data){
            return counter;
        }
        iterator = iterator->next;
        counter++;
    }
    return -1;
}
int
print_linked_list(SingleLinkedListPtr linked_list){
    if(is_empty(linked_list)){
        printf("[]\n");
        return -1;
    }
    for (NodePtr iterator = linked_list->head;iterator != linked_list->tail->next;iterator=iterator->next) {
        if(iterator == linked_list->head){
            printf("[ ");
        }
        if(iterator!=linked_list->tail){
            printf("%d -> ",iterator->data);
        }
        if(iterator==linked_list->tail){
            printf("%d ]\n",iterator->data);
        }

    }
    printf("Size:%d\n",linked_list->size);
    return 0;
}

NodePtr
peek_head(SingleLinkedListPtr linked_list){
    return linked_list->head;
}

NodePtr
peek_tail(SingleLinkedListPtr linked_list){
    return linked_list->tail;
}

int
main(){
    SingleLinkedListPtr linked_list = init_single_linked_list();
    printf("Insert Test\n");
    insert_to_head(linked_list,1);
    insert_to_tail(linked_list,2);
    insert_to_head(linked_list,3);
    insert_to_tail(linked_list,4);
    print_linked_list(linked_list);

    insert_at(linked_list,5,1);
    insert_at(linked_list,6,2);

    print_linked_list(linked_list);

    insert_to_head(linked_list,7);
    insert_to_head(linked_list,8);
    print_linked_list(linked_list);

    printf("Remove Test\n");
    remove_tail(linked_list);
    print_linked_list(linked_list);
    remove_head(linked_list);
    print_linked_list(linked_list);

    remove_at(linked_list,5);
    print_linked_list(linked_list);

    remove_at(linked_list,1);
    print_linked_list(linked_list);
    printf("IndexOf, Test\n");
    printf("%d",index_of(linked_list,7));

}