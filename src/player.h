/*
 *  This one's hard. A player defines certain methods that the game calls
 *  when seeking an action. This in turn should return an action of some
 *  kind to the game. You'll have to use function pointers for this. The
 *  idea is for the game to dereference these pointers and call the
 *  respective functions when it wants.
 */

/* === BEGIN HEADERS === */
#ifndef _INCLUDE_GAMESTATE_H
#define _INCLUDE_GAMESTATE_H
#include "gameState.h"
#endif
/* === END HEADERS === */

typedef struct {
  /**
   *  This function places a ship on the board. Must return an array of at
   *  least 2 Coords specifying the (x1,y1) and (x2,y2) coordinates that
   *  define where the ship is placed.
   */
  Coord *(*placeShip)(GameState *);
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
  void (*attackResult)(bool success);
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
