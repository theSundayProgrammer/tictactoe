
#ifndef THE_SUNDAY_PROGRAMMER_TICTACTOE_HELPER
#define THE_SUNDAY_PROGRAMMER_TICTACTOE_HELPER
#include "game.hpp"

    int is_player_going_to_win(ESlotStates player, const ESlotStates board[]);
    bool fill_corner(ESlotStates slot, ESlotStates board[]);
    void fill_any(ESlotStates player,  ESlotStates board[]) ;
    void fill_line (int k, ESlotStates player,  ESlotStates board[]);
    bool forced_play(ESlotStates player, ESlotStates opponent,  ESlotStates board[]) ;
#endif
