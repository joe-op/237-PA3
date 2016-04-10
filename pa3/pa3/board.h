#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <string>
#include <list>
using namespace std;
#include "position.h"

const int BOARD_SIZE = 4;

class Board {
public:
  // Make a randomly-shuffled board.
  Board();

  // Re-randomize all the letters.
  void reshuffle();

  // Return the letter at the given position.
  char letter_at(Position p) const;

  void draw(ostream &out) const;

  // Does the board contain this sequence of letters?
  bool contains(const string &word) const;

private:
  // Recursive helper for the contains method.  Look for the part of
  // "target" starting at character tfrom at position p.  The
  // rest of the word must occur at an adjacent position to p.
  bool word_search(const string &target, int tfrom, Position p) const;

  // Return a list of all the positions adjacent to p, horizontally,
  // vertically, and diagonally.  Should NOT include positions that
  // are outside the board (x < 0, x > 3, y < 0, or y > 3).
  list<Position> adjacent(Position p) const;

  char letters[BOARD_SIZE][BOARD_SIZE];

  // Helper function for draw
  // Returns a string for the lines before, in between,
  // and after the letters
  string draw_line_str() const;
  // Helper function for draw
  // Returns a string corresponding to
  // one row of letters
  string draw_row_str(int y) const;
};

#endif

