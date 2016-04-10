#include "wordlist.h"
#include <fstream>

/*
 * WordList() - Default constructor for WordList
 * Description:
 *    Takes a string giving the filepath of a text file
 *     with a list of words.
 *     Tho words are stored in a vector.
 * Input:
 *    A string containing the filepath of the list of words
 * Output:
 *    A WordList object
 */
WordList::WordList(string filename) {
	ifstream word_file(filename.c_str());
	if (word_file.fail()) {
		throw runtime_error("Invalid word list file.");
	}
	list_size = 0;
	string word;
	while (word_file >> word) {
		if (word.length() > 1) {
			words.push_back(word);
			list_size++;
		}
	}
}
/*
 * size() - number of words in the WordList
 * Input: none
 * Output: An integer
 */
int WordList::size() const {
	return list_size;
}
/*
 * contains() - Does the list contain this word?
 * Input: string
 * Output: bool
 */
bool WordList::contains(const string &word) const {

}
/*
 * binary_search() - Searches for a word in the WordList
 * Input: const string &target: the word searched for
 *        int begin: the first location to search
 *        int end: the last location to search
 */
bool WordList::binary_search(const string &target, int begin, int end) const {
	// base case
	if (end - begin <= 1) {
		return (target == words.at(begin) || target == words.at(end));
	}
	// check if word is in the middle
	int mid = (end + begin) / 2;
	const char *target_chars = target.c_str();
	const char *mid_chars = words.at(mid).c_str();
	int compare = strcmp(mid_chars, mid_chars);
	if (compare == 0) {
		return true;
	} // if word is not found, search again
	else if (compare < 0) {
		return binary_search(target, begin, mid);
	}
	else if (compare > 0) {
		return binary_search(target, mid, end);
	}
}
