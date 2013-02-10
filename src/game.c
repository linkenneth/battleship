/*
 *  The game module should only contain only the logic for Battleship. Data
 *  about the state of the game (ie. how many ships are sunk, etc.) should
 *  be stored in GameState.c. The game module should also not directly use
 *  the terminal or anything else to ASK for commands/moves. This is not
 *  flexible. Instead, the game should delegate move-making and how to
 *  "ask" for moves by the player's function itself.
 */

/* === BEGIN HEADERS === */
#include "game.h"  // all other includes are here
#include <stdbool.h>
/* === END HEADERS === */

/**
 *  Denotes lengths of ships to be placed.
 */
static int NUM_SHIPS_TO_PLACE = 3;
/*
 *  Handles the logic for the 'placing' phase.
 */
void placePhase(GameState *gamestates) {
  Player *currplayer; Ship *shiplist;
  for (int i = 0; i < 2; i++) {
    *currplayer = *gamestates[i]->player;
    *shiplist = *gamestates[i]->ships;
    for (int k = 0; k < 6; k++) {
       *shiplist[k] = *currplayer->placeShip(gamestates[i]);
       *shiplist[k].sunk = false;
    }
  }
}

/*
 *  Handles the logic for the 'attacking' phase.
 *  Takes the array of GameStates
 *  
 */
void attackPhase(GameState *gameStates, int shipnum) {
  Coord attacked;
  int otherPlayer;
  int shipLen;
  Coord curShipCoord;
  int turn = 0;
  while (!gameOver()) {
    attacked = gameStates[turn].player.attack(gameStates[turn]);
    for (int i=0; i<shipnum; i++) { //for each ship in the attacked player
      otherPlayer = -(turn-1)
      shipLen = gameStates[otherPlayer].ships[i].size;
      for (int j=0; j<shipLen; j++) { //for each coordinate in the ship
        curShipCoord = gameStates[otherPlayer].ships[i][j]
        if (curShipCoord.Equals(attacked)) {
	  //if the attacked Coord is a ship, sink that Coord
	  curShipCoord.sunk = false;
	  //print whether the attack was a hit
	  gameStates[turn].player.attackResult();
	  
        } else {
	  turn = otherPlayer;
	}
      }
    }
  }

}

/**
 *  Returns a number depending on whether the game is over. Returns 1 if
 *  Player 1 wins, returns 0 if Player 0 wins, and returns -1 if the game
 *  is not yet over.
 */
bool gameOver(GameState *gameStates, int shipnum) {
  //check if at least one player has all ships sunk
  int shipLen;
  int shipSunk;
  for (int p=0; p<2; p++) {
    int defeated = 0; //number of sunk ships
    for (int i=0; i<shipnum; i++) {
      shipLen = gameStates[p].ships[i].size;
      shipSunk = 0;
      for (int j=0;j<shipLen;j++) {
	if (gameStates[p].ships[i][j].sunk) {
	  shipSunk++;
	};
      };
      if (shipSunk.Equals(shipLen)) {
	defeated++;
      };
    };
    if (defeated.Equals(shipnum)) {
      return true;
    };
  }; 
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
  int shipNum = 2;
  int shipLen;
  for (int i = 0; i < 2; i++) {
    shipLen = gameStates[otherPlayer].ships[i].size;
  }

  placePhase(gameStates, shipnum);
  while (!gameOver()){
    attackPhase(gameStates);
  };
}


 void usage() {
   char *help = "PLZ USE ./game [1~2] For number of AI. By default two humans.";
   printf("%s", help);
 }

/**
 *  The main function should handle reading the various options and passing
 *  these options to create a new game. The processing of the options
 *  should be left to the game itself.
 */
int main(int argc, char *argv[]) {
  inst numai;
  if (argc > 2) {
    usage();
    return 1;
  }
  if (argc == 1) {
    numai = 0;
  } else {
    numai = atoi(argv[1]);
  }
  start(numai);
  return 0;
}
