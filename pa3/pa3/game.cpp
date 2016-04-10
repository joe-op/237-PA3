#include "game.h"
#include "board.h"
#include "wordlist.h"
#include <list>
#include <string>

/* game(string wordfile) - Constructor for game
 * Description:
 *    Creates a word search game.
 *    The game consists of:
 *        - The maximum number of incorrect guesses
 *        - A board of shuffled letters
 *        - A wordlist containing all valid words
 *    A score is tallied with each correct find of length n
 *    counting for n squared points.
 *    The same word cannot be found twice.
 *    The game ends after the number of incorrect guesses is reached
 *    or when the user quits.
 * Input:
 *    A string indicating the location of a text file.
 *    The list of valid words is compiled from this file.
 * Output:
 *    A game object.
 */
game::game(string wordfile) {
	words = WordList(wordfile);
	board = Board();
	score = 0;
	misses = 0;
}
/*
 * take_turn() - play one turn of the game
 * Displays the board and requests input.
 * If user enters 'q', the game ends; otherwise,
 * the word is checked and score and 
 * misses are modified appropriately.
 * Input: none
 * Output: none
 */
void game::take_turn() {
	board.draw(cout);
	// Display score, misses, words found so far
	cout << "Current score: " << score << endl;
	cout << "Misses: " << misses << "/" << NUM_TRIES << endl;
	if (score > 0) {
		cout << "Found words:" << endl;
		list<string>::iterator curr;
		for (curr = usedwords.begin(); curr != usedwords.end(); ++curr) {
			cout << *curr << endl;
		}
	}

	cout << "Enter 'q' to quit." << endl;
	string input;
	cout << "Enter a word:" << endl;
	cin >> input;
	if (!word_in_list(input)) {
		cout << "That's not a word!" << endl;
		misses++;
	}
	else if (!word_new(input)) {
		cout << "You already used that word!" << endl;
		misses++;
	}
	else if (!word_on_board(input)) {
		cout << "That's not on the board!" << endl;
		misses++;
	} else {
		cout << "Correct!" << endl;
		score = score + input.length()^2;
	}
}
/*
 * get_score() - return the current score
 * Input: none
 * Output: int
 */
int game::get_score() const {
	return score;
}
/* 
 * get_misses() - return the number of misses
 * Input: none
 * Output: int
 */
int game::get_misses() const {
	return misses;
}
/*
 * is_ended() - Has the game ended?
 * Returns false if the number of misses is 
 * less than NUM_TRIES, true otherwise
 * Input: none
 * Output: bool
 */
bool game::is_ended() const {
	return (misses >= NUM_TRIES);
}
/*
 * game_over() - Prints the game over message and score
 * Input: none
 * Output: none
 */
void game::game_over() const {
	cout << "Thanks for playing!" << endl;
	cout << "Score: " << score << endl;
}
/*
 * word_in_list() - check if the word is a real word
 * Input: string
 * Output: bool
 */
bool game::word_in_list(string word) const {
	return words.contains(word);
}
/*
 * word_new() - check if the word has been used before
 * Input: string
 * Output: bool that is true if the word has not been used before
 */
bool game::word_new(string word) const {
	list<string>::const_iterator curr;
	for (curr = usedwords.begin(); curr != usedwords.end(); ++curr) {
		if (word == *curr) {
			return false;
		}
	}
	return true;
}
/*
 * word_on_board() - check if the word is on the board
 * Input: string
 * Output: bool
 */
bool game::word_on_board(string word) const {
	return board.contains(word);
}