#ifndef THE_SUNDAY_PROGRAMMER_TICTACTOE
#define THE_SUNDAY_PROGRAMMER_TICTACTOE
    enum class ESlotStates  { cross, circle, empty};


    int has_player_won ( ESlotStates player, const ESlotStates board[]);
    int is_player_going_to_win(ESlotStates player, const ESlotStates board[]);
    bool fill_corner(ESlotStates slot, ESlotStates board[]);
    void fill_any(ESlotStates player,  ESlotStates board[]) ;
    void fill_line (int k, ESlotStates player,  ESlotStates board[]);
    bool forced_play(ESlotStates player, ESlotStates opponent,  ESlotStates board[]) ;
    void play_turn(int state,  ESlotStates board[]);
#endif
