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
/* === END HEADERS === */

/**
 *  Abstraction of the coordinates of the board. The numbering starts on
 *  the bottom left corner of the board at (0,0) and behaves like a normal
 *  x-y graph.
 */
typedef struct {
  unsigned int x;
  unsigned int y;
} Coord;

/**
 *  The GameState object encapsulates all the data of a state of a
 *  game. Shit like Coords of yet-to-be-sunk targets, number of turns, etc.
 */
typedef struct {
  /**
   *  Every guess is a turn, regardless of whether it is successful (in
   *  which case it is the same player's turn again) or not (in which case
   *  it is the opponent's turn).
   */
  unsigned int turnsTaken;
  /**
   *  0 for Player 0, 1 for Player 1.
   */
  bool turn;
  /**
   *  The targets of Player 0.
   */
  Coord *targets_0;
  /**
   *  Length of targets_0.
   */
  unsigned int targetsLeft_0;
  /**
   *  The targets of Player 1.
   */
  Coord *targets_1;
  /**
   *  Length of targets_1.
   */
  unsigned int targetsLeft_1;
} GameState;
