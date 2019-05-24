#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int freqCount(int letterNumber, FILE * f){
  char c;
  int counter = 0;
  char letter = ('a' + letterNumber);
  while ((c = fgetc(f)) != EOF){
    if (isalpha(c)){
      c = tolower(c);
      if (c == letter){
	  counter += 1;
	}
    }
  }
  rewind(f);
  return counter;
}      
 
int main (int argc, char ** argv){
  if (argc != 2){
    fprintf(stderr, "Usage: encrypt key inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL){
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  int letterCount[26] = {0};
  int key = 0;
  for (int i = 0; i < 26; i++){
    letterCount[i] = freqCount(i, f);
  }
  int mostCommon = 0;
  for (int j = 0; j < 26; j++){
    if (letterCount[j] > mostCommon){
	mostCommon = j;
      }
  }
  if (mostCommon > 4){
    key = mostCommon - 4;
  }
  if ((mostCommon < 4) && (mostCommon != 0)){
    key = 26 - mostCommon;
  }
  printf ("%d\n", key);
  return EXIT_SUCCESS;
}
