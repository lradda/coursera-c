#include <stdio.h>
#include <stdlib.h>
size_t maxSeq(int * array, size_t n);

int main(void){
  int array1[] = {1,2,3};
  if (maxSeq(array1, 3) != 3) {
    printf("Failed on array1\n");
    exit(EXIT_FAILURE);
  }
  int array2[] = {0};
  if (maxSeq(array2, 0) != 0) {
    printf("Failed on array2\n");
    exit(EXIT_FAILURE);
  }
  int array3[] = {1,2,3,2,2,2,4,5,6,7,2,2,7,8,9};
  if (maxSeq(array3, 15) != 5) {
    printf("Failed on array3\n");
    exit(EXIT_FAILURE);
  }
  int array4[] = {4,4,4,4,4,4,4};
  if (maxSeq(array4, 7) != 1) {
    printf("Failed on array4\n");
    exit(EXIT_FAILURE);
  }
  int array5[] = {1};
  if (maxSeq(array5, 1) != 1) {
    printf("Failed on array5\n");
    exit(EXIT_FAILURE);
  }
  int array6[] = {0,6,7,0,2};
  if (maxSeq(array6, 3) != 3) {
    printf("Failed on array6\n");
    exit(EXIT_FAILURE);
  }
  int array7[] = {-1,0,3};
  if (maxSeq(array7, 3) != 3) {
    printf("Failed on array7\n");
    exit(EXIT_FAILURE);
  }
  int array8[] = {-3,-2,-1};
  if (maxSeq(array8, 3) != 3) {
    printf("Failed on array8\n");
    exit(EXIT_FAILURE);
  }
  int array9[] = {1,2,3,12,3,4,12,3};
  if (maxSeq(array9, 8) != 4) {
    printf("Failed on array9\n");
    exit(EXIT_FAILURE);
  }
  EXIT_SUCCESS;
}
  

 
