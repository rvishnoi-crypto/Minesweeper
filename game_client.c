#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "game_core.h"

//helper 3
// valid (col, row) checks if the square is in the range 
bool valid(int col, int row, int width, int height) 
{ 
    // Returns true if row number and column number 
    // is in range 
    return (row >= 0) && (row < height) && 
           (col >= 0) && (col < width); 
} 


//helper 2
//search_bomb(c,r,width,height) searches for bombs in the vicinit
// printf("%d %d",col,row);
// printf ("1");

int search_bomb(int col, int row, int width,int height)                    
{ 
      int count = 0; 
         if (valid(col-1,row,width,height) == true) 
        {    if (mine_at (col-1, row) == true) {
          count++; }
        } 
  

        if (valid (col+1, row,width,height) == true) 
        {  if (mine_at (col+1, row) == true) {
               count++; }
        } 
  
        if (valid(col, row+1,width,height) == true) 
        {  if (mine_at (col, row+1) == true) {
               count++; }
        } 
  

        if (valid (col, row-1,width,height) == true) 
        {  if (mine_at (col, row-1) == true) {
               count++; }
        } 

        if (valid(col-1, row+1,width,height) == true) 
        { if (mine_at (col-1,row+1 ) == true) {
               count++; }
        } 
  

        if (valid(col-1, row-1,width,height) == true) 
        { if (mine_at (col-1, row-1) == true) {
               count++; }
        } 
  

        if (valid (col+1, row+1,width,height) == true) 
        {  if (mine_at (col+1, row+1) == true) {
               count++; }
        } 
  

        if (valid (col+1, row-1,width,height) == true) 
        {  if (mine_at (col+1, row-1) == true) {
               count++; }
        } 

 return count; 
} 



// helper 1 
// updates the boards based on player choice
void update(const int c, const int r, const int width,const int height) {

  player_board[width*r+c]=search_bomb(c,r,width,height);
  }


bool step(const int c, const int r, const int width, const int height) {  
  int spot = player_board [width*r+c];
  if (spot==MARKED || spot!=UNKNOWN){
    return false;
  }  
  update(c,r,width,height);
  return mine_at(c, r);
}

bool mark(const int c, const int r, int width, int height) {
  int spot = player_board [width*r+c];
  if (spot==UNKNOWN){
    player_board [width*r+c]= MARKED;
  }
  else if (spot==MARKED){
    player_board [width*r+c]= UNKNOWN;
  }
 
  
  return board_complete();
}

void print(int width, int height) {
  // Now we print the player board 
  //board_debug();
  for (int i=0 ; i<=height-1; ++i){
    for (int j=0; j<=width-1; ++j){
      if (player_board[width*i+j]==UNKNOWN){
        if (j==width-1){
          printf("_");
        }
        else{
        printf("_ ");}
      }
      else if (player_board[width*i+j]==MARKED){
        if (j==width-1){
          printf("P");
        }
        else{
        printf("P ");}
          
      }
      else if (player_board[width*i+j]==MINE){
        if (j==width-1){
          printf("X");
        }
        else {printf("X ");}
      }
      else {
        if (j==width-1){
          printf("%d",player_board[width*i+j]);
        }
       else{ printf("%d ",player_board[width*i+j]);}
      }
    }
    printf("\n");
  } 
  //Now printing the last line
  for (int m=0; m<=width-1; ++m){
     if (m==width-1){
          printf("=");}
    else{    
    printf("==");}
  }
  printf("\n");
  
  
  
}


bool step_adv(const int c, const int r, const int width, const int height) {

  
  int spot = player_board [width*r+c];
  if (spot==MARKED || spot!=UNKNOWN){
     return false;
   }  

  update(c,r,width,height);
  
  if (search_bomb(c,r,width,height)==0){
    if (valid (c-1,r,width,height) == true){
    step_adv(c-1,r,width,height);}
    if (valid (c+1,r,width,height) == true){
    step_adv(c+1,r,width,height);}
    if (valid (c,r+1,width,height) == true){
    step_adv(c,r+1,width,height);}
    if (valid (c,r-1,width,height) == true){
    step_adv(c,r-1,width,height);}
    if (valid (c-1,r+1,width,height) == true){
    step_adv(c-1,r+1,width,height);}
    if (valid (c-1,r-1,width,height) == true){
    step_adv(c-1,r-1,width,height);}
    if (valid (c+1,r+1,width,height) == true){
    step_adv(c+1,r+1,width,height);}
    if (valid (c+1,r-1,width,height) == true){
    step_adv(c+1,r-1,width,height);}
  }

  return mine_at(c, r);
}