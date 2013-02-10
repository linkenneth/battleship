/*
 *  This should include any functions that manipulate the game state as
 *  well as other general utility functions. So, for example, it shouldn't
 *  do error-checking when the player makes an illegal move, but it should
 *  contain the function the change the game state after it is determined
 *  that the move is legal.
 */

/* === BEGIN HEADERS === */
#include "gameState.h"
#include <stdlib.h>
#include <math.h>
/* === END HEADERS === */

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
