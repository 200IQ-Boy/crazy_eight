#ifndef CARDS
#define CARDS
#include <stdbool.h>

typedef unsigned int uint;
typedef enum 
{
    SPADES, 
    HEARTS, 
    DIAMONDS, 
    CLUBS,
    NB_COLORS
} color;

typedef struct 
{
    uint value;
    color color;
}base_card;

typedef struct 
{
    char* name;
    color color;
}spe_card;
typedef struct 
{
    bool is_named;
    union
    {
    base_card b_card;
    spe_card s_card;
    }card_type;
}s_card;
typedef s_card* card;

typedef struct 
{
    uint taille;
    card pack_cards;
}s_pack;
typedef s_pack* pack;

typedef struct 
{
    card picked;
    pick next;
}s_pick;
typedef s_pick* pick;

/*  basics functions to handle cards  */

/**
 * @brief Create a Classic Card object 
 * A classic card is a card that has a value in range of 1 to 10
 * @param color 
 * @param number number must be a value in [1,10]
 * @return card 
 */
card CreateClassicCard(color color,uint number);

/**
 * @brief Creates a special card (Jack, Queen, King, Ace).
 *
 * This function generates a special card by assigning its value 
 * and suit based on the provided parameters. Special cards include 
 * the Jack, Queen, King, and Ace, which have specific roles in the game.
 *
 * @param color The suit of the card (e.g., "Hearts", "Diamonds").
 * @param name The special value of the card:
 *             - 11: Jack
 *             - 12: Queen
 *             - 13: King
 *             - 14: Ace
 * @return A `Card` structure initialized with the given suit and type.
 *
 * @note This function assumes the special values are between 11 and 14.
 *       Other values are not handled.
 */
card CreateSpeCard(char* name , color color);


void PrintCard(card c);

/**
 * @brief 
 * @details Compare two cards and return true if :
 * - both cards has the same color 
 * - both cards has the same number
 * @param c1 A card
 * @param c2 A card
 * @return true if both cards have the same color or the number
 * false otherwise
 */
bool AreEqual(card c1 , card c2);

/**
 * @brief Create a pack object
 * A Pack is an object that contain
 * 
 * @return pack 
 */
pack CreatePack();
bool IsEmptyPack(pack p);
pick CreatePick();
bool IsEmptyPick(pick)
#endif