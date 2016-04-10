#include "board.h"
#include "letters.h"
#include "position.h"

/*
 * Default constructor for Board
 * Randomly shuffles letters
 * Selects letters based on letter frequency
 * Input: None
 * Output: A Board object
 */
Board::Board() {
	reshuffle();
}
/*
 * Remake the board
 * Input: none
 * Output: none
 */
void Board::reshuffle() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			letters[i][j] = random_letter();
		}
	}
}
/*
 * Get the letter at a given position
 * Input: A position object
 * Output: char
 */
char Board::letter_at(Position p) const {
	// Valid position?
	if (p.x() >= 0 && p.x() < BOARD_SIZE &&
		p.y() >= 0 && p.y() < BOARD_SIZE) {
		return letters[p.y()][p.x()];
	}
	else {
		throw runtime_error("Invalid position requested!");
	}
}
/*
 * Print the board to an output stream
 * Input: an ostream object
 * Output: none
 */
void Board::draw(ostream &out) const {
	out << draw_line_str() << endl;
	for (int i = 0; i < BOARD_SIZE; i++) {
		out << draw_row_str(i) << endl;
		out << draw_line_str() << endl;
	}
}
/*
 * Create a string for the lines
 * before and after each row
 * Input: none
 * Output: string
 */
string Board::draw_line_str() const{
	string str = "+";
	for (int i = 0; i < BOARD_SIZE; i++) {
		str += "---+";
	}
	return str;
}
/*
 * Create one row of the board
 * Input: int
 * Output: string
 */
string Board::draw_row_str(int y) const{
	// Valid y value?
	if (y >= 0 && y < BOARD_SIZE) {
		string str = "|";
		for (int i = 0; i < BOARD_SIZE; i++) {
			str += " ";
			str += letters[y][i];
			str += " |";
		}
		return str;
	}
	else {
		throw runtime_error("Invalid row requested!");
	}
}
/*
 * contains() - Check if the board contains a certain word
 * Input: string
 * Output: bool
 */
bool Board::contains(const string &word) const {
	// Iterate over every position and use
	// word_search function to check if the word is there
	// If word is found, immediately return true
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (word_search(word, 0, Position(i, j))) {
				return true;
			}
		}
	}
	// Default if word is not found
	return false;
}
/*
 * word_search() - Try to find a word at a certain position
 * Description:
 *    This function checks every adjacent Position for the next
 *     character in a word. It can be called recursively to search
 *     for every possible path to find the word.
 * Input:
 *    A string indicating the word to be found,
 *    an int indicating the current position in the word,
 *    a Position indicating the current position on the board
 * Output:
 *    A bool indicating whether or not the word can be found at
 *    that position.
 */
bool Board::word_search(const string &target, int tfrom, Position p) const
{
	// Base case
	// Return true if the search makes it past
	// the end of the word.
	if (tfrom >= target.length()) {
		return true;
	}
	// Return false if the current Position does not contain the current
	// letter.
	// Return true if it does and this is the last letter
	if (letter_at(p) != target.at(tfrom)) {
		return false;
	}
	else {
		if (tfrom + 1 == target.length()) {
			return true;
		}
	}
	// Check adjacent Positions for the next letter in the word
	const list<Position> neighbors = adjacent(p);
	for (Position neighbor : neighbors) {
		if (word_search(target, tfrom + 1, neighbor)) {
			return true;
		}
	}
	// Default return if word is not found
	return false;
}
/*
 * adjacent() - Return a list of every adjacent position
 * Description: 
 *     This function gives a list of every position
 *      that is adjacent to the given position.
 *      Positions that are outside of the scope of the
 *      board are not included.
 * Input: A Position object
 * Output: A list of Position objects
 */
list<Position> Board::adjacent(Position p) const {
	list<Position> positions;
	for (int i = -1; i <= 1; i = i + 2) {
		for (int j = -1; j <= 1; j = j + 2) {
			int new_x = p.x() + i;
			int new_y = p.y() + j;
			// Valid Position ?
			if (new_x >= 0 && new_x < BOARD_SIZE &&
				new_y >= 0 && new_y < BOARD_SIZE) {
				positions.push_front(Position(new_x, new_y));
			}
		}
	}
	return positions;
}