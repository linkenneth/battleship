/*
 *  The game module should only contain only the logic for Battleship. Data
 *  about the state of the game (ie. how many ships are sunk, etc.) should
 *  be stored in GameState.c. The game module should also not directly use
 *  the terminal or anything else to ASK for commands/moves. This is not
 *  flexible. Instead, the game should delegate move-making and how to
 *  "ask" for moves by the player's function itself.
 */

/* === BEGIN HEADERS === */
#ifndef _INCLUDE_GAME_H
#define _INCLUDE_GAME_H
#include "game.h"  // all other includes are here
#endif
#inlude <stdbool.h>
/* === END HEADERS === */

/**
 *  Denotes lengths of ships to be placed.
 */
char SHIPS_TO_PLACE[] = { 3, 4, 5 };
int NUM_SHIPS_TO_PLACE = 3;

/**
 *  Handles the logic for the 'placing' phase.
 */
void placePhase() {
  for (int i = 0; i < NUM_SHIPS_TO_PLACE; i++) {
    /* SHIPS_TO_PLACE[i] = 3; */
  }
}

/**
 *  Handles the logic for the 'attacking' phase.
 *  Takes the array of GameStates
 *  
 */
void attackPhase(GameState gameStates[]) {
  while (not gameOver()) {

  };
}

/**
 *  Returns a number depending on whether the game is over. Returns 1 if
 *  Player 1 wins, returns 0 if Player 0 wins, and returns -1 if the game
 *  is not yet over.
 */
bool gameOver(GameState gameStates[]) {
  //check if at least one player has all ships sunk
  for (i=0; i<
  return false; 
};

/**
 *  Starts the game. A game consists of two phases: a 'placing' phase and a
 *  'attacking' phase. In the 'placing' phase, players take turns to place
 *  their ships on the board. After the 'placing' phase is over, the
 *  'attacking' phase begins, in which players take turns guessing and
 *  attacking where they think the opponent's ship is. The first player to
 *  win is to one to sink all of their opponent's ships.
 */
void start() {
  GameState gameStates[2];
  for (int i = 0; i < 2; i++) {
    gameStates[i].turnsTaken = 0;
    gameStates[i].targetsLeft = 0;
  }

  placePhase();
  attackPhase();
}

/**
 *  The main function should handle reading the various options and passing
 *  these options to create a new game. The processing of the options
 *  should be left to the game itself.
 */
int main(int argc, char *argv[]) {
  // parse some shit, then
  start();
  return 0;
}
