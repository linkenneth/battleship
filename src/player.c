/*
 *  This one's hard. A player defines certain methods that the game calls
 *  when seeking an action. This in turn should return an action of some
 *  kind to the game. You'll have to use function pointers for this. The
 *  idea is for the game to dereference these pointers and call the
 *  respective functions when it wants.
 */

/* === BEGIN HEADERS === */

#include "player.h"
#include "game.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* === END HEADERS === */
Coord* ask_for_coord();


Coord *placeShip_human(GameState *state, int len) {
    printf("Place a ship of length %d\n", len);
    Coord *head = NULL;
    Coord *tail = NULL;
    do {
        printf("For head of ship\n");
        head = ask_for_coord();
        printf("For tail of ship\n");
        tail = ask_for_coord();
    } while (head->x != tail->x || head->y != tail->y); //Check if the coords are not diagonal
    //Coord *arrOfShips = genShipsArr(head->x, head->y, tail->x, tail->y);
    return head;
}

Coord* ask_for_coord() {
    Coord *c = malloc(sizeof(Coord));
    c->x = -1;
    c->y = -1;
    while (c->x != -1) {
        printf("Gimme the X coord (<10) :\n");
        char *x;
        c->x = atoi(gets(x));
        if (c->x < 0 || c->x >= BOARD_WIDTH) {
            c->x = -1;
        }
    }
    while (c->y != -1) {
        printf("Gimme the Y coord (<10) :\n");
        char *y;
        c->y = atoi(gets(y));
        if (c->y < 0 || c->y >= BOARD_HEIGHT) {
            c->y = -1;
        }
    }
    return c;
}
    

Coord *attack_human(GameState *state) {
  
}

Player *newHumanPlayer() {
  Player player;
}


/**
 * Utility function. Generate an array of Coords.
 Coord* genShipsArr (int hxCoor, int hyCoor, int txCoor, int tyCoor) {
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
 */
