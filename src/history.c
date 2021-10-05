#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history() {
  List list;
  List *ptr_list = &list;
  return ptr_list;
}

void add_history(List *list, char *str) {
  Item new_item;
  new_item.str = str;
  new_item.next = NULL;
  list->root = &new_item;
  printf("String in Root: %s\n", list->root->str);
}

char *get_history(List *list, int id) {

}

void print_history(List *list) {
  printf("String in Root 2: %s\n", list->root->str);
}

void free_history(List *list) {

}
