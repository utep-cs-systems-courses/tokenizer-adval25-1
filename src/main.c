#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 300

int main (void) {
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
}

int space_char(char a) {
  // Checks if a is a space(32), tab(9), or new line(10) character
  if (a == 32 || a == 9 || a == 10) {
    return 1;
  } else {
    return 0;
  }
}

int non_space_char(char a) {
  int r = space_char(a) == 0 ? 1 : 0; // returns opposite of space_char()
  return r;
}

char *word_start(char *str) {
  // "Scan" string until you find a non-whitespace character
  int i = 0;
  while (space_char(*(str + i))) { i++; }
  
  return (str + i); 
}

char *word_end(char *str) {
  // Find the end of the current word (& stop scanning if at end of string)
  int i = 0;
  while(non_space_char(*(str + i)) == 1 && *(str + i) != 0) { i++; }
  return (str + i);
}

int count_words(char *str) {
  // Return 0 if there are no words on the string
  if (*(word_start(str)) == 0) { return 0; }
  
  // Count the number of words in a string
  // and exit loop once end of string is reached
  int num_words = 0; // we have at least 1 word if the function wasn't exited
  while (1) {
    str = word_start(str);
    if (*str == 0) { break; }
    str = word_end(str);
    num_words++;
  }
  
  return num_words;
}

char *copy_str(char *inStr, short len) {
  char *new_str = (char*) malloc(sizeof(char) * len);
  for (short i = 0; i < len; i++) {
    *(new_str + i) = *(inStr + i); // copy contents from inStr to new_str
  }
  return new_str;
}

char **tokenize(char *str) {
  short token_len = count_words(str) + 1; // length of array to be returned
  char **token = (char**) malloc(sizeof(char) * token_len);
  char *tmp_p1, *tmp_p2; // temporary pointers
  short w_len = 0; // distance between the 2 temp pointers (word length)
  for (int i = 0; i < token_len; i++) {
    if (i < token_len - 1) {
      tmp_p1 = word_start(str); 
      tmp_p2 = word_end(tmp_p1);
      w_len = (tmp_p2 - tmp_p1) * sizeof(*tmp_p1);
      str = tmp_p1;
      token[i] = copy_str(str, w_len);
      str = tmp_p2;
    } else {
      token[i] = "\0";
    }
  }
  return token;
}

void print_tokens(char **tokens) {
  int i = 0;
  while (tokens[i][0] != 0) { // exit program once you've reached end of tokens
    printf("%s\n", tokens[i]);
    i++;
  }
}

char *get_token(char **tokens, int id) {
  char *ptr = tokens[id];
  return ptr;
}

void free_tokens(char **tokens) {
  int i = 0;
  while (1) { 
    if (tokens[i][0] == 0) {
      free(tokens[i]);
      break;
    } else {
      free(tokens[i]);
    }
  }
  free(tokens);
}
