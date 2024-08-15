#FALP Fleet Battle 2 Tests © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

get_directory_property(MYDEFS COMPILE_DEFINITIONS)


set(libraries "")

if("${MYDEFS}" MATCHES "TESTOPPONENTBOARD")
    add_subdirectory(opponentBoard opponentBoard)
    list(APPEND libraries "opponentBoardTests")
endif()
if("${MYDEFS}" MATCHES "TESTPLAYER")
    add_subdirectory(player player)
    list(APPEND libraries "playerTests")
endif()
if("${MYDEFS}" MATCHES "TESTPLAYERBOARD")
    add_subdirectory(playerBoard playerBoard)
    list(APPEND libraries "playerBoardTests")
endif()
if("${MYDEFS}" MATCHES "TESTUTILITIES")
    add_subdirectory(utilities utilities)
    list(APPEND libraries "utilitiesTests")
endif()