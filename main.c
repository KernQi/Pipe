#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

int main(){
    struct linked_list* l;
    l = list_create();
    for(int i=0; i<5; i++){
        list_append(l, i);
    }

    list_insert(l, 10, 1);
    list_remove(l, 2);
    printf("%d\n", list_get(l, 0));
    printf("%d\n", list_get(l, 1));
    printf("%d\n", list_get(l, 2));
    printf("%d\n", list_get(l, 3));
    printf("%d\n", list_get(l, 4));
    printf("%d\n", list_get(l, 5));
    printf("%d\n", list_get(l, 6));

    //list_empty(l);
    //free(l);
}