#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <string>
#include <list>
#include "board.h"
#include "wordlist.h"
using namespace std;

const int NUM_TRIES = 5;

class game {
public:
    game(string wordfile);

    void take_turn();

    int get_score() const;
    int get_misses() const;

    // Has the game ended?
    bool is_ended() const;

    // Print the game over message and score.
    void game_over() const;
private:

	// Check whether the word is valid.
	// 1) In the word list
	bool word_in_list(string word) const;
	// 2) Not used before
	bool word_new(string word) const;
	// 3) On the board
	bool word_on_board(string word) const;

    int score;
    int misses;

    Board board;
    WordList words;
    //use standard list class
	list<string> usedwords;
};

#endif
