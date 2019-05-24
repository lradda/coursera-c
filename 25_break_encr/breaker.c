#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//int freqCount (int letterNumber, FILE * f){
// char c = fgetc(f);
//  char currentLetter = c;
//  int counter = 1;
//  while ((c = fgetc(f)) != EOF){
//    if (isalpha(c)){
//     c = tolower(c);
//      if (c == currentLetter){
//	counter += 1;
//      }
//      if (c != currentLetter){


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
    fprintf(stderr, "ppppUsage: encrypt key inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL){
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  int letterCount;
  int maxCount;
  int index;
  //array
  int key = 0;
  for (int i = 0; i < 26; i++){
    letterCount = freqCount(i, f);
    if (letterCount > maxCount){
      index = i;
      maxCount = letterCount;
    }
    //letterCount[i] = freqCount(i, f);
  }
  //int temp = -1;
  //int mostCommon = 0;
  //for (int j = 0; j < 26; j++){
  //  if (letterCount[j] > temp){
  //mostCommon = j;
  //	temp = letterCount[j];
  //  }
  //}
  if (index > 4){
    key = index - 4;
  }
  if ((index < 4) && (index != 4)){
    key = 26 - 4 + index;
  }
  printf ("%d\n", key);
  return EXIT_SUCCESS;
}
