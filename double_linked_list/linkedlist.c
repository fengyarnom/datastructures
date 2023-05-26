//
// Created by yarnom on 26/05/23.
//
#include "linkedlist.h"
NodePtr
init_node(int data,NodePtr pre,NodePtr next){
    NodePtr new_node = (NodePtr)malloc(sizeof(Node));
    new_node->data = data;
    new_node->pre =pre;
    new_node->next = next;

    return new_node;
}

DoubleLinkedListPtr
init_double_linked_list(){
    DoubleLinkedListPtr new_linked_list =
            (DoubleLinkedListPtr)malloc(sizeof(DoubleLinkedList));

    new_linked_list->size = 0;
    new_linked_list->head = NULL;
    new_linked_list->tail = NULL;

    return new_linked_list;
}
int
size(DoubleLinkedListPtr linked_list){
    return linked_list->size;
}

int
is_empty(DoubleLinkedListPtr linked_list){
    if(!size(linked_list)){
        return 1;
    }
    return 0;
}

void
insert_to_head(DoubleLinkedListPtr linked_list,int data){
    if(is_empty(linked_list)){
        NodePtr new_node = init_node(data,NULL,NULL);
        linked_list->head =new_node;
        linked_list->tail = new_node;
    }else{
        NodePtr new_node = init_node(data,NULL,linked_list->head);
        linked_list->head = new_node;
    }

    linked_list->size += 1;
}

void
insert_to_tail(DoubleLinkedListPtr linked_list,int data){
    if(is_empty(linked_list)){
        NodePtr new_node = init_node(data,NULL,NULL);
        linked_list->head =new_node;
        linked_list->tail = new_node;
    }else{
        NodePtr new_node = init_node(data,linked_list->tail,NULL);
        linked_list->tail->next = new_node;
        linked_list->tail = new_node;
    }

    linked_list->size += 1;
}

int
insert_at(DoubleLinkedListPtr linked_list,int data,int index){

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
        // 使用二分法缩短插入时间
        if(index <= (size(linked_list) / 2)){
            NodePtr iterator = linked_list->head;
            int counter = 0;

            while(iterator != linked_list->tail->next && counter != index){
                counter++;
                iterator = iterator->next;
            }

            NodePtr new_node = init_node(data,iterator->pre,iterator);
            iterator->pre->next = new_node;
            iterator->pre = new_node;
        }else{
            NodePtr iterator = linked_list->tail;
            int counter = size(linked_list);

            while(iterator != linked_list->head->pre && counter != index){
                counter--;
                iterator = iterator->pre;
            }

            NodePtr new_node = init_node(data,iterator,iterator->next);
            iterator->next->pre = new_node;
            iterator->next = new_node;
        }

    }

    linked_list->size++;
    return 0;
}

int
remove_head(DoubleLinkedListPtr linked_list){
    if(is_empty(linked_list)){
        perror("该链表为空");
        return -1;
    }

    NodePtr temp = linked_list->head;
    linked_list->head = linked_list->head->next;
    linked_list->head->pre = NULL;

    free(temp);
    linked_list->size -= 1;
    return 0;
}


int
remove_tail(DoubleLinkedListPtr linked_list){
    if(is_empty(linked_list)){
        perror("该链表为空");
        return -1;
    }

    NodePtr temp = linked_list->tail;
    linked_list->tail = linked_list->tail->pre;
    linked_list->tail->next = NULL;
    free(temp);
    linked_list->size -= 1;

    return 0;
}

int
remove_at(DoubleLinkedListPtr linked_list,int index){
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
        // 使用二分法缩短删除时间
        if(index <= (size(linked_list) / 2)){
            NodePtr iterator = linked_list->head;
            int counter = 0;

            while(counter != index){
                counter++;
                iterator = iterator->next;
            }

            NodePtr temp = iterator;
            iterator->pre->next = iterator->next;
            iterator->next->pre = iterator->pre;
            free(temp);

        }else{
            NodePtr iterator = linked_list->head;
            int counter = size(linked_list);

            while(counter != index){
                counter--;
                iterator = iterator->pre;
            }

            NodePtr temp = iterator;
            iterator->pre->next = iterator->next;
            iterator->next->pre = iterator->pre;
            free(temp);
        }

        linked_list->size -= 1;
    }

    return 0;
}

int
index_of(DoubleLinkedListPtr linked_list,int num){
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
print_linked_list(DoubleLinkedListPtr linked_list){
    if(is_empty(linked_list)){
        printf("[]\n");
        return -1;
    }
    for (NodePtr iterator = linked_list->head;iterator != linked_list->tail->next;iterator=iterator->next) {
        if(iterator == linked_list->head){
            printf("[ ");
        }
        if(iterator!=linked_list->tail){
            printf("%d <-> ",iterator->data);
        }
        if(iterator==linked_list->tail){
            printf("%d ]\n",iterator->data);
        }

    }
    printf("Size:%d\n",linked_list->size);
    return 0;
}
NodePtr
peek_head(DoubleLinkedListPtr linked_list){
    return linked_list->head;
}

NodePtr
peek_tail(DoubleLinkedListPtr linked_list){
    return linked_list->tail;
}

int main(){
    DoubleLinkedListPtr linked_list = init_double_linked_list();
    insert_to_head(linked_list,7);
    insert_to_tail(linked_list,88);
    insert_to_tail(linked_list,98);
    insert_to_tail(linked_list,2);
    insert_to_tail(linked_list,5);
    insert_to_tail(linked_list,77);
    insert_to_tail(linked_list,100);
    print_linked_list(linked_list);

    insert_at(linked_list,40,4);
    print_linked_list(linked_list);

    remove_head(linked_list);
    remove_tail(linked_list);
    print_linked_list(linked_list);

    remove_at(linked_list,2);
    remove_at(linked_list,0);
    print_linked_list(linked_list);

}