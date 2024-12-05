#ifndef _CARDS
#define _CARDS
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
// special  cards 
typedef enum {
    ACE = 1,
    JACK = 11,
    QUEEN = 12,
    KING = 13,
    NB_NAMES = 4
}SpecialCardType;

typedef struct 
{
    uint value;
    color color;
}BaseCard;

typedef struct 
{
    SpecialCardType name;
    color color;
}SpecialCard;

typedef struct 
{
    bool is_special;
    union
    {
    BaseCard b_card;
    SpecialCard s_card;
    }card_type;
}s_card;
typedef s_card* card;

typedef struct 
{
    uint taille;
    card pack_cards;
}s_pack;
typedef s_pack* pack;

struct s_pick
{
    card picked;
    struct s_pick* next;
};
typedef struct s_pick s_pick;
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
card CreateSpeCard(SpecialCardType name , color color);


/**
 * @brief display the given card in shell
 * @param c 
 */
void PrintCard(card c);


/**
 * @brief 
 * @details Compare two cards and return true if :
 * - both cards are basic and has the same color
 * - both cards are basic and has the same number
 * - both cards are special and has name
 * @param c1 A card
 * @param c2 A card
 * @return true if both cards have the same color or the number
 * false otherwise
 */
bool AreEquivalent(card c1 , card c2);

/**
 * @brief Free the allocated memory for the card
 * 
 * @param c the card
 */
void FreeCard(card c);

/**
 * @brief Generates a complete deck of cards.
 * @details This function creates a standard pack aimed to contain 52 playing cards,
 * including all suits (Hearts, Diamonds, Clubs, Spades) and
 * values (2 to 10, Jack, Queen, King, Ace).
 * @return A pack that can store 52 cards in a shuffled oreder.
 * @note The array provided must be large enough to hold all 52 cards (excluding joker).
 */
pack CreatePack();


/**
 * @brief check if the pack is empty
 * 
 * @param p 
 * @return true if the pack is empty
 * false otherwise
 */
bool IsEmptyPack(pack p);


/**
 * @brief add a card in the pack
 * 
 * @param p A pack where to add the card
 * @param c the card to be added
 * @return pack 
 */
pack AddCardPack(pack p,card c);


/**
 * @brief Create an empty Pick object
 * that will be use to store the  card remaining after
 * the split of cards to players
 * @return pick 
 */
pick CreatePick();


/**
 * @brief check if the pick is empty
 * @return true if the pick is empty
 * false otherwise
 */
bool IsEmptyPick(pick);


/**
 * @brief add a card in the pack
 * 
 * @param p A pack where to add the card
 * @param c the card to be added
 * @return pack 
 */
pick AddCardPick(pick p , card c );
#endif