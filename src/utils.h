/*
 *  This should include any functions that manipulate the game state as
 *  well as other general utility functions. So, for example, it shouldn't
 *  do error-checking when the player makes an illegal move, but it should
 *  contain the function the change the game state after it is determined
 *  that the move is legal.
 */

/* === BEGIN HEADERS === */
#ifndef _INCLUDE_GAMESTATE_H
#define _INCLUDE_GAMESTATE_H
#include "gameState.h"
#endif

#include <stdlib.h>
#include <math.h>
/* === END HEADERS === */

/**
 *  Returns a 2-dimensional array representing the board. True values
 *  indicate that there is a ship/target at the location, while false
 *  values indicate that there is not.
 */
bool **getBoard(GameState *state, Player *player);

int randInt(int min, int max) {
  return rand() % (max - min) + min;
}

/**
 *  Returns a 4-skewed random integer. Does that even make any sense?
 *  Basically it's skewed towards the center.
 */
int randSkewed(int range) {
  double sum = 0;
  for (int i = 0; i < 4; i++) {
    sum += rand() % (range - 4) + i;
  }
  return (int) round(sum / 4)
}
