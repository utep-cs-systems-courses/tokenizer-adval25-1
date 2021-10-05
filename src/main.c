#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 300

int main (void) {
  List *n_list;
  n_list = init_history();
  add_history(n_list, "hey guy");
  //add_history(n_list, "alina");
  print_history(n_list);
  
  /*
  int c, n;
  char input_str[MAX];

  printf("Type in a word & press ENTER: \n");
  
  c = getchar();
  while (c != EOF && c!= 10 && n < MAX) {
    input_str[n] = c;
    n++;
    c = getchar();
  }
  
  char *s_ptr = input_str;
  char **n_tokens = tokenize(s_ptr);
  printf("Now Printing Tokens:\n");
  print_tokens(n_tokens);
  free_tokens(n_tokens);
  */
}
