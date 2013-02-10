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
    do {
        while (!hxCoor = -1) {
            printf("Gimme the head's X coord (<10) :\n");
            int hxCoor = atoi(gets(input));
            if (hxCoor < 0 || hxCoor >= BOARD_WIDTH) {
                hxCoor = -1;
            }
        }
        while (!hyCoor = -1) {
            printf("Gimme the head's Y coord (<10) :\n");
            int hyCoor = atoi(gets(input));
            if (hyCoor < 0 || hyCoor >= BOARD_HEIGTH) {
                hyCoor = -1;
            }
        }
        while (!txCoor = -1) {
            printf("Gimme the tail's X coord (<10) :\n");
            int txCoor = atoi(gets(input));
            if (txCoor < 0 || txCoor >= BOARD_WIDTH) {
                txCoor = -1;
            }
        }
        while (!tyCoor = -1) {
            printf("Gimme the tail's Y coord (<10) :\n");
            int tyCoor = atoi(gets(input));
            if (tyCoor < 0 || tyCoor >= BOARD_HEIGTH) {
                tyCoor = -1;
            }
        }
    } while (hxCoor != txCoor || hyCoor != tyCoor); //Check if the coords are not diagonal
    Coord *arrOfShips = genShipsArr(hxCoor, hyCoor, txCoor, tyCoor);
}

Coord *attack_human(GameState *state) {
  
}

Player *newHumanPlayer() {
  Player player;
}


/**
 * Utility function. Generate an array of Coords.
 */
 Coord* arrOfShips (int hxCoor, int hyCoor, int txCoor, int tyCoor) {
     Coord *arrayOfCoords = NULL;
     int index = 0;
     if ((hxCoor - txCoor) != 0) {
        arrayOfCoords = Coord array[hxCoor-txCoor];
        for (int i = hxCoor; i < txCoor; i++) {
            Coord c;
            c.x = i;
            c.y = hyCoor;
            arrayOfCoords[index] = c;
            index++;
        }
     } else {
        arrayOfCoords = Coord array[hyCoor-tyCoor];
        for (int i = hyCoor; i < tyCoor; i++) {
            Coord c;
            c.x = hxCoor;
            c.y = i;
            arrayOfCoords[index] = c;
            index++;
        }
     }
     return &arrayOfCoords;
 }
