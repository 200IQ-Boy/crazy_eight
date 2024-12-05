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
            printf("    _ _ _ _ _ _ _ _ _\n");
            printf("   | A            A  |\n");
            printf("   |                 |\n");
            printf("   |                 |\n");
            printf("   |        ");
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
            printf("        |\n");
            printf("   |                 |\n");
            printf("   |                 |\n");
            printf("   | A            A |\n");
            printf("    _ _ _ _ _ _ _ _ _\n");
            break;
        case JACK:
            printf("    _ _ _ _ _ _ _ _ _\n");
            printf("   | J            J  |\n");
            printf("   |                 |\n");
            printf("   |                 |\n");
            printf("   |        ");
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
            printf("        |\n");
            printf("   |                 |\n");
            printf("   |                 |\n");
            printf("   | J            J |\n");
            printf("    _ _ _ _ _ _ _ _ _\n");
            break;
        case QUEEN:
            printf("    _ _ _ _ _ _ _ _ _\n");
            printf("   | Q            Q  |\n");
            printf("   |                 |\n");
            printf("   |                 |\n");
            printf("   |        ");
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
            printf("        |\n");
            printf("   |                 |\n");
            printf("   |                 |\n");
            printf("   | Q            Q |\n");
            printf("    _ _ _ _ _ _ _ _ _\n");
            break;
        case KING:
            printf("    _ _ _ _ _ _ _ _ _\n");
            printf("   | K            K  |\n");
            printf("   |                 |\n");
            printf("   |                 |\n");
            printf("   |        ");
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
            printf("        |\n");
            printf("   |                 |\n");
            printf("   |                 |\n");
            printf("   | K            K |\n");
            printf("    _ _ _ _ _ _ _ _ _\n");
            break;
        default:
            break;
        }
    }
    else{
        printf("    _ _ _ _ _ _ _ _ _\n");
        printf("   | %d            %d  |\n",c->card_type.b_card.value,c->card_type.b_card.value);
        printf("   |                 |\n");
        printf("   |                 |\n");
        printf("   |        ");
        switch (c->card_type.b_card.color)
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
        printf("        |\n");
        printf("   |                 |\n");
        printf("   |                 |\n");
        printf("   | %d            %d |\n",c->card_type.b_card.value,c->card_type.b_card.value);
        printf("    _ _ _ _ _ _ _ _ _\n");
    }
    
}

int main(){
    card c1 = CreateClassicCard(SPADES,2);
    card c2 = CreateSpeCard(ACE,HEARTS);
    card c3 = CreateSpeCard(JACK,DIAMONDS);
    card c4 = CreateSpeCard(QUEEN,CLUBS);
    card c5 = CreateSpeCard(KING,SPADES);
    card c6 = CreateClassicCard(HEARTS,3);
    card c7 = CreateClassicCard(DIAMONDS,4);
    card c8 = CreateClassicCard(CLUBS,5);
    card c9 = CreateClassicCard(SPADES,6);
    card c10 = CreateClassicCard(HEARTS,7);
    card c11 = CreateClassicCard(DIAMONDS,8);
    card c12 = CreateClassicCard(CLUBS,9);
    card c13 = CreateClassicCard(SPADES,10);

    PrintCard(c1);
    PrintCard(c2);
    PrintCard(c3);
    PrintCard(c4);
    PrintCard(c5);
    PrintCard(c6);
    PrintCard(c7);
    PrintCard(c8);
    PrintCard(c9);
    PrintCard(c10);
    PrintCard(c11);
    PrintCard(c12);
    PrintCard(c13);

    printf("Are c1 and c2 equivalent ? %d\n",AreEquivalent(c1,c2));
    printf("Are c2 and c3 equivalent ? %d\n",AreEquivalent(c2,c3));
    printf("Are c3 and c4 equivalent ? %d\n",AreEquivalent(c3,c4));
    printf("Are c4 and c5 equivalent ? %d\n",AreEquivalent(c4,c5));
    printf("Are c5 and c6 equivalent ? %d\n",AreEquivalent(c5,c6));
    printf("Are c6 and c7 equivalent ? %d\n",AreEquivalent(c6,c7));
    printf("Are c7 and c8 equivalent ? %d\n",AreEquivalent(c7,c8));
    printf("Are c8 and c9 equivalent ? %d\n",AreEquivalent(c8,c9));
    printf("Are c9 and c10 equivalent ? %d\n",AreEquivalent(c9,c10));
    printf("Are c10 and c11 equivalent ? %d\n",AreEquivalent(c10,c11));
    printf("Are c11 and c           equivalent ? %d\n",AreEquivalent(c11,c12));         
    printf("Are c12 and c13 equivalent ? %d\n",AreEquivalent(c12,c13));
    printf("Are c13 and c1 equivalent ? %d\n",AreEquivalent(c13,c1));       
    return EXIT_SUCCESS;
}