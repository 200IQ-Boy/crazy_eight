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

int HasSpecialCard(player p, color color, SpecialCardType name)
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
                    return i;
                }
            }
        }
    }
    return -1;
}

int HasBasicCard(player p, color color, uint value)
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
                    return i;
                }
            }
        }
    }
    return -1;
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
    g->current_card = NULL;
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
    return g->players[g->id_current_player];
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

pick transferPackToPick(pick p, pack pack)
{
    // test parameters validity
    assert(p != NULL);
    assert(pack != NULL);

    for(int i = 0; i < pack->taille; i++)
    {
        p = AddCardPick(p,pack->pack_cards[i]);
        pack = removeCardPack(pack,pack->pack_cards[i]);

    }
    return p;
}

void Distribute(game g,uint nb_cards) 
{
    //test parameters validity
    assert(g != NULL);
    assert(nb_cards < HAND_MAX_CARDS);
    assert(g->nb_players <= MAX_PLAYERS && g->nb_players > 1);
    assert(g->pack->taille == 52);
    
    int k = 0;
    for(int i = 0; i < g->nb_players; i++)
    {
        g->players[i]->nb_cards = nb_cards;
        for(int j = 0; j < nb_cards; j++)
        {
            g->players[i]->hand[j] = g->pack->pack_cards[k];
            k++;
            // update the state of the pack after the card been distribute
            g->pack = removeCardPack(g->pack,g->players[i]->hand[j]);
        }
    }

    // set the current card
    g->current_card = g->pack->pack_cards[k];
    g->pack = removeCardPack(g->pack,g->pack->pack_cards[k]);

    // put the remaining cards in the pick
    g->pick = transferPackToPick(g->pick,g->pack);
}

void Pick(player j,pick p) 
{
    assert(p != NULL);
    assert(j != NULL);
    
    j->hand[j->nb_cards] = PickCard(p);
    j->nb_cards++;
}

void ChangeGameDirection(game g)
{
    assert(g != NULL);
    g->ClockWise = !g->ClockWise;
}

void AdvanceToNextPlayer(game g) 
{
    assert(g != NULL);
    if(g->ClockWise)
    {
        g->id_current_player = (g->id_current_player + 1)%g->nb_players;
    }
    else 
    {
        if(g->id_current_player == 0)
        {
            g->id_current_player = g->nb_players - 1;
        }
        else 
        {
            g->id_current_player--;
        }
    }
}

game PlayBasicCard(player p, game g, color c, uint value) 
{
    assert(p != NULL);
    assert(g != NULL);
    assert(g->current_card != NULL);
    
    int id = HasBasicCard(p,c,value);
    if(id != -1)
    {
        g->pack =  AddCardPack(p,g->current_card);
        for(int i = id ; i < p->nb_cards -1 ; i++)
        {
            p->hand[i] = p->hand[i+1];
        }
        p->nb_cards--;
    }
}

game PlaySpecialCard(player p, game g, color c, SpecialCardType name)
{
    assert(p != NULL);
    assert(g != NULL);
    assert(g->current_card != NULL);

    int id = HasSpecialCard(p,c,name);
    if(id != -1)
    {
        g->pack =  AddCardPack(p,g->current_card);
        for(int i = id ; i < p->nb_cards -1 ; i++)
        {
            p->hand[i] = p->hand[i+1];
        }
        p->nb_cards--;
    }
}