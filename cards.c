#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cards.h"
#include <time.h>
#include <assert.h>

card CreateClassicCard(color color, uint number)
{
    // check parameters validity
    assert(color < NB_COLORS && color >= SPADES);
    assert(number >= 2 && number <= 10);

    card c = malloc(sizeof(s_card));
    if (c == NULL)
    {
        fprintf(stderr, "Failed to create a new card\n");
        exit(EXIT_FAILURE);
    }
    c->is_special = false;
    c->card_type.b_card.color = color;
    c->card_type.b_card.value = number;
    return c;
}

card CreateSpeCard(SpecialCardType name, color color)
{
    // check parameters validity
    assert(color < NB_COLORS && color >= SPADES);

    card c = malloc(sizeof(s_card));
    if (c == NULL)
    {
        fprintf(stderr, "Failed to create a new special card\n");
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
            fprintf(stderr, "The name given is not a possible speacial card\n");
            exit(EXIT_FAILURE);
    }

    return c;
}

bool AreEquivalent(card c1, card c2)
{
    // test parameters validity
    if (c1 == NULL || c2 == NULL)
    {
        fprintf(stderr, "One of the cards is NULL\n");
        exit(EXIT_FAILURE);
    }
    // if cards are special we compare the name or the color
    if (c1->is_special && c2->is_special)
    {
        return c1->card_type.s_card.name == c2->card_type.s_card.name || c1->card_type.s_card.color == c2->card_type.s_card.color;
    }
    // if cards are not special we compare the color or the number
    else if (!c1->is_special && !c2->is_special)
    {
        return c1->card_type.b_card.color == c2->card_type.b_card.color || c1->card_type.b_card.value == c2->card_type.b_card.value;
    }
    // check cards of different types are equivalent
    else if (c1->is_special && !c2->is_special)
    {
        return c1->card_type.s_card.color == c2->card_type.b_card.color;
    }
    else 
    {
        return c1->card_type.b_card.color == c2->card_type.s_card.color;
    }
}

bool AreEqual(card c1, card c2) 
{
    if(c1->is_special && c2->is_special) 
    {
        return c1->card_type.s_card.color == c2->card_type.s_card.color && c1->card_type.s_card.name == c2->card_type.s_card.name;
    }
    if(!c1->is_special && !c2->is_special)
    {
        return c1->card_type.b_card.color == c2->card_type.b_card.color && c1->card_type.b_card.value == c2->card_type.b_card.value;
    }
    return false;
}

