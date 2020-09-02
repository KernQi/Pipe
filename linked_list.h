/* A circular doubly-linked list of integers. */




#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct linked_list_node{
    int data;
    struct linked_list_node* next;
    struct linked_list_node* prev;
};

struct linked_list{
    struct linked_list_node* head;
    int size;
};

// initializes an empty linked list
struct linked_list* list_create();
    

// adds a an element to the end of the list
// takes O(1) time; updates size
void list_append(struct linked_list* list, int elem);

// adds an element at the specified position
// afterwards, elem will appear at index pos; updates size
// exits if pos is out of bounds
void list_insert(struct linked_list* list, int elem, int pos);

// returns the element at the specified position
// exits if pos is out of bounds
int list_get(struct linked_list* list, int pos);

// deletes the element at the specified position and returns it
// frees the memory used by the node; updates size
// exits if pos is out of bounds
void list_remove(struct linked_list* list, int pos);

// returns the first index at which an element occurs
// returns -1 if the element is not in the list
int list_find(struct linked_list* list, int elem);

// prints each element, separated by ", "
// starts with '[', ends with "]\n"
void list_print(struct linked_list* list);

// removes all elements from the list
// frees node memory; sets size to 0
void list_empty(struct linked_list* list);

#endif // LINKED_LIST_H