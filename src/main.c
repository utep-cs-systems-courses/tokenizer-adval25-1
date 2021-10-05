#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAX 300 // max amount of chars for user input string

void main (void) {
  // Variables for user/char input
  int c, n;
  char input_str[MAX]; // user input string
  int b_slash = 0; // checks if the character entered is a '\'

  char cp = '2';
  int conv = (int)(cp - 48);
  printf("Converted Char: %d\n", conv);
  
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
  char *s_ptr = input_str; // Pointer to user input string
  char **n_tokens = tokenize(s_ptr);
  
  // Prompt user for further action
  printf("Type in a character to run a function: p- print_tokens, g- get_token, w- word_count\n");
  c = getchar();

  // Print Tokens
  if (c == 112) {
    printf("Now Printing Tokens:\n");
    print_tokens(n_tokens);
  } else if (c == 103) { // get_token
    int id = 0, num_words = count_words(s_ptr) - 1;
    printf("Press '[' or ']' keys to select index and press ENTER. Press EOF to get token:\n");
    printf("'[' - Decrease id, ']' - Increase id\n");
    printf("Current id: %d\n", id);
    c = getchar();
    while (c != EOF) {
      if (c == 91 || c == 93) {
	if (c == 91) { id--; } else { id++; }
	if (id < 0) { id = 0; }
	if (id > num_words) { id = num_words; }
	printf("Current id: %d\n", id);
      }
      c = getchar();
    }
    printf("Token at id=%d: %s\n", id, get_token(n_tokens, id));
  } else if (c == 119) { // print word_count
    printf("Number of words in string: %d\n", count_words(s_ptr));
  } else {
    printf("Invalid command. Now exiting program\n");
  }
  free_tokens(n_tokens);
  printf("Thank you. Goodbye!\n");
}
