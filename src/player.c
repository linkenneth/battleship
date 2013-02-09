/*
 *  This one's hard. A player defines certain methods that the game calls
 *  when seeking an action. This in turn should return an action of some
 *  kind to the game. You'll have to use function pointers for this. The
 *  idea is for the game to dereference these pointers and call the
 *  respective functions when it wants.
 */

/* === BEGIN HEADERS === */
#ifndef _INCLUDE_PLAYER_H
#define _INCLUDE_PLAYER_H
#include "player.h"
#endif

#ifndef _INCLUDE_GAMESTATE_H
#define _INCLUDE_GAMESTATE_H
#include "gameState.h"
#endif

#ifndef _INCLUDE_STDBOOL_H
#define _INCLUDE_STDBOOL_H
#include <stdbool.h>
#endif

#ifndef _INCLUDE_STDIO_H
#define _INCLUDE_STDIO_H
#include <stdio.h>
#endif
/* === END HEADERS === */

Coord *placeShip_human(GameState *state) {
  char input[32];
  gets(input);
}

Coord *attack_human(GameState *state) {
  
}

Player *newHumanPlayer() {
  Player player;
}