void PrintCard(card c)
{
    if (c == NULL)
    {
        fprintf(stderr, "The card is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (c->is_special)
    {
        if (c->card_type.s_card.name == ACE)
        {
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
        }
        else if (c->card_type.s_card.name == JACK)
        {
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
        }
        else if (c->card_type.s_card.name == QUEEN)
        {
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
        }
        else
        {
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
        }
    }
    else
    {
        if (c->card_type.b_card.value == 10)
        {
            printf(".------.\n|%d    |\n|      |\n|  ", c->card_type.b_card.value);
        }
        else
        {
            printf(".------.\n|%d     |\n|      |\n|  ", c->card_type.b_card.value);
        }
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
        if (c->card_type.b_card.value == 10)
        {
            printf("   |\n|      |\n|    %d|\n'------'\n", c->card_type.b_card.value);
        }
        else
        {
            printf("   |\n|      |\n|     %d|\n'------'\n", c->card_type.b_card.value);
        }
    }
}

void FreeCard(card c)
{
    if (c != NULL)
    {
        free(c);
    }
}

pack CreatePack()
{
    pack n_pack = malloc(sizeof(s_pack));
    if (n_pack == NULL)
    {
        fprintf(stderr, "Failed to create a new pack\n");
        exit(EXIT_FAILURE);
    }
    n_pack->pack_cards = malloc(52 * sizeof(card));
    if (n_pack->pack_cards == NULL)
    {
        fprintf(stderr, "Failed to create a new pack\n");
        free(n_pack);
        exit(EXIT_FAILURE);
    }
    n_pack->taille = 0;
    return n_pack;
}

bool IsEmptyPack(pack p)
{
    if (p == NULL || p->taille == 0)
        return true;
    return false;
}

bool AddCardPack(pack p, card c)
{
    if (p == NULL || c == NULL)
    {
        fprintf(stderr, "The pack or the card is NULL\n");
       return false;
    }
    if (p->taille == 52)
    {
        fprintf(stderr, "The pack is full\n");
        return false;
    }
    p->pack_cards[p->taille] = c;
    p->taille++;
    return true;
}

pack CreateFullPack()
{
    pack f_pack = CreatePack();

    // add of basic cards in the pack
    for (int color = 0; color < NB_COLORS; color++)
    {
        for (int value = 2; value < 11; value++)
        {
            AddCardPack(f_pack, CreateClassicCard(color, value));
        }
    }
    // add of special cards
    for (int color = 0; color < NB_COLORS; color++)
    {
        AddCardPack(f_pack, CreateSpeCard(ACE, color));
        AddCardPack(f_pack, CreateSpeCard(JACK, color));
        AddCardPack(f_pack, CreateSpeCard(QUEEN, color));
        AddCardPack(f_pack, CreateSpeCard(KING, color));
    }
    return f_pack;
}

pack ShufflePack(pack p)
{
    // test parameters validity
    if (IsEmptyPack(p))
    {
        fprintf(stderr, "Empty pack can't be shuffled\n");
        exit(EXIT_FAILURE);
    }

    // Fisher-Yates Shuffle Algorithm
    srand(time(NULL));
    for (int i = p->taille - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        card tmp = p->pack_cards[i];
        p->pack_cards[i] = p->pack_cards[j];
        p->pack_cards[j] = tmp;
    }
    return p;
}

void FreePack(pack p)
{
    if (p != NULL)
    {
        free(p->pack_cards);
        free(p);
    }
}

bool RemoveCardPack(pack p, card c)
{
    if (IsEmptyPack(p) || c == NULL)
    {
        fprintf(stderr, "The pack is empty or the card is NULL\n");
        return false;
    }

    if (c->is_special)
    {
        for (int i = 0; i < p->taille; i++)
        {
            if (p->pack_cards[i]->is_special && p->pack_cards[i]->card_type.s_card.color == c->card_type.s_card.color && p->pack_cards[i]->card_type.s_card.name == c->card_type.s_card.name)
            {
                FreeCard(p->pack_cards[i]);
                for (int j = i; j < p->taille - 1; j++)
                {
                    p->pack_cards[j] = p->pack_cards[j + 1];
                }
                p->taille--;
                return true;
            }
        }
    }
    else
    {
        for (int i = 0; i < p->taille; i++)
        {
            if (!p->pack_cards[i]->is_special && p->pack_cards[i]->card_type.b_card.color == c->card_type.b_card.color && p->pack_cards[i]->card_type.b_card.value == c->card_type.b_card.value)
            {
                FreeCard(p->pack_cards[i]);
                for (int j = i; j < p->taille - 1; j++)
                {
                    p->pack_cards[j] = p->pack_cards[j + 1];
                }
                p->taille--;
                return true;
            }
        }
    }
    fprintf(stderr, "The card is not in the pack\n");
    return false;
}

pick CreatePick()
{
    pick pioche = malloc(sizeof(s_pick));
    if (pioche == NULL)
    {
        fprintf(stderr, "Failed to create a new Pick\n");
        exit(EXIT_FAILURE);
    }
    pioche->next = NULL;
    pioche->picked = NULL;
    return pioche;
}

bool IsEmptyPick(pick p)
{
    return p == NULL || p->picked == NULL;
}

pick AddCardPick(pick p, card c)
{
    if (p == NULL || c == NULL)
    {
        fprintf(stderr, "The pick or the card is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (p->picked == NULL)
    {
        p->picked = c;
        return p;
    }
    pick node = CreatePick();
    node->picked = c;
    node->next = NULL;
    p->next = node;
    return p;
}

card PickCard(pick * p)
{
    if (IsEmptyPick(p))
    {
        fprintf(stderr, "The pick is empty\n");
        return NULL;
    }
    card res = (*p)->picked;
    pick tmp = (*p)->next;
    free(*p);
    (*p)= tmp;
    return res;
}

void FreePick(pick p)
{
    if (!IsEmptyPick(p))
    {
        pick tmp = p->next;
        free(p);
        while (tmp != NULL)
        {
            pick q = tmp->next;
            free(tmp);
            tmp = q;
        }
    }
}
