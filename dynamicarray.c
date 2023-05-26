#include <stdio.h>
#include <stdlib.h>
#include "dynamicarray.h"

DynamicArrayPtr
dynamic_array_init(int capacity){
    if(capacity < 0){
        perror("不能设置数值小于零的数组长度");
    }

    DynamicArrayPtr new_array =
            (DynamicArrayPtr)malloc(sizeof(DynamicArray));

    new_array->arr_ptr = (int* )malloc(sizeof(int)*capacity);
    new_array->len = 0;
    new_array->capacity = capacity;

    return new_array;
}

int
get(DynamicArrayPtr dynamic_array,int index){
    if(index < 0 || index > dynamic_array->len){
        perror("索引不能小于零或者大于动态数组当前长度");
        return -1;
    }

    return dynamic_array->arr_ptr[index];
}

int
set(DynamicArrayPtr dynamic_array, int index, int num){
    if(index < 0 || index > dynamic_array->len){
        perror("索引不能小于零或者大于动态数组当前长度");
        return -1;
    }

    dynamic_array->arr_ptr[index] = num;

    return 0;
}

int
size(DynamicArrayPtr dynamic_array){
    return dynamic_array->len;
}

int
is_empty(DynamicArrayPtr dynamic_array){
    if(size(dynamic_array)){
        return 1;
    }

    return 0;
}


void
add(DynamicArrayPtr dynamic_array,int num){
    if((dynamic_array->len + 1) == dynamic_array->capacity){

        int* new_arr_ptr = malloc(sizeof(int) * (dynamic_array->capacity) * 2);

        for (int i = 0; i < dynamic_array->len; ++i) {
            new_arr_ptr[i] = dynamic_array->arr_ptr[i];
        }

        dynamic_array->capacity = dynamic_array->capacity * 2;

        free(dynamic_array->arr_ptr);
        dynamic_array->arr_ptr = new_arr_ptr;
    }

    dynamic_array->arr_ptr[dynamic_array->len] = num;
    dynamic_array->len += 1;

}

int
remove_at(DynamicArrayPtr dynamic_array, int rm_index){
    if(rm_index < 0 || rm_index > dynamic_array->len){
        perror("索引不能小于零或者大于动态数组当前长度");
        return -1;
    }

    int* new_arr_ptr = (int *)malloc(dynamic_array->len - 1);
    for (int i = 0,j=0; i < dynamic_array->len; ++i,++j) {
        if(i == rm_index){
            j -= 1;
            continue;
        }

        new_arr_ptr[j] = dynamic_array->arr_ptr[i];


    }
    free(dynamic_array->arr_ptr);
    dynamic_array->arr_ptr = new_arr_ptr;

    dynamic_array->len -= 1;
    dynamic_array->capacity -= 1;

    return 0;
}


void
print_dynamic_list(DynamicArrayPtr dynamic_array){

    for (int i = 0; i < dynamic_array->len; ++i) {
        if(i == 0){
            printf("[");
        }
        printf(" %d", get(dynamic_array,i));

        if(i == (dynamic_array->len - 1)){
            printf(" ]");
        }
    }
    printf("\nlen:%d capacity:%d\n", dynamic_array->len,dynamic_array->capacity);

}

int
index_of(DynamicArrayPtr dynamic_array , int need_to_find){
    for (int i = 0; i < dynamic_array->len; ++i) {
        if(need_to_find == dynamic_array->arr_ptr[i]){
            return i;
        }
    }

    return -1;

}

int
contains(DynamicArrayPtr dynamic_array, int elem){
    int index = index_of(dynamic_array,elem);
    if(index == -1){
        return -1;
    }

    return index;
}

int
remove_elem(DynamicArrayPtr dynamic_array,int elem){
    int index = index_of(dynamic_array,elem);
    if(index == -1){
        return -1;
    }

    remove_at(dynamic_array,index);

    return 0;
}

int
main(){
    DynamicArrayPtr dynamic_array = dynamic_array_init(3);
    add(dynamic_array,2);
    add(dynamic_array,88);
    add(dynamic_array,7);
    add(dynamic_array,8);

    set(dynamic_array,2,5);
    print_dynamic_list(dynamic_array);

    remove_at(dynamic_array,2);
    print_dynamic_list(dynamic_array);

    add(dynamic_array,9);
    add(dynamic_array,80);

    print_dynamic_list(dynamic_array);
    remove_elem(dynamic_array,9);
    print_dynamic_list(dynamic_array);

    add(dynamic_array,87);
    add(dynamic_array,110);
    add(dynamic_array,986);
    add(dynamic_array,100);
    add(dynamic_array,0);
    add(dynamic_array,445);
    print_dynamic_list(dynamic_array);

    printf("%d", contains(dynamic_array,110));
    return 0;
}