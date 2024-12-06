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

bool AreEquivalent(card c1 , card c2){
    // test parameters validity
    if(c1 == NULL || c2 != NULL){
        fprintf(stderr,"One of the cards is NULL\n");
        exit(EXIT_FAILURE);
    }
    // if cards are special we only compare the name
    if(c1->is_special && c2->is_special){
        return c1->card_type.s_card.name == c2->card_type.s_card.name;
    }
    // if cards are not special we compare the color and the number
    else if(!c1->is_special && !c2->is_special){
        return c1->card_type.b_card.color == c2->card_type.b_card.color || c1->card_type.b_card.value == c2->card_type.b_card.value;
    }
    return false;
}

void PrintCard(card c) {
    if(c == NULL){
        fprintf(stderr,"The card is NULL\n");
        exit(EXIT_FAILURE);
    }
    if(c->is_special){
        switch (c->card_type.s_card.name)
        {
        case ACE:
            printf(".------.\n|A     |\n|      |\n|  ");
            switch (c->card_type.s_card.color)
            {
            case SPADES:
                printf("♤");
                break;
            case HEARTS:
                printf("♡");
                break;
            case DIAMONDS:
                printf("♢");
                break;
            case CLUBS:
                printf("♧");
                break;
            default:
                break;
            }
            printf("   |\n|      |\n|     A|\n'------'\n");
        case JACK:
            printf(".------.\n|J     |\n|      |\n|  ");
            switch (c->card_type.s_card.color)
            {
            case SPADES:
                printf("♤");
                break;
            case HEARTS:
                printf("♡");
                break;
            case DIAMONDS:
                printf("♢");
                break;
            case CLUBS:
                printf("♧");
                break;
            default:
                break;
            }
            printf("   |\n|      |\n|     J|\n'------'\n");
        case QUEEN:
            printf(".------.\n|Q     |\n|      |\n|  ");
            switch (c->card_type.s_card.color)
            {
            case SPADES:
                printf("♤");
                break;
            case HEARTS:
                printf("♡");
                break;
            case DIAMONDS:
                printf("♢");
                break;
            case CLUBS:
                printf("♧");
                break;
            default:
                break;
            }
            printf("   |\n|      |\n|     Q|\n'------'\n");
        case KING:
            printf(".------.\n|K     |\n|      |\n|  ");
            switch (c->card_type.s_card.color)
            {
            case SPADES:
                printf("♤");
                break;
            case HEARTS:
                printf("♡");
                break;
            case DIAMONDS:
                printf("♢");
                break;
            case CLUBS:
                printf("♧");
                break;
            default:
                break;
            }
            printf("   |\n|      |\n|     K|\n'------'\n");
        default:
            break;
        }
    }
    else{
        printf(".------.\n|%d     |\n|      |\n|  ",c->card_type.b_card.value);
            switch (c->card_type.s_card.color)
            {
            case SPADES:
                printf("♤");
                break;
            case HEARTS:
                printf("♡");
                break;
            case DIAMONDS:
                printf("♢");
                break;
            case CLUBS:
                printf("♧");
                break;
            default:
                break;
            }
            printf("   |\n|      |\n|     %d|\n'------'\n",c->card_type.b_card.value);
    }
}

bool AreEquivalent(card c1 , card c2){
    // test parameters validity
    if(c1 == NULL || c2 != NULL){
        fprintf(stderr,"One of the cards is NULL\n");
        exit(EXIT_FAILURE);
    }
    // if cards are special we only compare the name
    if(c1->is_special && c2->is_special){
        return c1->card_type.s_card.name == c2->card_type.s_card.name;
    }
    // if cards are not special we compare the color and the number
    else if(!c1->is_special && !c2->is_special){
        if(c1->card_type.b_card.color != c2->card_type.b_card.color)
            return c1->card_type.b_card.value == c2->card_type.b_card.value;
        return true;
    }
    return false;
}

void FreeCard(card c){
    if(c != NULL){
        free(c);
    }
}

pack CreatePack(){
    pack n_pack = malloc(sizeof(s_pack));
    if(n_pack == NULL){
        fprintf(stderr,"Failed to create a new pack\n");
        exit(EXIT_FAILURE);
    }
    n_pack->pack_cards = malloc(52*sizeof(s_card));
    if(n_pack->pack_cards == NULL){
        fprintf(stderr,"Failed to create a new pack\n");
        free(n_pack);
        exit(EXIT_FAILURE);
    }
    n_pack->taille = 0;
    return n_pack; 
}

bool IsEmptyPack(pack p){
    if(p == NULL || p->taille == 0)
        return true;
    return false;
}