#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

struct linked_list* list_create(){

    struct linked_list* new_list = (struct linked_list*)malloc(sizeof(struct linked_list));

    new_list->head = NULL;
    new_list->size = 0;

    return new_list;

}

void list_append(struct linked_list* list, int elem){
    struct linked_list_node* node = (struct linked_list_node*)malloc(sizeof(struct linked_list_node));

    node->data = elem;

    if(list->size == 0){
      list->head = node;
      list->size ++;
      node->prev = node;
      node->next = node;
    }
    else{
      struct linked_list_node* temp = list->head->prev;
      temp->next = node;
      node->prev = temp;
      node->next = list->head;
      list->head->prev = node;
      list->size++;
    }
}

void list_insert(struct linked_list* list, int elem, int pos){
  if(pos > list->size){
    printf("Invalid insert");
    exit(1);
  }
  else if(pos == list->size){
    list_append(list, elem);
  }
  else{
      struct linked_list_node* node = (struct linked_list_node*)malloc(sizeof(struct linked_list_node));
    node->data = elem;
    struct linked_list_node* temp = list-> head;
    for(int i = 0; i < pos; i++){
      temp = temp -> next;
    }
    if(pos == 0){
      list->head = node;
    }
    node->prev = temp->prev;
    node->prev->next = node;
    node->next = temp;
    temp->prev = node;

    list->size++;
  }
}

// returns the element at the specified position
// exits if pos is out of bounds
int list_get(struct linked_list* list, int pos){
  if(pos >= list->size){
    exit(1);
  }
  struct linked_list_node* current = list-> head;
    
  for(int i = 0; i < pos; i++){
    current = current -> next;
  }
  return current->data;
}

void list_remove(struct linked_list* list, int pos){
  if(pos >= list->size){
    exit(1);
  }
  struct linked_list_node* temp = list-> head;
    
    for(int i = 0; i < pos; i++){
      temp = temp -> next;
    }
  if(list->size > 1){
    if(pos == 0){
      list->head = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
  }
  else{
    list->head =NULL;
    free(temp);
  }
  list->size--;
}

// returns the first index at which an element occurs
// returns -1 if the element is not in the list
int list_find(struct linked_list* list, int elem){
  struct linked_list_node* temp = list->head;
  for(int i = 0; i < list->size; i++){
    if(temp->data == elem){
      return i;
    }
    else{
      temp = temp->next;
    }
  }
  return -1;
}

// prints each element, separated by ", "
// starts with '[', ends with "]\n"
void list_print(struct linked_list* list){
  printf("[");
  for(int i = 0; i < list->size - 1; i++){
    printf("%d, ", list_get(list, i));
  }
  printf("%d]\n", list_get(list, list->size - 1));
}

// removes all elements from the list
// frees node memory; sets size to 0
void list_empty(struct linked_list* list){
  struct linked_list_node* temp = list->head;
  for(int i = 0; i < list->size; i++){
    struct linked_list_node* next = temp->next;
    free(temp);
    temp = next;
  }
  list->size = 0;
}