/*
 *  A GameState represents the board, whose turn it is, and in general,
 *  everything possible about the state of the game. It should not include
 *  any sort of GAME logic, however, it should include any functions that
 *  manipulate or update the game state. So, for example, it shouldn't do
 *  error-checking when the player makes an illegal move, but it should
 *  contain the function the change the game state after it is determined
 *  that the move is legal.
 */
#include <stdbool.h>

/**
 *  Abstraction of the coordinates of the board. The numbering starts on
 *  the bottom left corner of the board at (0,0) and behaves like a normal
 *  x-y graph.
 */
typedef struct {
  int x;
  int y;
} Coord;

/**
 *  The most essential GameState object encapsulates all the data of a
 *  state of a game.
 */
typedef struct {
  
} GameState;

/**
 *  Returns a 2-dimensional array representing the board. True values
 *  indicate that there is a ship/target at the location, while false
 *  values indicate that there is not.
 */
bool **getBoard(GameState *state, Player *player);
