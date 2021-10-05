#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history() {
  List list;
  list.root = NULL;
  List *ptr_list = &list;
  return ptr_list;
}

void add_history(List *list, char *str) {
  Item new_item;// = (Item) malloc(sizeof(struct Item));
  printf("Size of Item: %d\n", sizeof(Item));
  new_item.str = str;

  if (list->root == NULL) {
    new_item.next = NULL;
    list->root = &new_item;
    printf("Root was NULL\n");
  } else {
    new_item.next = NULL;
    printf("Root was NOT NULL\n");
    new_item.next = list->root;
    list->root->next = &new_item;
  }
  printf("String in Root: %s\n", list->root->str);
}

char *get_history(List *list, int id) {

}

void print_history(List *list) {
  printf("Str in Root: %s\n", list->root->str);
  printf("Str in Root Next: %s\n", list->root->next->str);
  printf("Root: %x\n", list->root);
}

void free_history(List *list) {

}
