#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 300 // max amount of chars for user input string

int main (void) {

  // update
  printf("Update 1:\n");
  
  // Variables for user/char input
  int c, n;
  char input_str[MAX]; // user input string
  int b_slash = 0; // checks if the character entered is a '\'
  
  // Receive user input
  printf("Type in a word & press ENTER: \n");
  c = getchar();
  while (c != EOF && c!= 10 && n < MAX) {

    // Checks if char entered is a '\'
    if (c == 92) { b_slash = 1; }
    
    // Registers next char
    if (b_slash == 0) {
      input_str[n] = c;
      n++;
    } else {
      // Converts tab, new line, & space to whitespace
      if (c != 92) {
	b_slash = 0;
	if (c == 116 || c == 110 || c == 32) {	 
	  input_str[n] = ' ';
	} else {
	  input_str[n] = c;
	}
	n++;
      }
    }
    c = getchar();
  }
  
  char *s_ptr = input_str;
  char **n_tokens = tokenize(s_ptr);
  printf("Num Words: %d\n", count_words(s_ptr));
  printf("Now Printing Tokens:\n");
  print_tokens(n_tokens);
  free_tokens(n_tokens);
}
