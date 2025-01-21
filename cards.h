#ifndef _CARDS
#define _CARDS
#include <stdbool.h>

typedef unsigned int uint;

/**
 * @enum color
 * @brief Enumeration for the colors of the cards.
 */
typedef enum 
{
    SPADES, 
    HEARTS, 
    DIAMONDS, 
    CLUBS,
    NB_COLORS
} color;


/**
 * @enum SpecialCardType
 * @brief Enumeration for the types of special cards.
 */
typedef enum {
    ACE = 1,
    JACK = 11,
    QUEEN = 12,
    KING = 13,
    NB_NAMES = 4
}SpecialCardType;

/**
 * @struct BaseCard
 * @brief Represents a standard card (non-special).
 */
typedef struct 
{
    uint value;
    color color;
}BaseCard;

/**
 * @struct SpecialCard
 * @brief Represents a special card (Ace, Jack, Queen, King).
 */
typedef struct 
{
    SpecialCardType name;
    color color;
}SpecialCard;

/**
 * @struct s_card
 * @brief Represents a card, which can either be a base card or a special card.
 */
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

/**
 * @struct s_pack
 * @brief Represents a pack of cards.
 */
typedef struct 
{
    uint taille;
    card* pack_cards;
}s_pack;
typedef s_pack* pack;

/**
 * @struct s_pick
 * @brief Represents a node in a linked list of picked cards.
 */
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
 * - both cards are special and has the same name
 * - both cards are special and has the same color
 * - cards have different types but have the same color
 * @param c1 A card
 * @param c2 A card
 * @return true if both cards are equivalent
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
 * @return A pack that can store 52 cards.
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
 * @param p A pack where to add the card
 * @param c the card to be added
 * @return a pack with the added card
 */
pack AddCardPack(pack p,card c);



/**
 * @brief remove  a card from the pack
 * 
 * @param p 
 * @param c 
 * @return pack 
 */
pack RemoveCardPack(pack p, card c);



/**
 * @brief Create a pack object
 * with the 52 cards composing a crazy eight game (without Jokers)
 * @return pack
 */
pack CreateFullPack();


/**
 * @brief Shuffle a pack
 * @param p 
 * @return a pack shuffled
 */
pack ShufflePack(pack p);

/**
 * @brief Free the memory allocated for a Pack
 * @param p a pack  
 */
void FreePack(pack p);


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
bool IsEmptyPick(pick p);


/**
 * @brief add a card in the pick
 * 
 * @param p A pack where to add the card
 * @param c the card to be added
 * @return a pick with the new added card
 */
pick AddCardPick(pick p , card c );


/**
 * @brief Pick a card in a pick 
 * The pick given is automatically uploaded 
 * @param p a pick
 * @return the card on top of the pick 
 */
card PickCard(pick p);


/**
 * @brief Free the memory allocated for the pick 
 * @param p a pick
 */
void FreePick(pick p);
#endif