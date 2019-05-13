#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"


void print_hand(deck_t * hand){
  for (size_t i = 0; i < hand->n_cards; i++){
    print_card(*(hand->cards[i]));
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  for (size_t i = 0; i < d->n_cards; i++){
    if ((d->cards[i]->value == c.value) && (d->cards[i]->suit == c.suit)){
      return 1;
    }   
  }    
  return 0;
}

void shuffle(deck_t * d){
  int tempValue[d->n_cards];
  int tempSuit[d->n_cards];
  int newOrder[d->n_cards];
  int n = (random() % d->n_cards);
  newOrder[0] = n;
  for (int i = 1; i < d->n_cards; i++){
    n = (random() % d->n_cards);
    for (int j = 0; j < i; j++){
      if (newOrder[j] == n){
	n = (random() % d->n_cards);
	j = -1;
      }
    }  				      
    newOrder[i] = n;
  }
  for (int m = 0; m < d->n_cards; m++){
    tempSuit[m] = d->cards[newOrder[m]]->suit;
    tempValue[m] = d->cards[newOrder[m]]->value; 
  }
  for (int k = 0; k < d->n_cards; k++){
    d->cards[k]->value = tempValue[k];
    d->cards[k]->suit = tempSuit[k];    
  }  
}

void assert_full_deck(deck_t * d) {
  card_t array[d->n_cards];
  int temp = -1;
  for (unsigned i = 0; i < d->n_cards; i++){
    card_t tempCard = card_from_num(i);
    array[i] = tempCard;
  }
  for (unsigned j = 0; j < d->n_cards; j++){
    if ((deck_contains(d, array[j])) == 1){
      temp += 1;
    }
  }
  assert(temp == (d->n_cards - 1));   
}
