#ifndef WORDLIST_H_INCLUDED
#define WORDLIST_H_INCLUDED

#include <string>
#include <vector>
using namespace std;

class WordList {
public:
  // Read and sort a list of words.
  WordList(string filename);

  // Number of words in the list.
  int size() const;

  // Does the list contain this word?
  bool contains(const string &word) const;

private:
  // Recursive helper for the contains method.
  bool binary_search(const string &target, int begin, int end) const;

  // The words themselves.
  vector<string> words;
};

#endif
