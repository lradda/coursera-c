#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

void writeMatrix(FILE * f, char array[10][11]){
  char c;
  for (int j = 0; j < 10; j++){
    for (int i = 0; i <= 10; i++){
      //if ((c = fgetc(f)) != EOF){
      c = fgetc(f);
      //if (c == 10){
      //continue;
      //}
	array[j][i] = c;
	//printf("%d %d\n", i, j);
	//printf("%c", c);
	//printf("%c\n", array[j][i]); 
	//}
    }       
  }
}  

void rotate(char array[10][11]){
  char arrayTemp[10][11];
  for (int j = 0; j < 10; j++){
    for (int i = 0; i < 10; i++){
      //printf("%c", array[j][i]);
      arrayTemp[j][i] = array[9-i][j];
      //printf("%c", arrayTemp[j][i]);

    }
    arrayTemp[j][10] = array[j][10];
  }
  for (int k = 0; k < 10; k++){
    for (int l = 0; l <= 10; l++){
      array[k][l] = arrayTemp[k][l];
    }
  }  
}

int main(int argc, char ** argv){
  if (argc != 2){
    fprintf(stderr, "Usage: encrypt key inputFileName\n");
    return EXIT_FAILURE;
  }
  FILE * f = fopen(argv[1], "r");
  if (f == NULL){
    perror("Could not open file");
    return EXIT_FAILURE;
  }
  char array[10][11];
  writeMatrix(f, array);
  //test
  //for (int i = 0; i < 10; i++){
  //for (int j = 0; j <= 10; j++){
  //  printf("%c", array[i][j]);
  //}
  //}
//test
  rotate(array);
  for (int i = 0; i < 10; i++){
    for (int j = 0; j <= 10; j++){
      printf("%c", array[i][j]);
    }
  }
  return EXIT_SUCCESS;
}
