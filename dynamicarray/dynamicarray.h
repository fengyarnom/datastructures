//
// Created by yarnom on 26/05/23.
//

#ifndef DYNAMICARRAY_DYNAMICARRAY_H
#define DYNAMICARRAY_DYNAMICARRAY_H

typedef struct{
    int* arr_ptr;
    int len;        // length user thinks array is
    int capacity;   // Actual array size
}DynamicArray,*DynamicArrayPtr;


DynamicArrayPtr dynamic_array_init(int capacity);

int get(DynamicArrayPtr dynamic_array,int index);
int set(DynamicArrayPtr dynamic_array, int index, int num);
void add(DynamicArrayPtr dynamic_array,int num);
int remove_at(DynamicArrayPtr dynamic_array, int rm_index);
int remove_elem(DynamicArrayPtr dynamic_array,int elem);

void print_dynamic_list(DynamicArrayPtr dynamic_array);

int size(DynamicArrayPtr dynamic_array);
int is_empty(DynamicArrayPtr dynamic_array);

int contains(DynamicArrayPtr dynamic_array, int elem);
int index_of(DynamicArrayPtr dynamic_array , int need_to_find);

#endif //DYNAMICARRAY_DYNAMICARRAY_H
