#FALP Fleet Battle 2 Tests © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

get_directory_property(MYDEFS COMPILE_DEFINITIONS)

add_executable(playerTests
#                testAddSunkShips.cpp
#                testCheckOtherBoard.cpp
#                testCheckOwnBoard.cpp
#                testCheckShoot.cpp
#                testGetDeployedShipsCount.cpp
#                testGetSunkShipsCount.cpp
#                testIsShipSunk.cpp
                testPlayerConstructor.cpp
#                testUpdateOtherBoard.cpp
              )

target_link_libraries(playerTests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(playerTests PUBLIC  utilities)
target_link_libraries(playerTests PUBLIC  playerBoard)
target_link_libraries(playerTests PUBLIC  opponentBoard)
target_link_libraries(playerTests PUBLIC  player)

add_test(NAME playerTests COMMAND playerTests)