/*
 *  This one's hard. A player defines certain methods that the game calls
 *  when seeking an action. This in turn should return an action of some
 *  kind to the game. You'll have to use function pointers for this. The
 *  idea is for the game to dereference these pointers and call the
 *  respective functions when it wants.
 */
#include <GameState.h>

typedef struct {
  /**
   *  This function places a ship on the board. Must return an array of at
   *  least 2 Coords specifying the (x1,y1) and (x2,y2) coordinates that
   *  define where the ship is placed.
   */
  (Coord *) (*placeShip)(GameState);
  /**
   *  This function attacks the opponent's ships. Must return a single
   *  Coord specifying the (x,y) coordinates that the player chooses to
   *  attack.
   */
  (Coord) (*attack)(GameState);
} Player;

/**
 *  This returns a pointer to a new human player.
 */
Player *newHumanPlayer();
/**
 *  This returns a pointer to a new computer player.
 */
Player *newComputerPlayer();

/* Other details depends on implementation. */
