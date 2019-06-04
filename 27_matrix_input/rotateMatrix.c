#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

//int writeMatrix(FILE * f, char array[10][11]){
//  char c;
//  for (int j = 0; j < 10; j++){
//    for (int i = 0; i <= 10; i++){
//      if ((c = fgetc(f)) == EOF){
//	return 1;       
//     }
//      if ((i < 10) && (c == 10)){
//	return 2;
//      }
//      array[j][i] = c;
//    }       
//  }
//  if ((c = fgetc(f)) != EOF){
//    return 3;
//  }
//  return 0;
//}  

void rotate(char array[10][11]){
  char arrayTemp[10][11];
  for (int j = 0; j < 10; j++){
    for (int i = 0; i < 10; i++){
      arrayTemp[j][i] = array[9-i][j];
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
  int c;
  for (int j = 0; j < 10; j++){
    for (int i = 0; i <= 10; i++){
      if ((c = fgetc(f)) == EOF){
	fprintf(stderr, "File is too short\n");
	return EXIT_FAILURE;
      }
      if ((i < 10) && (c == 10)){
	fprintf(stderr, "Line is too short\n");
	return EXIT_FAILURE;
      }
      if ((i == 10) && (c != 10)){
	fprintf(stderr, "Line is too long\n");
	return EXIT_FAILURE;
      }				  
      array[j][i] = c;
    }       
  }
  if ((c = fgetc(f)) != EOF){
    fprintf(stderr, "File is too long\n");
    return EXIT_FAILURE;
  //  int x = writeMatrix(f, array);
  //if (x == 1){
  //  fprintf(stderr, "File is too short\n");
  //  return EXIT_FAILURE;
  //}
  //if (x == 2){
  //  fprintf(stderr, "Line is too short\n");
  //  return EXIT_FAILURE;
  //}
  //if (x == 3){
  //   fprintf(stderr, "File is too long\n");
  // return EXIT_SUCCESS;
  } 
  rotate(array);
  for (int i = 0; i < 10; i++){
    for (int j = 0; j <= 10; j++){
      printf("%c", array[i][j]);
    }
  }
  return EXIT_SUCCESS;
}
