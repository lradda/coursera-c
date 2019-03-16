#include <stdlib.h>
#include <stdio.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double calculation (double newTotal, retire_info info){
  newTotal = newTotal + (newTotal * info.rate_of_return + info.contribution);
return newTotal;
}
   
void retirement (int startAge, double initial, retire_info working, retire_info retired){
  double total = initial;
  for (int i = 0; i < working.months; i++){  
    printf("Age %d month %d you have $%.2f\n", startAge/12, startAge%12, total);
    total = calculation(total, working);
    startAge++;
  }
  for (int i = 0; i < retired.months; i++){
    printf("Age %d month %d you have $%.2f\n", startAge/12, startAge%12, total);
    total = calculation(total, retired);
    startAge++;
  }
}

int main (void){
  int startAge = 327;
  double initial = 21345;
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = (0.045/12);
  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = (0.01/12);
  retirement (startAge, initial, working, retired);
  return EXIT_SUCCESS;
}
	  



  
