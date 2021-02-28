
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch.hpp>
#include "game_helper.hpp"
    TEST_CASE("Test has won", "[check_win]"){
       
    ESlotStates board[9]= { 
        ESlotStates::cross,ESlotStates::empty,ESlotStates::empty,
        ESlotStates::empty,ESlotStates::cross,ESlotStates::empty,
        ESlotStates::empty,ESlotStates::empty,ESlotStates::cross
    };
    REQUIRE(has_player_won(ESlotStates::cross,board) >= 0);
    board[0]=ESlotStates::circle;
    REQUIRE(has_player_won(ESlotStates::cross,board) == -1);
    REQUIRE(is_player_going_to_win(ESlotStates::cross,board) == -1);
    board[0]=ESlotStates::empty;
    REQUIRE(is_player_going_to_win(ESlotStates::cross,board) >=0);
    }
//int main(){}
