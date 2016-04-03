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

    // Check whether the word is valid.
	// 1) In the word list
	// 2) On the board
	// 3) Not used before
	bool check_word(string word) const;

    int get_score() const;
    int get_misses() const;

    // Has the game ended?
    bool is_ended() const;

    // Print the game over message and score.
    void game_over() const;
private:
    int score;
    int misses;

    Board board;
    WordList words;
    //use standard list class
	list<string> usedwords;
};

#endif
