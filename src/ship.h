/*
 *  This is the struct that represents ships, each ship contains an array
 *  of Coords that contain ship "parts"
 */

/* === BEGIN HEADERS ===*/
#ifndef _INCLUDE_GAMESTATE_H
#define _INCLUDE_GAMESTATE_H
#include "gameState.h"
#endif

#ifndef _INCLUDE_STDBOOL_H
#define _INCLUDE_STDBOOL_H
#include <stdbool.h>
#endif
/* === END HEADERS === */

typedef struct {

  /*
   *  A pointer to an array of ships that is defined by the player
   */
  Coord *parts;
  
  /*
   *  The int is 0 if the ship has been sunk. 1 otherwise.
   */
  bool sunk;

} Ship;

