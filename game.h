#ifndef _GAME 
#define _GAME
#include "cards.h"

typedef struct 
{
    uint nb_cards;
    card* hand;
}player_s;
typedef player_s* player;

typedef struct 
{
    card current_card;
    uint nb_players;
    player* players;
    pack pack;
    pick pick;
}game_s;
typedef game_s* game;


/* functions to manipulate game instances  */
/**
 * @brief Create a player 
 * The player object can represent both bot and actual players
 * @return a player 
 */
player CreatePlayer();


/**
 * @brief Check if a given player have a certain card
 *@
 * @param p the player
 * @param color The suit of the card (e.g., "Hearts", "Diamonds")
 * @param name The special value of the card:
 *             - 11: Jack
 *             - 12: Queen
 *             - 13: King
 *             - 14: Ace
 * @return true if he has it
 * false otherwise 
 */
bool HasSpecialCard(player p, color color, SpecialCardType name);


/**
 * @brief Check if a given player have a certain card
 *@
 * @param p the player
 * @param color The suit of the card (e.g., "Hearts", "Diamonds")
 * @param value The value of the card in range of 2 to 10
 * @return true if he has it
 * false otherwise 
 */
bool HasBasicCard(player p, color color, uint value);


/**
 * @brief Create a new game instance for the 8 American card game.
 * 
 * This function initializes all components of the game, including the players, 
 * the deck of cards (pack), the pile of picked cards (pick), and the first card 
 * to be played (current_card). It allocates memory for the game structure and its 
 * associated players and cards.
 * 
 * @return A pointer to the newly created game instance.
 *         Returns NULL in case of memory allocation failure.
 * 
 * @note The caller is responsible for freeing the memory associated with the 
 *       game instance using an appropriate cleanup function to avoid memory leaks.
 */
game CreateGame();
#endif