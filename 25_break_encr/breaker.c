#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int freqCount (FILE * f){
  int array[26] = {0};
  char c;
  while ((c = fgetc(f)) != EOF){
    if (isalpha(c)){
      c = tolower(c);
      switch (c){
      case 'a': array[0] += 1; break;
      case 'b': array[1] += 1; break;
      case 'c': array[2] += 1; break;
      case 'd': array[3] += 1; break;
      case 'e': array[4] += 1; break;
      case 'f': array[5] += 1; break;
      case 'g': array[6] += 1; break;
      case 'h': array[7] += 1; break;
      case 'i': array[8] += 1; break;
      case 'j': array[9] += 1; break;
      case 'k': array[10] += 1; break;
      case 'l': array[11] += 1; break;
      case 'm': array[12] += 1; break;
      case 'n': array[13] += 1; break;
      case 'o': array[14] += 1; break;
      case 'p': array[15] += 1; break;
      case 'q': array[16] += 1; break;
      case 'r': array[17] += 1; break;
      case 's': array[18] += 1;	break;
      case 't': array[19] += 1; break;
      case 'u': array[20] += 1; break;
      case 'v': array[21] += 1; break;
      case 'w': array[22] += 1; break;
      case 'x': array[23] += 1; break;
      case 'y': array[24] += 1; break;
      case 'z': array[25] += 1;	break;
      }
    }
  }
  int largestIndex = 0;
  int temp = 0;
  for (int i = 0; i < 26; i++){
    if (array[i] > temp){
      temp = array[i];
      largestIndex = i;
    }
  }
  return largestIndex;
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
  int index = freqCount(f);
  int key = 0;
  if (index > 4){
    key = index - 4;
  }
  if ((index < 4) && (index != 4)){
    key = 26 - 4 + index;
  }
  printf ("%d\n", key);
  return EXIT_SUCCESS;
}
