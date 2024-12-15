#ifndef _GAME 
#define _GAME
#include "cards.h"

#define MAX_PLAYERS 5
#define HAND_MAX_CARDS 5

typedef struct 
{
    uint nb_cards;
    card* hand;
}player_s;
typedef player_s* player;

typedef struct 
{
    bool ClockWise;
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
 * @brief Initializes a new 8 American game instance.
 * 
 * This function creates and initializes a game structure with the following:
 * - A shuffled deck of cards.
 * - A specified number of players with empty hands.
 * - A random card in the packk is set as the starting card.
 * - The game direction set to clockwise by default.
 * 
 * @return A pointer to the newly created game instance.
 *         Returns NULL if the allocation of memory fails or the input is invalid.
 * 
 * @note 
 * - The caller is responsible for freeing the memory allocated for the game using a dedicated function.
 * - Ensure that `nb_players` is valid (e.g., <= MAX_PLAYERS).
 */
game CreateGame(uint nb_players);



/**
 * @brief Get the Game Pack object
 * This object store all the game cards.
 * @param g the current game
 * @return pack object
 */
pack GetGamePack(const game g);


/**
 * @brief Get the Game Pick object
 * This object will store the remaining cards after distribution
 * and will be use as a pick
 * @param g the current game
 * @return pick 
 */
pick GetGamePick(const game g);


/**
 * @brief Get the Current Card of the game
 * 
 * @param the current game
 * @return a card 
 */
card GetCurrentCard(const game g);


/**
 * @brief Retrieves the current player in the 8 American game.
 * 
 * This function returns a pointer to the player whose turn it currently is in the game.
 * It assumes that the game instance maintains the necessary state to track the current player.
 * 
 * @param g The game instance. Must not be NULL.
 * 
 * @return A pointer to the current player in the game.
 *         Returns NULL if the game instance is invalid or if there are no players.
 * 
 * @note 
 * - The function does not modify the game state.
 * - The returned pointer should not be freed by the caller.
 * - Ensure that the game instance is properly initialized and that the number of players is greater than 0.
 */
player GetCurrentPlayer(const game g);


/**
 * @brief Add a player in a game instance
 * 
 * @param g the current game
 * @return a game with a new player
 */
game AddPlayer(game g);


/**
 * @brief Distribute an equal amount of cards to all players
 * The game pack is supposed shuffled. 
 * The lasting cards after distribution will be put in the pick
 * @param g the pack
 * @param nb_cards the number of cards every player will get 
 * @note nb_cards <= HAND_MAX_CARDS
 */
void Distribute(game g,uint nb_cards);


/**
 * @brief Add a card to a player hand
 * @param p The player that's picking
 * @param g The current game
 *@note The pick and the player hand are uploaded
 */
void Pick(player j,pick p);


/**
 * @brief Plays a basic card (2-10) from the player's hand in the 8 American game.
 * 
 * This function allows a player to play a basic card of a specified value and color.
 * If the player does not possess the specified card, the game state remains unchanged.
 * The old card is automaticallyy to the pack 
 * @param p The player attempting to play the card.
 * @param g The current game instance.
 * @param c The color (suit) of the card to be played (e.g., SPADES, HEARTS).
 * @param value The value of the card to be played (must be between 2 and 10).
 * The old card is automatically added to the pack 
 * @return @return the game with a new current card
 * @note 
 * - The function ensures the game state is not modified if the move is invalid.
 * - The function assumes the validity of the `player` and `game` pointers.
 * - Use this function only for non-special cards (values 2 through 10).
 */
game PlayBasicCard(player p, game g, color c, uint value);


/**
 * @brief Plays a special card (Ace, Jack, Queen, King) from the player's hand in the 8 American game.
 * 
 * This function allows a player to play a special card of a specified type and color.
 * If the player does not possess the specified card, the game state remains unchanged.
 * The old card is automaticallyy to the pack 
 * @param p The player attempting to play the card.
 * @param g The current game instance.
 * @param c The color (suit) of the card to be played (e.g., SPADES, HEARTS).
 * @param name The special card type (one of the following):
 *             - ACE: 1
 *             - JACK: 11
 *             - QUEEN: 12
 *             - KING: 13
 * 
 * @return the game with a new current card
 * 
 * @note 
 * - The function ensures the game state is not modified if the move is invalid.
 * - Special effects associated with the card (if any) should be handled in the game logic.
 * - The function assumes the validity of the `player` and `game` pointers.
 */
game PlaySpecialCard(player p, game g, color c, SpecialCardType name);


/**
 * @brief Advances the turn to the next player in the 8 American game.
 * 
 * This function updates the game state to set the next player as the current player.
 * The direction of play (clockwise or counterclockwise) is taken into account, 
 * and the turn wraps around if the end of the player list is reached.
 * 
 * @param g The game instance. Must not be NULL.
 * 
 * @note 
 * - The function assumes the game instance tracks the current player and the direction of play.
 * - This function modifies the state of the game by updating the current player.
 * - Ensure the game has been initialized with at least one player.
 */
void AdvanceToNextPlayer(game g);


/**
 * @brief Reverses the direction of play in the 8 American game.
 * 
 * This function modifies the game state to switch the direction of play:
 * - If the current direction is clockwise, it will change to counterclockwise.
 * - If the current direction is counterclockwise, it will change to clockwise.
 * 
 * @param g The game instance. Must not be NULL.
 * 
 * @note 
 * - This function directly modifies the `ClockWise` attribute in the game structure.
 * - The direction of play is significant for determining the next player in the game.
*/
void ChangeGameDirection(game g);
#endif