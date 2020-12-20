
#ifndef _GAME_CORE
#define _GAME_CORE

#include <stdbool.h>

// UNKNOWN represents a square that the player has neither marked nor stepped on
extern const int UNKNOWN;

// MARKED represents a square that the player has marked
extern const int MARKED;

// MINE represents a square that contains a mine
extern const int MINE;

// player_board points to the first field of the Minesweeper board. The board is
//   stored as a (flat) 1D-array with width * height elements. Squares are
//   stored in the following order (column,row):
// [0,0], [1,0], [2,0], ..., [width-1,0], [0,1], [1,1], ..., [width-1,height-1]
extern int *player_board;

// game_start(width, height) creates a randomly generated complete board as well
//   as a player board, both with given width and height. All squares in the
//   player board are initizlized to UNKNOWN. game_end has be called before
//   exiting the game.
// requires: width and height > 0
// time: O(w*h)
void game_start(const int width, const int height);

// game_start_seed(width, height, seed) creates a randomly generated complete
//   board as well as a player board, both with given width and height. All
//   squares in the player board are initizlized to UNKNOWN. Using the same
//   parameters width, height, and seed guarantees creation of the same board.
//   game_end has be called before exiting the game.
// time: O(w*h)
void game_start_seed(const int w, const int h, const int seed);

// game_end() ends the game and releases all resources.
// effects: invalidates player_board
// time: O(1)
void game_end(void);

// mine_at(c, r) returns true if there is a mine at ([c]olumn,[r]ow), and false
//   otherwise. The function also returns false if ([c],[r]) is outside of the
//   board.
// time: O(1)
bool mine_at(const int c, const int r);

// board_complete() returns true if all squares with mines are marked and all
//   marked squares contain mines, and false otherwise.
// time: O(w*h)
bool board_complete(void);

// board_debug() prints the complete board. THIS FUNCTION IS FOR DEBUG PURPOSES
//   ONLY. YOU MAY USE IT BUT YOU HAVE TO REMOVE ALL CALLS TO IT BEFORE
//   SUBMITTING YOUR CODE.
// effects: creates ouput
// time: O(w*h)
void board_debug(void);

#endif // GAME_CORE_H