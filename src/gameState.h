/*
 *  A GameState represents the board, whose turn it is, and in general,
 *  everything possible about the state of the game. It should not include
 *  any sort of GAME logic. Functions that help make the job of modifying
 *  the GameState easier should be included in utils.c or game.c.
 */

/* === BEGIN HEADERS === */
#ifndef _INCLUDE_STDBOOL_H
#define _INCLUDE_STDBOOL_H
#include <stdbool.h>
#endif
#include <ship.h>
/* === END HEADERS === */

/**
 *  Abstraction of the coordinates of the board. The numbering starts on
 *  the bottom left corner of the board at (0,0) and behaves like a normal
 *  x-y graph.
 */
typedef struct {
  unsigned int x;
  unsigned int y;
  bool hit;
} Coord;

/**
 *  The GameState object encapsulates all the data of a state of a
 *  game. Shit like Coords of yet-to-be-sunk targets, number of turns,
 *  etc. Each player has his own GameState that only shows him the ships
 *  that he has. Obviously, he shouldn't be able to see what ships the
 *  other guy has.
 */
typedef struct {

  Player* player;

  Ship ships[2];

} GameState;
