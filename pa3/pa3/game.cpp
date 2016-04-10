#include "game.h"

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
 * Input: none
 * Output: none
 */
void game::take_turn() {
	string input;
	cout << "Enter a word:\n";
	cin >> input;

}