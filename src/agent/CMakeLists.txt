#FALP Fleet Battle 2 Tests © 2023 by Antlampas is licensed under CC BY-SA 4.0. To view a copy of this license, visit http://creativecommons.org/licenses/by-sa/4.0/

get_directory_property(MYDEFS COMPILE_DEFINITIONS)

add_executable(agentTests
               testConstructor.cpp
               testFunctor.cpp
               testReadMessage.cpp
               testWriteMessage.cpp
)

target_link_libraries(agentTests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(agentTests PUBLIC  utilities agent)

add_test(NAME agentTests COMMAND agentTests)

