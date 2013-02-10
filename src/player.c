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
Coord* genShipsArr (int len, int is_vertical, int head, int other);


Ship placeShip_human(GameState *state, int len) {
    printf("Place a ship of length %d\n", len);
    Ship *s = (Ship *) malloc(sizeof(Ship));
    s->size = len;
    s->sunk = 0;
    Coord *head = NULL;
    Coord *tail = NULL;
    do {
        printf("For head of ship\n");
        head = ask_for_coord();
        printf("For tail of ship\n");
        tail = ask_for_coord();
    } while ((head->x != tail->x || head->y != tail->y) &&
             ((abs(head->x - tail->x)) == len || (abs(head->y - tail->y)) == len)); //Check if the coords are not diagonal and correct size
    Coord *arrOfShips = NULL;
    if ((head->x - tail->x) != 0) {
        arrOfShips = genShipsArr(len, 0, (head->x > tail->x) ? tail->x : head->x, head->y);
    } else {
        arrOfShips = genShipsArr(len, 1, (head->y > tail->y) ? tail->y : head->y, head->x);
    }
    s->parts = arrOfShips;
    return *s;
}

Coord* ask_for_coord() {
    Coord *c = malloc(sizeof(Coord));
    c->x = -1;
    c->y = -1;
    while (c->x == -1) {
        printf("Gimme the X coord (<10) :\n");
        char *x;
        c->x = atoi(gets(x));
        if (c->x < 0 || c->x >= BOARD_WIDTH) {
            c->x = -1;
        }
    }
    while (c->y == -1) {
        printf("Gimme the Y coord (<10) :\n");
        char *y;
        c->y = atoi(gets(y));
        if (c->y < 0 || c->y >= BOARD_HEIGHT) {
            c->y = -1;
        }
    }
    return c;
}
    

Coord attack_human(GameState *state) {
    return *ask_for_coord();
}

void attack_result(int result) {
    if (result) {
        printf("You hit the opponent!!");
    } else {
        printf("You missed.");
    }
}

void opponent_attacked(int hit) {
    if (hit) {
        printf("You were hit!!");
    } else {
        printf("He missed.");
    }
}

/**
 * Constructor function
 */
Player *newHumanPlayer() {
  Player *player = malloc(sizeof(Player));
  player->placeShip = &placeShip_human;
  player->attack = &attack_human;
  player->attackResult = &attack_result;
  player->opponentAttacked = &opponent_attacked;
  return player;
}


/**
 * Utility function. Generate an array of Coords.
 */
 Coord* genShipsArr (int len, int is_vertical, int head, int other) {
     Coord *array = malloc(sizeof(Coord)*len);
     int index = 0;
     while (index < len) {
         Coord *c = malloc(sizeof(Coord));
         if (!is_vertical) {
             c->x = head + index;
             c->y = other;
         } else {
             c->x = other;
             c->y = head + index;
         }
         array[index] = *c;
         index ++;
     }
     return array;
 }
