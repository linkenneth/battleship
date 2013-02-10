/*
 *  This one's hard. A player defines certain methods that the game calls
 *  when seeking an action. This in turn should return an action of some
 *  kind to the game. You'll have to use function pointers for this. The
 *  idea is for the game to dereference these pointers and call the
 *  respective functions when it wants.
 */

/* === HEADERS === */
#include "player.h"
#include "gameState.h"
#include "game.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* === GLOBALS === */
/** Attack attempts made and their results. */
int g_Attacks[BOARD_WIDTH][BOARD_HEIGHT];
Coord lastAttack;
int nextY = 0;

/* === FUNCTIONS === */

Ship placeShip_comp(GameState *state, int shipLength) {
  int interval = (int) (NUM_SHIPS / BOARD_HEIGHT);
  int startY = randInt(nextY, nextY + interval);
  nextY += interval;
  int startX = randInt(0, BOARD_WIDTH - shipLength);

  Coord *c = (Coord *) malloc(shipLength * sizeof(Coord));
  for (int i = 0; i < shipLength; i++) {
    c[i].x = startX + i;
    c[i].y = startY + i;
  }
  Ship ship;
  ship.parts = c;
  ship.sunk = false;
  ship.size = shipLength;
  printf("Bob secretly placed a ship.\n");
  return ship;
}

Coord attack_comp(GameState *state) {
  Coord *c = (Coord *) malloc(sizeof(Coord));
  c->x = randSkewed(BOARD_WIDTH);
  c->y = randSkewed(BOARD_HEIGHT);
  lastAttack = *c;
  printf("Bob attacks (%d,%d)! OH SHIT\n", c->x, c->y);
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
