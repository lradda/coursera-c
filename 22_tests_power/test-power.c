#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y);

void run_check(unsigned x, unsigned y, unsigned expected_ans){
  if (power(x, y) != expected_ans){
    printf("Did not match expected answer\n");
    exit(EXIT_FAILURE);
  }
}

int main(void){
  run_check(0, 0, 1);
  run_check(0, 3, 0);
  run_check(3, 0, 1);
  run_check(-1, 2, 1);
  run_check(2, -2, 0);
  run_check(1, 1, 1);
  run_check(25, 5, 9765625);
  EXIT_SUCCESS;
}
  
  
