#ifndef _GAMESTATE_H
#define _GAMESTATE_H

/*
 *  A GameState represents the board, whose turn it is, and in general,
 *  everything possible about the state of the game. It should not include
 *  any sort of GAME logic. Functions that help make the job of modifying
 *  the GameState easier should be included in utils.c or game.c.
 */

/* === BEGIN HEADERS === */
#include <stdbool.h>
/* === END HEADERS === */

struct Player;

/**
 *  Abstraction of the coordinates of the board. The numbering starts on
 *  the bottom left corner of the board at (0,0) and behaves like a normal
 *  x-y graph.
 */
typedef struct {
  unsigned int x;
  unsigned int y;
} Coord;

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


/**
 *  The GameState object encapsulates all the data of a state of a
 *  game. Shit like Coords of yet-to-be-sunk targets, number of turns,
 *  etc. Each player has his own GameState that only shows him the ships
 *  that he has. Obviously, he shouldn't be able to see what ships the
 *  other guy has.
 */
struct GameState {
  struct Player *player;
  Ship *ships;
};

#endif
