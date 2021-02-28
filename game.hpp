#ifndef THE_SUNDAY_PROGRAMMER_TICTACTOE
#define THE_SUNDAY_PROGRAMMER_TICTACTOE
    enum class ESlotStates  { cross, circle, empty};
    extern const int lines[][3] ;
    void play_turn(int state,  ESlotStates board[]);
    int has_player_won ( ESlotStates player, const ESlotStates board[]);
#endif
