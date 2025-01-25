#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "cards.h"

static void FreeCards(card *cards, uint length)
{
    if (cards != NULL && length != 0)
    {
        for (int i = 0; i < length; i++)
        {
            FreeCard(cards[i]);
        }
    }
}

bool test_CreateClassicCard()
{
    for (int number = 2; number < 11; number++)
    {
        for (int color = 0; color < NB_COLORS; color++)
        {
            card c1 = CreateClassicCard(color, number);

            // card with same color and number
            card c2 = CreateClassicCard(color, number);

            // card with same color and diferent number
            card c3 = CreateClassicCard(color, number != 10 ? number + 1 : number - 1);

            // card with same number but a different color
            card c4 = CreateClassicCard(color == 0 ? HEARTS : color - 1, number);

            // special cards with the same color
            card c5 = CreateSpeCard(KING, color);
            card c6 = CreateSpeCard(QUEEN, color);
            card c7 = CreateSpeCard(JACK, color);
            card c8 = CreateSpeCard(ACE, color);
            if (!AreEqual(c1, c2) || AreEqual(c1, c3) || AreEqual(c1, c4) || AreEqual(c1, c5) || AreEqual(c1, c6) || AreEqual(c1, c7) || AreEqual(c1, c8))
            {
                FreeCards((card[]){c1, c2, c3, c4, c5, c6, c7, c8}, 8);
                return false;
            }
            FreeCards((card[]){c1, c2, c3, c4, c5, c6, c7, c8}, 8);
        }
    }
    return true;
}

bool test_CreateSpeCard()
{
    SpecialCardType types[] = {ACE, JACK, QUEEN, KING};
    for (int i = 0; i < NB_NAMES; i++)
    {
        printf("1");
        for (int color = 0; color < NB_COLORS; color++)
        {
            card c1 = CreateSpeCard(types[i], color);
            printf("2");
            // card with same type and color
            card c2 = CreateSpeCard(types[i], color);
            printf("3");
            // card with same type but a different color
            card c3 = CreateSpeCard(types[i], color == 0 ? HEARTS : color - 1);
            printf("4");
            // basic card with the same color
            card c4 = CreateClassicCard(color, 6);
            if (!AreEqual(c1, c2) || AreEqual(c1, c3) || AreEqual(c1, c4))
            {
                printf("5");
                FreeCards((card[]){c1, c2, c3, c4}, 4);
                return false;
            }
            FreeCards((card[]){c1, c2, c3, c4}, 4);
        }
    }
    return true;
}

bool test_FreeCard()
{
    // try to free a classic card and a special card
    card c1 = CreateClassicCard(SPADES, 2);
    card c2 = CreateSpeCard(ACE, 0);
    FreeCard(c1);
    FreeCard(c2);
    return true;
}

bool test_AreEquivalent()
{
    for (int color = 0; color < NB_COLORS; color++)
    {
        /*We first ckeck equivalence between classic card and classic card / special card*/
        for (uint number = 2; number < 11; number++)
        {
            // check if a card is equivalent to cards with same color but different number
            card c1 = CreateClassicCard(color, number);
            for (uint num = number + 1; num < 11; num++)
            {
                card c2 = CreateClassicCard(color, num);
                if (!AreEquivalent(c1, c2))
                {
                    FreeCards((card[]){c1, c2}, 2);
                    return false;
                }
                FreeCard(c2);
            }

            // check if a special card and a classic card with same color are equivalent
            card c3 = CreateSpeCard(KING, color);
            card c4 = CreateSpeCard(QUEEN, color);
            card c5 = CreateSpeCard(JACK, color);
            if (!AreEquivalent(c1, c3) || !AreEquivalent(c1, c4) || !AreEquivalent(c1, c5))
            {
                FreeCards((card[]){c1, c3, c4, c5}, 4);
                return false;
            }

            // check if two cards with different color but same numbers are equivalent
            card c6 = CreateClassicCard(((color + 1) % NB_COLORS), number);
            if (!AreEquivalent(c1, c6))
            {
                FreeCards((card[]){c1, c3, c4, c5, c6}, 5);
                return false;
            }

            // check if two cards with nothing in common are not equivalent
            card c7 = CreateClassicCard(((color + 1) % NB_COLORS), number == 10 ? 2 : number + 1);
            card c8 = CreateSpeCard(JACK, ((color + 1) % NB_COLORS));
            if (AreEquivalent(c1, c7) || AreEquivalent(c1, c8))
            {
                FreeCards((card[]){c1, c3, c4, c5, c6, c7, c8}, 7);
                return false;
            }
            FreeCards((card[]){c1, c3, c4, c5, c6, c7, c8}, 7);
        }

        /*Then we check equivalence between two special cards*/
        card c9 = CreateSpeCard(JACK, color);
        card c10 = CreateSpeCard(JACK, ((color + 1) % NB_COLORS));
        card c11 = CreateSpeCard(KING, ((color + 1) % NB_COLORS));
        card c12 = CreateSpeCard(QUEEN, ((color + 1) % NB_COLORS));
        if (!AreEquivalent(c9, c10) || AreEquivalent(c9, c11) || AreEquivalent(c9, c11))
        {
            FreeCards((card[]){c9, c10, c11, c12}, 4);
            return false;
        }
    }
    return true;
}

void usage(char *argv[])
{
    fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        usage(argv);
    }

    fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);

    bool ok = false;
    /*if (strcmp("CreatePack", argv[1]) == 0)
    {
        ok = test_CreatePack();
    }*/
    /*else*/ if (strcmp("CreateClassicCard", argv[1]) == 0)
    {
        ok = test_CreateClassicCard();
    }
    /*else if (strcmp("IsEmptyPack", argv[1]) == 0)
    {
        ok = test_IsEmptyPack();
    }*/
    else if (strcmp("CreateSpeCard", argv[1]) == 0)
    {
        ok = test_CreateSpeCard();
    }
    else if (strcmp("AreEquivalent", argv[1]) == 0)
    {
        ok = test_AreEquivalent();
    }
    else if (strcmp("FreeCard", argv[1]) == 0)
    {
        ok = test_FreeCard();
    } /*
     else if (strcmp("CreatePick", argv[1]) == 0)
     {
         ok = test_CreatePick();
     }
     else if (strcmp("IsEmptyPick", argv[1]) == 0)
     {
         ok = test_IsEmptyPick();
     }
     else if (strcmp("AddCardPick", argv[1]) == 0)
     {
         ok = test_AddCardPick();
     }
     else if (strcmp("PickCard", argv[1]) == 0)
     {
         ok = test_PickCard();
     }
     else if (strcmp("FreePick", argv[1]) == 0)
     {
         ok = test_FreePick();
     }
     else if (strcmp("CreateFullPack", argv[1]) == 0)
     {
         ok = test_CreateFullPack();
     }
     else if (strcmp("ShufflePack", argv[1]) == 0)
     {
         ok = test_ShufflePack();
     }
     else if (strcmp("FreePack", argv[1]) == 0)
     {
         ok = test_FreePack();
     }
     else if (strcmp("RemoveCardPack", argv[1]) == 0)
     {
         ok = test_RemoveCardPack();
     }*/
    else
    {
        fprintf(stderr, "Error: test \"%s\" not found!\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (ok)
    {
        fprintf(stderr, "Test \"%s\" finished: SUCCESS\n", argv[1]);
        return EXIT_SUCCESS;
    }
    else
    {
        fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
        return EXIT_FAILURE;
    }
}