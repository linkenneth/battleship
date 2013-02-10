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
        printf("For head of ship\n");
        Coord head = ask_for_coord();
        printf("For tail of ship\n");
        Coord tail = ask_for_coord();
    } while (head.x != tail.x || head.y != tail.y); //Check if the coords are not diagonal
    Coord *arrOfShips = genShipsArr(hxCoor, hyCoor, txCoor, tyCoor);
}

Coord* ask_for_coord() {
    Coord c = NULL;
    c.x = -1;
    c.y = -1;
    while (!c.x = -1) {
        printf("Gimme the X coord (<10) :\n");
        int c.x = atoi(gets(input));
        if (c.x < 0 || c.x >= BOARD_WIDTH) {
            c.x = -1;
        }
    }
    while (!c.y = -1) {
        printf("Gimme the Y coord (<10) :\n");
        int c.y = atoi(gets(input));
        if (c.y < 0 || c.y >= BOARD_HEIGTH) {
            c.y = -1;
        }
    }
    return &c;
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
