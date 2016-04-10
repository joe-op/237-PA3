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
	if (input == "q") {
		misses = NUM_TRIES;
	}
	else {
		for (int i = 0; input[i] != 0; i++) {
			if (input[i] <= 122 && input[i] >= 97)
				input[i] -= 32;
		}
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
		}
		else {
			cout << "Correct!" << endl;
			score = score + input.length() ^ 2;
		}
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
	pause_237();
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
/* pause_237() - Wait for the user to press ENTER.
*
* Description:
* Optionally read and discard the remainder of the user's last
* line of input. Then, prompt the user to press ENTER, then
* read and discard another line of input.
*
* Inputs:
* bool have_newline:
* True if the user has already entered a newline that the
* program has not yet read. If true, this function first
* discards remaining input up to and including that newline.
*
* Reads two lines from standard input if have_newline is true,
* one line if it is false. Lines are assumed to be less than
* two hundred characters long.
*
* Outputs:
* No return value.
*
* Prints a prompt to standard output.
*
* Notes:
* This function is intended to be used at the end of a program,
* just before returning from main(). Reading another line of
* input prevents the console window from closing immediately.
*
* In general, have_newline should be true if the last user input
* from cin used the extraction operator (>>), and false if there
* has been no user input or if the last input used getline().
*/
void pause_237(bool have_newline)
{
	if (have_newline) {
		// Ignore the newline after the user's previous input. 
		cin.ignore(200, '\n');
	}
	// Prompt for the user to press ENTER, then wait for a newline. 
	cout << endl << "Press ENTER to continue." << endl;
	cin.ignore(200, '\n');
}