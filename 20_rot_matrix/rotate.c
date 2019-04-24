#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void rotate(char matrix[10][10]){
  char arrayTemp[10][10];
  for (int j = 0; j < 10; j++) {
    for (int i = 10; i > 0; i--)  {
      arrayTemp[j][9-i+1] = matrix[i-1][j];
    }
  }
  for (int k = 0; k < 10; k++) {
    for (int l = 0; l < 10; l++)  {
      matrix[k][l] = arrayTemp[k][l];
    }
  }
}

