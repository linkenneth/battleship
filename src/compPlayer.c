/*
 *  This one's hard. A player defines certain methods that the game calls
 *  when seeking an action. This in turn should return an action of some
 *  kind to the game. You'll have to use function pointers for this. The
 *  idea is for the game to dereference these pointers and call the
 *  respective functions when it wants.
 */

/* === HEADERS === */
#ifndef _INCLUDE_PLAYER_H
#define _INCLUDE_PLAYER_H
#include "player.h"
#endif

#ifndef _INCLUDE_GAMESTATE_H
#define _INCLUDE_GAMESTATE_H
#include "gameState.h"
#endif

#include "game.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* === GLOBALS === */
/** Attack attempts made and their results. */
int g_Attacks[BOARD_WIDTH][BOARD_HEIGHT];
Coord lastAttack;

/* === FUNCTIONS === */

Coord *placeShip_comp(GameState *state, int shipLength) {
  NUM_SHIPS_TO_PLACE
}

Coord attack_comp(GameState *state) {
  Coord c;
  c.x = 5; c.y = 5;  // actually do stuff here
  lastAttack = c;
  return lastAttack;
}

void attackResult_comp(int result) {
  g_Attacks[lastAttack.x][lastAttack.y] = result;
}

void opponentAttacked_comp(bool hit) {
  // don't care
}

Player *newComputerPlayer() {
  Player *player;
  player = (Player *) malloc(sizeof(Player));
  for (int i = 0; i < BOARD_WIDTH; i++) {
    for (int j = 0; j < BOARD_HEIGHT; j++) {
      printf("%d", g_Attacks[i][j]);
      /* g_Attacks[i][j] = 0;  // necessary? */
    }
  }

  player->placeShip = &placeShip_comp;
  player->attack = &attack_comp;
  player->attackResult = &attackResult_comp;
  player->opponentAttacked = &opponentAttacked_comp;
  strcpy("Bob", player->name);
  return player;
}
