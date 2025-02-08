#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "cards.h"

int main() {
    // Test : Création et affichage de cartes classiques
    printf("=== Test : Création et affichage de cartes classiques ===\n");
    card classic_card = CreateClassicCard(HEARTS, 7);
    PrintCard(classic_card);
    FreeCard(classic_card);

    // Test : Création et affichage de cartes spéciales
    printf("\n=== Test : Création et affichage de cartes spéciales ===\n");
    card special_card = CreateSpeCard(QUEEN, SPADES);
    PrintCard(special_card);
    FreeCard(special_card);

    // Test : Vérification d'équivalence et d'égalité
    printf("\n=== Test : Vérification d'équivalence et d'égalité ===\n");
    card card1 = CreateClassicCard(CLUBS, 8);
    card card2 = CreateClassicCard(CLUBS, 8);
    card card3 = CreateSpeCard(ACE, CLUBS);

    printf("Card 1 and Card 2 are %s\n", AreEqual(card1, card2) ? "equal" : "not equal");
    printf("Card 1 and Card 3 are %s\n", AreEquivalent(card1, card3) ? "equivalent" : "not equivalent");

    FreeCard(card1);
    FreeCard(card2);
    FreeCard(card3);

    // Test : Création d'un paquet complet
    printf("\n=== Test : Création d'un paquet complet ===\n");
    pack full_pack = CreateFullPack();
    printf("Full pack created with %d cards\n", full_pack->taille);

    // Test : Mélange d'un paquet
    printf("\n=== Test : Mélange du paquet ===\n");
    ShufflePack(full_pack);
    printf("Pack shuffled.\n");

    // Affichage des 5 premières cartes du paquet mélangé
    printf("Top 5 cards after shuffle:\n");
    for (int i = 0; i < 5; i++) {
        PrintCard(full_pack->pack_cards[i]);
    }

    // Test : Retirer une carte du paquet
    printf("\n=== Test : Retirer une carte du paquet ===\n");
    card card_to_remove = CreateClassicCard(DIAMONDS, 5);
    if (RemoveCardPack(full_pack, card_to_remove)) {
        printf("Card removed successfully.\n");
    } else {
        printf("Card not found in the pack.\n");
    }
    FreeCard(card_to_remove);

    // Test : Ajout d'une carte au paquet
    printf("\n=== Test : Ajout d'une carte au paquet ===\n");
    card new_card = CreateSpeCard(KING, HEARTS);
    if (AddCardPack(full_pack, new_card)) {
        printf("Card added successfully. Pack size is now %d.\n", full_pack->taille);
    } else {
        printf("Failed to add card to the pack.\n");
    }

    // Libération du paquet
    FreePack(full_pack);

    // Test : Manipulation de la pioche
    printf("\n=== Test : Manipulation de la pioche ===\n");
    pick my_pick = CreatePick();
    card pick_card1 = CreateClassicCard(SPADES, 9);
    card pick_card2 = CreateSpeCard(JACK, DIAMONDS);

    my_pick = AddCardPick(my_pick, pick_card1);
    my_pick = AddCardPick(my_pick, pick_card2);

    printf("Top card in the pick:\n");
    PrintCard(my_pick->picked);

    // Pioche d'une carte
    card picked_card = PickCard(&(my_pick));
    printf("Card picked from the pick:\n");
    PrintCard(picked_card);
    FreeCard(picked_card);

    // Libération de la pioche
    FreePick(my_pick);

    // Test final : Vérification de la mémoire
    printf("\n=== Test : Tous les objets ont été correctement libérés ===\n");
    printf("Tous les tests sont terminés.\n");

    return EXIT_SUCCESS;
}
