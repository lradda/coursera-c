#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str) {
  //WRITE ME!
  if (str == NULL){
    return;
  }
  int x = 0;
  char * p = str;
  while (*p != '\0'){
    x++;
    p++;
  }
  char tempString[x];
  for (int i = 0; i < x; i++){
    tempString[i] = str[x - 1 - i];
  }
  char * p1 = str;
  char * p2 = tempString;
  while (*p1 != '\0'){
    *p1 = *p2;
    p1++;
    p2++;
  }
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
