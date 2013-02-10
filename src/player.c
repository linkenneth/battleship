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

#ifndef _INCLUDE_GAME_H
#define _INCLUDE_GAME_H
#include "game.h"
#endif

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/* === END HEADERS === */


Coord *placeShip_human(GameState *state, int len) {
    int hxCoor = -1;
    int hyCoor = -1;
    int txCoor = -1;
    int tyCoor = -1;
    printf("Place a ship of length %d\n", len);
    while (!hxCoor = -1) {
        printf("Gimme the head's X coord (<10) :\n");
        int hxCoor = atoi(gets(input));
        if (hxCoor < 0 || hxCoor >= BOARD_WIDTH) {
            hxCoor = -1;
        }
    }
    while (!hyCoor = -1) {
        printf("Gimme the head's X coord (<10) :\n");
        int hyCoor = atoi(gets(input));
        if (hyCoor < 0 || hyCoor >= BOARD_WIDTH) {
            hyCoor = -1;
        }
    }
    while (!txCoor = -1) {
        printf("Gimme the head's X coord (<10) :\n");
        int txCoor = atoi(gets(input));
        if (txCoor < 0 || txCoor >= BOARD_WIDTH) {
            txCoor = -1;
        }
    }
    while (!tyCoor = -1) {
        printf("Gimme the head's X coord (<10) :\n");
        int tyCoor = atoi(gets(input));
        if (tyCoor < 0 || tyCoor >= BOARD_WIDTH) {
            tyCoor = -1;
        }
    }

        

int hyCoor = atoi(gets(input));

}

Coord *attack_human(GameState *state) {
  
}

Player *newHumanPlayer() {
  Player player;
}
