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
#include <stdio.h>
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
    currplayer = gamestates[i].player;
    shiplist = gamestates[i].ships;
    for (int k = 0; k < 6; k++) {
      shiplist[k] = currplayer->placeShip(&gamestates[i], 3);  // change 3
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
	if (gameStates[p].ships[i].parts[j].hit) {
	  shipSunk++;
	};
      };
      if (shipSunk == shipLen) {
	defeated++;
      };
    };
    if (defeated == shipnum) {
      return true;
    };
  }; 
  return false; 
};

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
  while (!gameOver(gameStates, shipnum)) {
    attacked = gameStates[turn].player->attack(&gameStates[turn]);
    for (int i=0; i<shipnum; i++) { //for each ship in the attacked player
      otherPlayer = -(turn-1);
      shipLen = gameStates[otherPlayer].ships[i].size;
      for (int j=0; j<shipLen; j++) { //for each coordinate in the ship
        curShipCoord = gameStates[otherPlayer].ships[i].parts[j];
        if (curShipCoord.x == attacked.x && curShipCoord.y == attacked.y) {
	  //if the attacked Coord is a ship, sink that Coord
	  curShipCoord.hit = true;
	  //print whether the attack was a hit
	  gameStates[turn].player->attackResult(curShipCoord.hit);
        } else {
	  turn = otherPlayer;
	}
      }
    }
  }

}

/**
 *  Starts the game. A game consists of two phases: a 'placing' phase and a
 *  'attacking' phase. In the 'placing' phase, players take turns to place
 *  their ships on the board. After the 'placing' phase is over, the
 *  'attacking' phase begins, in which players take turns guessing and
 *  attacking where they think the opponent's ship is. The first player to
 *  win is to one to sink all of their opponent's ships. NUM refers to the
 *  number of AI players. O for both human players. Will display a msg.
 */
void start(int num) {
  Player *p1, *p2;
  if (num != 0) {
    printf("%d AI player created. ", num);
    if (num == 1) {
      printf("Human player goes first!\n");
      p1 = newHumanPlayer();
      p2 = newComputerPlayer();
    } else {
      p1 = newComputerPlayer();
      p2 = newComputerPlayer();
    }
  } else {
    printf("Two human players selected! GLHF!\n");
  }
  GameState gameStates[2];
  gameStates[0].player = p1;
  gameStates[1].player = p2;
  placePhase(gameStates);
  attackPhase(gameStates, NUM_SHIPS);
}


void usage() {
  char *help = "PLZ USE ./game [1~2] (For number of AI. By default two humans.)\n";
  printf("%s", help);
}

void aimsg() {
  char *help = "Too many AI players! Only up to 2 allowed.\n";
  printf("%s", help);
}

/**
 *  The main function should handle reading the various options and passing
 *  these options to create a new game. The processing of the options
 *  should be left to the game itself.
 */
int main(int argc, char *argv[]) {
  int numai;
  if (argc > 2) {
    usage();
    return 1;
  }
  if (argc == 1) {
    numai = 0;
  } else {
    numai = atoi(argv[1]);
    if (numai > 2) {
      aimsg();
    }
  }
  start(numai);
  return 0;
}
