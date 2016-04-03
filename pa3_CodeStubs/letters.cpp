#include <cstdlib>
#include <string>
#include <cctype>
#include "letters.h"
using namespace std;

const int NUM_LETTERS = 26;
const char FIRST_LETTER = 'A';

// Percentage frequencies of letters in English.  From Wikipedia.
const double Frequencies[NUM_LETTERS] = {
    // A-E
    8.167, 1.492, 2.782, 4.253, 12.702,
    // F-J
    2.228, 2.015, 6.094, 6.966, 0.153,
    // K-O
    0.772, 4.025, 2.406, 6.749, 7.507,
    // P-T
    1.929, 0.095, 5.987, 6.327, 9.056,
    // U-Y
    2.758, 0.978, 2.360, 0.150, 1.974,
    // Z
    0.074
};

char random_letter()
{
    // Find the sum of all the frequencies.  Might not be 100%
    // because of rounding.
    double sum = 0.0;
    for (int i = 0; i < NUM_LETTERS; i++)
        sum += Frequencies[i];

    // Get a double between 0 and sum.
    double rdbl = rand() * sum / (RAND_MAX);
    double cumulative = 0.0;
    
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        // Cumulative frequency of all the letters so far.
        cumulative += Frequencies[i];

        // If the random number is less than the cumulative
        // frequency, it fell into the current letter's range.
        if (rdbl <= cumulative)
            return FIRST_LETTER + i;
    }

    // Because of rounding we might not have reached the exact sum.
    return FIRST_LETTER + NUM_LETTERS - 1;
}

string uppercase(string input)
{
    for (size_t i = 0; i < input.length(); i++)
        if (islower(input[i]))
            input[i] = toupper(input[i]);
    return input;
}
