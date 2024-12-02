#ifndef CARDS
#define CARDS
#include <stdbool.h>



typedef enum 
{
    SPADES, 
    HEARTS, 
    DIAMONDS, 
    CLUBS
} color;
typedef struct 
{
    int value;
    color col;
}base_card;
typedef struct 
{
    bool is_named;
    union
    {
    base_card b_card;
    char* name;
    }c_type;
}card;
typedef struct clist
{
    card* c;
    struct clist* next;
    struct clist* prev;
}clist;
typedef struct 
{
    int nb_cards;
    clist* first;
}deck;
        
card* createclassiccard(int value, color col);
card* createnamedcard(const char* name);

deck* createonecarddeck(card* c);

void addcardbefore(clist* l, card* newcard);

void freedeck(deck* d);

card* removecard(clist* l);

clist** distribute(int nbplayers, deck* d); 

void fprintdeck (const char* filename, deck* d);

#endif