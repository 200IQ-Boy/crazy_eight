#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cards.h"
#include <assert.h>

card CreateClassicCard(color color,uint number){
    //check parameters validity
    assert(color < NB_COLORS && color >= SPADES) ;
    assert(number >= 2 && number <= 10);

    card c = malloc(sizeof(s_card));
    if(c == NULL){
        fprintf(stderr,"Failed to create a new card\n");
        exit(EXIT_FAILURE);
    }
    c->is_special = false;
    c->card_type.b_card.color = color;
    c->card_type.b_card.value = number;
    return c;
}

card CreateSpeCard(SpecialCardType name , color color){
    //check parameters validity
    assert(color < NB_COLORS && color >= SPADES);

    card c = malloc(sizeof(s_card));
    if(c == NULL){
        fprintf(stderr,"Failed to create a new special card\n");
        exit(EXIT_FAILURE);
    }
    c->is_special = true;

    switch (name)
    {
    case ACE:
        c->card_type.s_card.color = color;
        c->card_type.s_card.name = ACE;
        break;
    case JACK:
        c->card_type.s_card.color = color;
        c->card_type.s_card.name = JACK;
        break;
    case QUEEN:
        c->card_type.s_card.color = color;
        c->card_type.s_card.name = QUEEN;
        break;
    case KING:
        c->card_type.s_card.color = color;
        c->card_type.s_card.name = KING;
        break;
    default:
        fprintf(stderr,"The name given is not a possible speacial card\n");
        exit(EXIT_FAILURE);
    }
    
    return c;
}

