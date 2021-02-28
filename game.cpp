#include "game_helper.hpp"

    const int lines[8][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6}
    };

    int has_player_won ( ESlotStates player, const ESlotStates board[]){

        bool found = false;
        int retval = -1;
        for (int i = 0; i<8 && !found; ++i ){
            found = true;
            for(auto x : lines[i]){
                if (board[x]!=player) found=false;

            }
            if (found) retval= i;
        }
        return retval;
    }

    int is_player_going_to_win(ESlotStates player, const ESlotStates board[]){

        
        int retval = -1;
        for (int i = 0; i<8 && retval == -1 ; ++i ){
            int count = 0;
            for(auto x : lines[i]){
                if (board[x]==player) ++count;
		else if (board[x]!=ESlotStates::empty) count=3;

            }
            if (count==2) retval = i;
        }
        return retval;
    }
    bool fill_corner(ESlotStates slot, ESlotStates board[]){
        int corners[]={0,2,6,8};
        for(int i =0; i<4 ; ++i){
            if (board[corners[i]]==ESlotStates::empty){
                board[corners[i]]=slot;
                return true;
            }
        }
        return false;
    }
    void fill_any(ESlotStates player,  ESlotStates board[])
    {
        for (int i=0; i< 9; ++i){
            if(board[i]==ESlotStates::empty){
                board[i] = player;
                break;
            }
        }

    }
    void fill_line (int k, ESlotStates player,  ESlotStates board[]){
         auto const& line = lines[k];
         for (int i=0; i<3; ++i){
            if(board[line[i]] == ESlotStates::empty){
                board[line[i]] = player;
                break;   
              }
            }
        }
    bool forced_play(ESlotStates player, ESlotStates opponent,  ESlotStates board[])
    {

                int k = is_player_going_to_win(player,board);
                if (k >=0){
                    fill_line(k,player,board);
                    return true;
                }
               k = is_player_going_to_win(opponent,board);
                if (k >=0){
                    fill_line(k,player,board);
                    return true;
                }
                return false;
    }
    void play_turn(int state,  ESlotStates board[]){
        switch (state){
        case 0: 
            board[4]=ESlotStates::circle;
            break;
        case 1:
            if (board[4]==ESlotStates::empty) {
                board[4]=ESlotStates::cross;
            } else {
                board[0]=ESlotStates::cross;
            }
            break;
        case 2:
            {
              int middle[]= {1,3,5,7};
              int diagnol[]= {8,8,0,0};
              for(int i=0; i < 4; ++i){
                  if (board[middle[i]] != ESlotStates::empty){
                      board[diagnol[i]] = ESlotStates::circle;
                      return;
                  }
              }
              fill_corner(ESlotStates::circle,board);
              break;
              }
        case 3:
        case 7:
        case 5:
            {

                if (forced_play(ESlotStates::cross,ESlotStates::circle,board))
                    break;
                else if (fill_corner(ESlotStates::cross,board)) 
                    break;
                else fill_any(ESlotStates::cross,board);
                break;
            }            
        case 4:
        case 8:
        case 6:
        {
                if (forced_play(ESlotStates::circle,ESlotStates::cross,board))
                    break;
                else if (fill_corner(ESlotStates::circle,board)) 
                    break;
                else fill_any(ESlotStates::circle,board);
                break;

        }
                
        }

    }
 
