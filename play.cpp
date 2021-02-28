#include "game.hpp"
#include "stdio.h"
char print_state(ESlotStates s){
   switch(s){
	   case ESlotStates::empty: return ' '; break;
	   case ESlotStates::circle: return 'o'; break;
	   case ESlotStates::cross: return 'x'; break;
   }
   return ' ';
}
void display(const ESlotStates board[])
{
  for( int start=0;start<9; start+=3){
  auto x1 = print_state(board[start]);
  auto x2 = print_state(board[start + 1]);
  auto x3 = print_state(board[start + 2]);

  printf("%c|%c|%c\n",x1,x2,x3);
  printf("-----\n");
  }
}
int main(int argc, char *argv[]){
  ESlotStates board[9] = {
    ESlotStates::empty,ESlotStates::empty,ESlotStates::empty,
    ESlotStates::empty,ESlotStates::empty,ESlotStates::empty,
    ESlotStates::empty,ESlotStates::empty,ESlotStates::empty	

  };
  int state = 0;
  bool computer = true;
  if (argc > 1 && argv[1][0]=='-' && argv[1][1]==  'h') computer = false;
  if (computer) {
    play_turn(state, board);
  }
  display (board);
  ESlotStates winning_player=ESlotStates::empty;
  for(; state < 8 ; ){
    auto c = getchar();
    if (c >= '0' && c < '9') {
      int index = c - '0';
      if (board[index] == ESlotStates::empty){
	board[index] = ESlotStates::cross;
	if (has_player_won(ESlotStates::cross,board)>=0){
	  winning_player = ESlotStates::cross;
	  break;
	}
	state += 2;
	play_turn(state,board);
	display(board);
	if (has_player_won(ESlotStates::circle,board)>=0){
	  winning_player = ESlotStates::circle;
	  break;
	}
      }

    }
    if (!computer && winning_player==ESlotStates::empty) {
      fill_any(ESlotStates::cross,board);
      if( has_player_won(ESlotStates::cross,board)>=0)
	winning_player = ESlotStates::cross;
    } 

    if (winning_player==ESlotStates::cross) {
      printf ("Congratulations! You have won\n");
    } else if (winning_player==ESlotStates::circle) {
      printf("Computer has won");
    }
  }
  return 0;

}
