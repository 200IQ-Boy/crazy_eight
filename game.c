#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include <assert.h>

player CreatePlayer() 
{
    player p = malloc(sizeof(player_s));

    if(p == NULL)
    {
        fprintf(stderr,"Failed to create a new playyer\n");
        exit(EXIT_FAILURE);
    }
    p->nb_cards = 0;
    p->hand = malloc(HAND_MAX_CARDS*sizeof(card));
    if(p->hand == NULL)
    {
        fprintf(stderr,"Failed to create a new player\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

bool HasSpecialCard(player p, color color, SpecialCardType name)
{
    // test parameters validity 
    assert(p != NULL);
    assert(color < NB_COLORS && color >= SPADES);

    for(int i = 0; i < p->nb_cards; i++)
    {
        if(p->hand[i] != NULL)
        {
            if(!p->hand[i]->is_special)
            {
                if(p->hand[i]->card_type.s_card.color == color && p->hand[i]->card_type.s_card.name == name)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool HasBasicCard(player p, color color, uint value)
{
    // test parameters validity 
    assert(p != NULL);
    assert(value < 11 && value > 1);
    assert(color < NB_COLORS && color >= SPADES);

    for(int i = 0; i < p->nb_cards; i++)
    {
        if(p->hand[i] != NULL)
        {
            if(!p->hand[i]->is_special)
            {
                if(p->hand[i]->card_type.b_card.color == color && p->hand[i]->card_type.b_card.value == value)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

game CreateGame(uint nb_players)
{
    if(nb_players > MAX_PLAYERS)
    {
        fprintf(stderr,"A game can't have more than 5 players\n");
        exit(EXIT_FAILURE);
    }

    pack pack = ShufflePack(CreateFullPack());
    pick pick = CreatePick();

    game g = malloc(sizeof(game_s));
    if(g == NULL)
    {
        fprintf(stderr,"Failed to create a new game\n");
        exit(EXIT_FAILURE);
    }

    g->ClockWise = true;
    g->nb_players = nb_players;
    g->pack = pack;
    g->pick = pick;
    g->id_current_player = 0;
    g->players = malloc(nb_players*sizeof(player));
    if(g->players == NULL)
    {
        free(g);
        fprintf(stderr,"Failed to create a new game\n");
        exit(EXIT_FAILURE);
    }
    return g;
}

pack GetGamePack(const game g) 
{
    assert(g != NULL);
    return g->pack;
}

pick GetGamePick(const game g)
{
    assert(g != NULL);
    return g->pick;
}

card GetCurrentCard(const game g) 
{
    assert(g != NULL);
    return g->current_card;
}

player GetCurrentPlayer(const game g)
{
    assert(g != NULL);
    return g->players[0];
}

game AddPlayer(game g,player p) 
{
    if(g == NULL || p == NULL)
    {
        fprintf(stderr,"Null,player or game given to the function\n");
        exit(EXIT_FAILURE);
    }
    if(g->nb_players < MAX_PLAYERS)
    {
        g->players[g->nb_players] = p;
        g->nb_players++;
    }
}

void Distribute(game g,uint nb_cards) 
{
    //test parameters validity
    assert(g != NULL);
    assert(nb_cards < HAND_MAX_CARDS);
    assert(g->nb_players <= MAX_PLAYERS && g->nb_players > 1);
    int k = 0;
    for(int i = 0; i < g->nb_players; i++)
    {
        g->players[i]->nb_cards = nb_cards;
        for(int j = 0; j < nb_cards; j++)
        {
            g->players[i]->hand[j] = 
        }
    }
}