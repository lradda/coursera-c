#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >= 2);
  assert(c.value <= 14);
  assert(c.suit >= 0);
  assert(c.suit <= 3);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH: return "STRAIGHT FLUSH";
  case FOUR_OF_A_KIND: return "FOUR OF A KIND";
  case FULL_HOUSE: return "FULL HOUSE";
  case FLUSH: return "FLUSH";
  case STRAIGHT: return "STRAIGHT";
  case THREE_OF_A_KIND: return "THREE OF A KIND";
  case TWO_PAIR: return "TWO PAIR";
  case PAIR: return "PAIR";
  case NOTHING: return "NOTHING";
  }
  return "";
} 

char value_letter(card_t c) {
  switch(c.value){
  case 2: return '2';
  case 3: return '3';
  case 4: return '4';
  case 5: return '5';
  case 6: return '6';
  case 7: return '7';
  case 8: return '8';
  case 9: return '9';
  case 10: return '0';
  case 11: return 'J';
  case 12: return 'Q';
  case 13: return 'K';
  case 14: return 'A';
  }
  return 'x';
}

char suit_letter(card_t c) {
  switch (c.suit){
  case 0: return 's';
  case 1: return 'h';
  case 2: return 'd';
  case 3: return 'c';
  case 4:
    printf ("Not a valid suit");
    return '!';
  }
  return 'x';
}

void print_card(card_t c) {
  printf("%c", value_letter(c));
  printf("%c", suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  switch (value_let){
  case '2':
    value_let = 2;
  case '3':
    value_let = 3;
  case '4':
    value_let = 4;
  case '5':
    value_let = 5;
  case '6':
    value_let = 6;
  case '7':
    value_let = 7;
  case '8':
    value_let = 8;
  case '9':
    value_let = 9;
  case '0':
    value_let = 10;
    break;
  case 'J':
    value_let = 11;
    break;
  case 'Q':
    value_let = 12;
    break;
  case 'K':
    value_let = 13;
    break;
  case 'A':
    value_let = 14;
    break;
  }
  switch (suit_let){
  case 's':
    suit_let = 0;
    break;
  case 'h':
    suit_let = 1;
    break;
  case 'd':
    suit_let = 2;
    break;
  case 'c':
    suit_let = 3;
    break;
  case '!':
    suit_let = 4;
    break;
  }   
  temp.value = value_let;
  temp.suit = suit_let;
  assert_card_valid(temp);
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  temp.value = ((c % 13) +2);
  temp.suit = (c / 13);
  return temp;
}
