#include "cards.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void) {
  card_t test;
  test.value = 12;
  test.suit = 2;
  printf("%s\n", ranking_to_string(FLUSH));
  printf("%c\n", value_letter(test));
  printf("%c\n", suit_letter(test));
  print_card(test);
  print_card(card_from_letters('K', 's'));
  print_card(card_from_num(14));
  EXIT_SUCCESS;
}
