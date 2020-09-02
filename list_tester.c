#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    struct linked_list* l;
    l = list_create();
    for(int i=0; i<5; i++){
        list_append(l, i);
    }
    list_print(l);
    list_insert(l, 99, 2);
    list_insert(l, -99, 5);
    list_print(l);
    list_remove(l, 0);
    list_remove(l, 3);
    list_print(l);
    printf("element at position 0: %d\n", list_get(l,0));
    printf("element at position 3: %d\n", list_get(l,3));
    printf("index of 99: %d\n", list_find(l, 99));
    printf("index of 0: %d\n", list_find(l,0));
    list_empty(l);
    list_insert(l, -2, 0);
    list_print(l);
    //printf("should give an error: ");
    //list_insert(l, 0, 2);
    list_print(l);
    //printf("Test");
    list_empty(l);
    free(l);
}