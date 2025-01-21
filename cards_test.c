#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cards.h"

void usage(char *argv[]) {
    fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage(argv);
    }

    fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);

    bool ok = false;
    if(strcmp("CreatePack", argv[1]) == 0) {
        ok = test_CreatePack();
    } else if(strcmp("IsEmptyPack", argv[1]) == 0) {
        ok = test_IsEmptyPack();
    } else if(strcmp("AddCardPack", argv[1]) == 0) {
        ok = test_AddCardPack();
    } else if(strcmp("CreateFullPack", argv[1]) == 0) {
        ok = test_CreateFullPack();
    } else if(strcmp("ShufflePack", argv[1]) == 0) {
        ok = test_ShufflePack();
    } else if(strcmp("FreePack", argv[1]) == 0) {
        ok = test_FreePack();
    } else if(strcmp("RemoveCardPack", argv[1]) == 0) {
        ok = test_RemoveCardPack();
    } else {
        fprintf(stderr, "Error: test \"%s\" not found!\n", argv[1]);
        exit(EXIT_FAILURE);
    } 
    if (ok) {
        fprintf(stderr, "Test \"%s\" finished: SUCCESS\n", argv[1]);
        return EXIT_SUCCESS;
    } else {
        fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
        return EXIT_FAILURE;
    }
}