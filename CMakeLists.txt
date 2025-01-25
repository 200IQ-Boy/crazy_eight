cmake_minimum_required(VERSION 3.10)

#Nom du projet
    project(GameExecutable)

        include(CTest)
            enable_testing()

                set(CMAKE_C_FLAGS "-std=c99 -Wall --coverage -g")

#création des librairies
                    add_library(cards_lib cards.c)

#ajout des exécutables
add_executable(eight - american eight - american.c)
add_executable(cards_test cards_test.c)

#ajout des librairies aux exécutables
target_link_libraries(eight - american cards_lib)
target_link_libraries(cards_test cards_lib)

#ajout des tests
add_test(test_CreateClassicCard./ cards_test CreateClassicCard)
add_test(test_CreateSpeCard./ cards_test CreateSpeCard)
add_test(test_FreeCard./ cards_test FreeCard)
add_test(test_AreEquivalent./ cards_test AreEquivalent)
add_test(test_IsEmptyPack./ cards_test IsEmptyPack)
#add_test(test_AddCardPack./ cards_test AddCardPack)
#add_test(test_RemoveCardPack./ cards_test RemoveCardPack)
#add_test(test_ShufflePack./ cards_test ShufflePack)
#add_test(test_CreateFullPack./ cards_test CreateFullPack)
#add_test(test_ShufflePack./ cards_test ShufflePack)
#add_test(test_FreePack./ cards_test FreePack)
#add_test(test_CreatePick./ cards_test CreatePick)
#add_test(test_IsEmptyPick./ cards_test IsEmptyPick)
#add_test(test_AddCardPick./ cards_test AddCardPick)
#add_test(test_PickCard./ cards_test PickCard)
#add_test(test_FreePick./ cards_test FreePick)
