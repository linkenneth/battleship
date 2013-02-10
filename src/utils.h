#ifndef _UTIL_H
#define _UTIL_H

/*
 *  This should include any functions that manipulate the game state as
 *  well as other general utility functions. So, for example, it shouldn't
 *  do error-checking when the player makes an illegal move, but it should
 *  contain the function the change the game state after it is determined
 *  that the move is legal.
 */

int randInt(int min, int max);

/**
 *  Returns a 4-skewed random integer. Does that even make any sense?
 *  Basically it's skewed towards the center.
 */
int randSkewed(int range);

#endif
