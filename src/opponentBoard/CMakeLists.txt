#FALP Fleet Battle 2 Tests © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

get_directory_property(MYDEFS COMPILE_DEFINITIONS)

add_executable(opponentBoardTests
                testConstructor.cpp
                testGetBoardStatus.cpp
                testGetSquareStatus.cpp
                testSetSquareStatus.cpp
              )

target_link_libraries(opponentBoardTests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(playerBoardTests   PUBLIC  utilities)
target_link_libraries(opponentBoardTests PUBLIC  opponentBoard)

add_test(NAME opponentBoardTests COMMAND opponentBoardTests)