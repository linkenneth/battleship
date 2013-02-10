/*
 *  This should include any functions that manipulate the game state as
 *  well as other general utility functions. So, for example, it shouldn't
 *  do error-checking when the player makes an illegal move, but it should
 *  contain the function the change the game state after it is determined
 *  that the move is legal.
 */

/* === BEGIN HEADERS === */
#ifndef _UTIL_H
#define _UTIL_H
#include "gameState.h"
#include <stdlib.h>
/* === END HEADERS === */

/**
 *  Returns a 2-dimensional array representing the board. True values
 *  indicate that there is a ship/target at the location, while false
 *  values indicate that there is not.
 */
bool **getBoard(struct GameState *state, struct Player *player);

int randInt(int min, int max) {
  return rand() % (max - min) + min;
}

#endif
