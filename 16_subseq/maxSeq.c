#include <stdio.h>
#include <stdlib.h>


void sequence (size_t * position, int * longest, int * array,  size_t n){
  int currentSequence = 1;
  for (int i = *position; i < (n-1); i++){
    if (array[i+1] > array[i]){
      currentSequence++;
    }
    else {
      *position = (i+1);
      break;
    }
  }
  if (*longest < currentSequence){
    *longest = currentSequence;
  }
}
 
size_t maxSeq(int * array, size_t n){
  if (n < 1){
      return 0;
    }
  int longestSequence = 1;
  size_t position = 0;
  for (int j = 0; j < n; j++){
    if (position <= (n-2)){
      sequence(&position, &longestSequence, array, n);
      }
  }
  return longestSequence;
}

