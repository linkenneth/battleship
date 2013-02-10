/*
 *  This one's hard. A player defines certain methods that the game calls
 *  when seeking an action. This in turn should return an action of some
 *  kind to the game. You'll have to use function pointers for this. The
 *  idea is for the game to dereference these pointers and call the
 *  respective functions when it wants.
 */

/* === BEGIN HEADERS === */
#ifndef _PLAYER_H
#define _PLAYER_H
#include "gameState.h"
/* === END HEADERS === */

typedef struct Player {
  /**
   *  This function places a ship on the board. This function takes a
   *  GameState that gives the player information of the data, and a second
   *  parameter SHIPLENGTH, which tells the player how long of a ship to
   *  place. Returns an array of SHIPLENGTH long that specifies all the
   *  Coords of where to place the ship. THIS FUNCTION SHOULD ERROR CHECK.
   */
  Ship (*placeShip)(GameState *, int);
  /**
   *  This function attacks the opponent's ships. Must return a single
   *  Coord specifying the (x,y) coordinates that the player chooses to
   *  attack.
   */
  Coord (*attack)(GameState *);
  /**
   *  The game calls this function after this player attempts an
   *  attack. This function allows the player to be notified of whether or
   *  not his attack was successful.
   */
  void (*attackResult)(int result);
  /**
   *  The game calls this function after the opponent attempts an
   *  attack. This function allows the player to be notified of whether or
   *  not the opponent's attack was successful.
   */
  void (*opponentAttacked)(bool hit);
  /**
   *  The name of the player.
   */
  char name[32];
} Player;

/**
 *  This returns a pointer to a new human player.
 */
Player *newHumanPlayer();
/**
 *  This returns a pointer to a new computer player.
 */
Player *newComputerPlayer();

/* Other details depends on implementation. */

#endif
