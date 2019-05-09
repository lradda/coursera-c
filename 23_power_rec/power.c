#include <stdio.h>
#include <stdlib.h>


unsigned powerHelper(unsigned x, unsigned y, unsigned * temp){
  if (y == 1){
    return x;
  }
  else {
    x = (x * *temp);
    return powerHelper(x, y-1, temp);
  }
}

unsigned power(unsigned x, unsigned y){
  if (((x == 0) && (y == 0)) || (y == 0)){
    return 1;
  }
  if ((x == 0) || (y > 40000000)){
    return 0;
  }
  unsigned z = x;
  unsigned * temp = &z; 
  return powerHelper(x, y, temp);
}


